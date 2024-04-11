#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=100005;

struct tree
{
    tree *lchild,*rchild,*father;
    LL num,ans,lsum,rsum,lmost,rmost,cnt;
} *root,*null,*ct1,*ct2,*ct3,*ct4,*where[maxn];

LL data[maxn];
pair<LL,LL> e[maxn];
int n,m,flag,xc,yc;

void update(tree *p)
{
    p->cnt=p->lchild->cnt+p->rchild->cnt+1;
    if (p->lchild==null) p->lmost=p->num; else p->lmost=p->lchild->lmost;
    if (p->rchild==null) p->rmost=p->num; else p->rmost=p->rchild->rmost;
    p->lsum=p->lchild->lsum+(p->num-p->lmost)+p->rchild->lsum+
            (p->rchild->lmost-p->lmost)*(p->rchild->cnt);
    p->rsum=p->rchild->rsum+(p->rmost-p->num)+p->lchild->rsum+
            (p->rmost-p->lchild->rmost)*(p->lchild->cnt);
    p->ans=p->lchild->ans+p->rchild->ans+
            p->lchild->rsum+(p->num-p->lchild->rmost)*p->lchild->cnt+
            p->rchild->lsum+(p->rchild->lmost-p->num)*p->rchild->cnt+
            p->lchild->rsum*(p->rchild->cnt)+
            p->rchild->lsum*(p->lchild->cnt)+
            (p->rchild->lmost-p->lchild->rmost)*(p->lchild->cnt)*(p->rchild->cnt);
}

void maketree(tree *father,tree *&node,int l,int r)
{
    if (l>r) return;
    tree *p=new tree;
    int m=(l+r)/2;
    p->lchild=null,p->rchild=null;
    p->father=father;
    p->num=e[m].w1;
    node=p;
    where[e[m].w2]=node;
    maketree(node,node->lchild,l,(l+r)/2-1);
    maketree(node,node->rchild,(l+r)/2+1,r);
    update(node);
}

void spinl(tree *a)
{
    tree *b=a->lchild;
    a->lchild=b->rchild;
    b->rchild->father=a;
    b->rchild=a;
    b->father=a->father;
    if (a->father!=null)
    {
        if (a->father->lchild==a) a->father->lchild=b;
                            else  a->father->rchild=b;
    }
    a->father=b;
    update(a);
    update(b);
}

void spinr(tree *a)
{
    tree *b=a->rchild;
    a->rchild=b->lchild;
    b->lchild->father=a;
    b->lchild=a;
    b->father=a->father;
    if (a->father!=null)
    {
        if (a->father->lchild==a) a->father->lchild=b;
                            else  a->father->rchild=b;
    }
    a->father=b;
    update(a);
    update(b);
}

void splay(tree *p,tree *destfa)
{
    while (p->father!=destfa)
    {
        if (p->father->lchild==p) spinl(p->father); else spinr(p->father);
    }
    if (destfa==null) root=p;
}

tree* lb1(int s)
{
    tree *p,*ans;
    p=root,ans=where[n];
    while (p!=null)
    {
        if ((p->num>=s)&&(p->num<=ans->num)) ans=p;
        if (p->num>=s)
            p=p->lchild;
        else
            p=p->rchild;
    }
    return ans;
}

tree* lb2(int s)
{
    tree *p,*ans;
    p=root,ans=where[n-1];
    while (p!=null)
    {
        if ((p->num<=s)&&(p->num>=ans->num)) ans=p;
        if (p->num<=s)
            p=p->rchild;
        else
            p=p->lchild;
    }
    return ans;
}

void insert(tree *p,tree *&node,tree *fa)
{
    if (node==null) node=p,node->father=fa; else
    {
        if (p->num<node->num) insert(p,node->lchild,node); else insert(p,node->rchild,node);
    }
}

void print(tree *p)
{
    printf("%d",p->num);
    if ((p->lchild!=null)||(p->rchild!=null))
    {
        printf("(");
        if (p->lchild!=null) print(p->lchild);
        if (p->rchild!=null)
        {
            printf(",");
            print(p->rchild);
        }
        printf(")");
    }
}

void printc(tree *p)
{
    if (p->lchild!=null) printc(p->lchild);
    printf("%d ",p->num);
    if (p->rchild!=null) printc(p->rchild);
}

void upall(tree *p)
{
    if (p==null) return;
    upall(p->lchild);
    upall(p->rchild);
    update(p);
}

int main()
{
    null=new tree;
    null->lchild=null,null->rchild=null,null->father=null;
    null->num=0,null->ans=0;
    null->lsum=0,null->rsum=0;
    null->lmost=0,null->rmost=0;
    null->cnt=0;

    //freopen("E.in","r",stdin);

    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d",&data[i]);
    ++n;
    data[n]=-maxlongint;
    ++n;
    data[n]=maxlongint;
    for (int i=1;i<=n;i++) e[i]=m_p(data[i],i);
    sort(e+1,e+n+1);
    maketree(null,root,1,n);

    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&flag,&xc,&yc);
        if (flag==2)
        {
            ct1=lb2(xc-1);
            ct2=lb1(yc+1);
            splay(ct2,null);
            splay(ct1,ct2);
            //cout<<ct1->num<<" "<<ct2->num<<endl;
            //upall(root);
            //print(root);cout<<endl;
            //cout<<where[6]->rsum<<endl;
            printf("%I64d\n",root->lchild->rchild->ans);
        }
        else
        {
            ct1=where[xc];
            splay(ct1,null);
            ct2=ct1->lchild;
            ct3=ct1->rchild;
            ct2->father=null;
            ct3->father=null;
            ct4=ct3;
            while (ct4->lchild!=null) ct4=ct4->lchild;
            //cout<<ct1->num<<" "<<ct3->num<<" f"<<endl;
            splay(ct4,null);
            ct4->lchild=ct2;
            ct2->father=ct4;
            root=ct4;

            ct1->num+=yc;
            ct1->ans=0;
            ct1->cnt=1;
            ct1->lmost=ct1->num;
            ct1->rmost=ct1->num;
            ct1->father=null;
            ct1->lchild=null;
            ct1->rchild=null;
            ct1->lsum=0;
            ct1->rsum=0;

            insert(ct1,root,null);
            splay(ct1,null);
        }
        //printc(root);cout<<endl;
    }

    return 0;
}