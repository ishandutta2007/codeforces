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
#include <ctime>

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

struct tree
{
    tree *lchild,*rchild;
    int left,right,max,maxplace;
    LL sum;
} *root;

int N,M,qzl,qzr,flag,xc,yc,zc,a[500005];
LL qzans;

void update(tree *p)
{
    p->sum=p->lchild->sum+p->rchild->sum;
    if (p->lchild->max>p->rchild->max)
    {
        p->max=p->lchild->max;
        p->maxplace=p->lchild->maxplace;
    }
    else
    {
        p->max=p->rchild->max;
        p->maxplace=p->rchild->maxplace;
    }
}

void maketree(tree *&node,int left,int right)
{
    tree *p=new tree;
    p->lchild=p->rchild=0;
    p->left=left,p->right=right;
    p->max=p->sum=0;
    node=p;
    if (left==right)
    {
        p->max=p->sum=a[left];
        p->maxplace=left;
        return;
    }
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
    update(node);
}

void getsum(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>qzr)||(r<qzl)) return;
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        qzans+=p->sum;
    }
    else
    {
        getsum(p->lchild);
        getsum(p->rchild);
    }
}

PII getmax(tree *p,int left,int right)
{
    int l=p->left,r=p->right;
    if ((l>right)||(r<left)) return m_p(-1,0);
    if ((l==left)&&(r==right)) return m_p(p->max,p->maxplace);
    return max(getmax(p->lchild,left,min(right,p->lchild->right)),
               getmax(p->rchild,max(left,p->rchild->left),right));
}

void change(tree *p,int place,int num)
{
    int l=p->left,r=p->right;
    if ((l>place)||(r<place)) return;
    if (l==r)
    {
        p->sum=p->max=num;
    }
    else
    {
        change(p->lchild,place,num);
        change(p->rchild,place,num);
        update(p);
    }
}
int main()
{
    scanf("%d %d",&N,&M);
    for (int i=1;i<=N;i++) scanf("%d",&a[i]);
    maketree(root,1,N);
    for (int i=1;i<=M;i++)
    {
        scanf("%d",&flag);
        if (flag==1)
        {
            scanf("%d %d",&qzl,&qzr);
            qzans=0;
            getsum(root);
            printf("%I64d\n",qzans);
        }
        if (flag==2)
        {
            scanf("%d %d %d",&xc,&yc,&zc);
            while (true)
            {
                PII cc=getmax(root,xc,yc);
                //cout<<cc.w1<<" "<<cc.w2<<endl;
                if (cc.w1>=zc)
                    change(root,cc.w2,cc.w1%zc);
                else break;
            }
        }
        if (flag==3)
        {
            scanf("%d %d",&xc,&yc);
            change(root,xc,yc);
        }
    }

    return 0;
}