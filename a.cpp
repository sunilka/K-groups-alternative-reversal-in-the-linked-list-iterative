#include<bits/stdc++.h>
using namespace std;

/*

1
9
4
1 2 3 4 5 6 7 8 9


*/

struct node
{
    int data;
    struct node *next;
};

struct newnode
{
    int data;
    struct newnode *next;
};

struct newnode *hhead = NULL;
struct newnode *llast = NULL;


struct node *head = NULL;
struct node *last = NULL;


void print()
{
    cout<<"\n printing the linked list here "<<endl;
    struct node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void pprint()
{
    cout<<"\n printing the new linked list here "<<endl;
    struct newnode *temp = hhead;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insert_into_ll(int temp)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = temp;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        last = newnode;
    }
    else{
        last->next = newnode;
        last = newnode;
    }
}

void cal(int k)
{
    struct node *newhead = NULL;
    struct node *temp = head;
    struct node *prev_node_before_reverse = NULL;
    struct node *next_node_after_reverse = NULL;
    struct node *last_ele_after_reverse = NULL;
    struct node *head_after_reverse = NULL;

    while(temp!=NULL){
        last_ele_after_reverse = temp;
        struct node *prev = NULL;
        struct node *next = NULL;
        struct node *cur = temp;

        int p = k;
        while(cur!=NULL && p){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            p--;
        }

        head_after_reverse = prev;
        next_node_after_reverse = cur;

        if(newhead == NULL){
            head = head_after_reverse;
            newhead = head;
        }

        last_ele_after_reverse->next = next_node_after_reverse;
        if(prev_node_before_reverse!=NULL){
            prev_node_before_reverse->next = head_after_reverse;
        }
        temp = cur;
        for(int i=0;temp!=NULL && i<k-1;i++){
            temp = temp->next;
        }

        prev_node_before_reverse = temp;
        if(temp!=NULL)
            temp = temp->next;
    }
    print();
}



void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        insert_into_ll(temp);
    }

    print();
    cal(k);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
