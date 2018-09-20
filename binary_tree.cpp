/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
#include <iostream>
#include "libs.h"
#include "binary_tree.h"

#define LOG true

using namespace std;

struct Node {
    
    int val;
    struct Node  *left,*right;
    
};
struct Node * get_node(int val)
{
    struct Node * node=new(struct Node);
    (*node).val=val;
    node->left=NULL;
    node->right=NULL;
    return node;
    
    
}
void insert(int val,struct Node * root)
{
    struct Node * ptr=root;
    struct Node * pre=root;
    
    do{
        
        if(ptr->val >  val)
        { 
           if(LOG)  lg("GO Left");
            pre=ptr;
            ptr=ptr->left;
        }
        else if(ptr->val < val)
        {   
           if(LOG)  lg("GO RIght");
            pre=ptr;
            ptr=ptr->right;
        }
        else
        {
            pre=NULL;
            break;
        }
        
    }while(ptr);
    
    if(pre){
        
       if(LOG) cout<<"Inserted "<<val<<" after "<<(pre->val)<<endl;
        if(pre->val > val)
        {
            pre->left=get_node(val);
        }
        else{
             pre->right=get_node(val);
        }
       if(pre==root)
           root=pre;
        
    }
    else
    {
        cout<<"Duplicate Entry";
       
    }
    
}
void in_order(Node * ptr)
{
    if(ptr==NULL)
        return;
        in_order(ptr->left);
        cout<<ptr->val<<" ";
        in_order(ptr->right);
       
    
}

void pre_order(Node * ptr)
{ 
    if(ptr==NULL)
        return;
        cout<<ptr->val<<" ";
        pre_order(ptr->left);
        pre_order(ptr->right);
           
}



void post_order(Node * ptr)
{ 
    
    if(ptr==NULL)
        return;
        post_order(ptr->left);
        post_order(ptr->right);
        cout<<ptr->val<<" ";
    
    
}

void binary_tree(){
    
  
    cout<<"Program :: Binary Tree "<<endl;
     
    int vals[]={8,9,6,1,2,3,7};
    struct Node * root=get_node(5);
    
    for(int i=0;i<sizeof(vals)/4;i++)
    {
        insert(vals[i],root);
    } 
    
    cout<<endl<<"InOrdder"<<endl;
    in_order(root);
    
    cout<<endl<<"PreOrdder"<<endl;
    pre_order(root);
    
    cout<<endl<<"PostOrdder"<<endl;
    post_order(root);
    
}