#include<stdio.h> //invoking standard input.
#include<stdlib.h> //invoking standard library functions.
struct node{
	int data;
	struct node *next,*prev;
}* start=NULL;

struct node * create(int data){ //using structure to create a node.
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node)); //malloc
	p->data=data;
	p->next=NULL;
	p->prev=NULL;
	return p; // return statement
}

void insert(struct node * n){ //using a insert method to insert a node in the linked list
	struct node *ptr=start;
	if(start==NULL)
		start=n;
	else{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=n;
		n->prev=ptr;
	}
}

void del(int data){ //method for deleting a node
	struct node * ptr=start,*tmp;
	int f=0;
	if(start==NULL)
		printf("UNDERFLOW\n"); 
	else{
		while(ptr!=NULL){
			if(start->data==data){
				start=NULL;
				f=1;
				printf("%d is deleted\n",data);
				break; //break statement
			}
			else if(ptr->data == data){
				tmp=ptr->next;
				ptr->prev->next=tmp;
				tmp->prev=tmp->prev->prev;
				printf("%d is deleted\n",data);
				f=1;
				break;
			}
			ptr=ptr->next;
		}
		if(f==0) // if statement
			printf("NOT FOUND\n"); //output statement
	}
}

void display(){ //method for displaying the output.
	struct node * ptr=start;
	if(start==NULL)
		printf("UNDERFLOW\n");
	else{
		while(ptr!=NULL){//while loop
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

int main(void){ // Main method
	int n,data;
	do{
		printf("Menu:\n1. Insert\n2. Display\n3. Delete\n4. Exit\nenter: "); //
			scanf("%d",&n);
		switch(n){//switch case
			case 1:
				printf("enter the data: ");
					scanf("%d",&data);
				insert(create(data));
				break;
			case 2:
				display();
				break;
			case 3:
				printf("enter the value: ");
					scanf("%d",&data);
				del(data);
				break;
			case 4:
				printf("Thank You!!\n");
			
			default: // default case.
				printf("Wrong Choice!! Try again\n");
		}
	}while(n!=3);//while loop
	return 1; //return statement
} //end of programs
