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

const int bigp=1000000009;
const int maxn=100005;

struct tree
{
    tree *lchild,*rchild;
    int left,right,f,g,f1,g1,cd,flag;
} *root;

int n,k,a1,b1,c1,d1,lc,rc,qzl,qzr,m;
int x[maxn],y[maxn];
PII ls[maxn];

void maketree(tree *&node,int left,int right)
{
    if (left>right) return;

    int mc,mk;
    tree *p=new tree;

    p->lchild=0,p->rchild=0;
    p->left=left,p->right=right;
    p->flag=0;
    p->f=0,p->g=0;
    p->cd=left;
    // f means that the current node isn't used and g is the opposite situation
    p->f1=0,p->g1=0;
    node=p;
    if (left==right) return;
    mc=-1,mk=0;
    for (int i=left;i<=right;i++)
        if (y[i]>mc) mc=y[i],mk=i;
    p->cd=mk;
    maketree(node->lchild,left,mk-1);
    maketree(node->rchild,mk+1,right);
    if (p->lchild==0)
    {
        p->f=max(p->rchild->f,p->rchild->g);
        p->g=1+p->rchild->f;
    }
    else
        if (p->rchild==0)
        {
            p->f=max(p->lchild->f,p->lchild->g);
            p->g=1+p->lchild->f;
        }
        else
        {
            p->f=max(p->lchild->f,p->lchild->g)+max(p->rchild->f,p->rchild->g);
            p->g=1+max(p->lchild->f+max(p->rchild->f,p->rchild->g),
                       p->rchild->f+max(p->lchild->f,p->lchild->g));
        }
}

void doit(tree *p,int l,int r,int i)
{
    //cout<<p->left<<" "<<p->right<<" "<<l<<" "<<r<<endl;
    if ((l>p->right)||(r<p->left)) return;
    if (l==r)
    {
        p->flag=i;
        p->f1=0;
        p->g1=0;
        return;
    }
    if ((p->left==l)&&(p->right==r))
    {
        p->flag=i;
        p->f1=p->f;
        p->g1=p->g;
    }
    else
    {
        if (l<=p->cd-1) doit(p->lchild,l,min(r,p->cd-1),i);
        if (r>=p->cd+1) doit(p->rchild,max(l,p->cd+1),r,i);
        if ((p->cd>=qzl)&&(p->cd<=qzr))
        {
            if ((p->lchild==0)||(p->lchild->flag!=i))
            {
                p->f1=max(p->rchild->f1,p->rchild->g1);
                p->g1=1+p->rchild->f1;
            }
            else
                if ((p->rchild==0)||(p->rchild->flag!=i))
                {
                    p->f1=max(p->lchild->f1,p->lchild->g1);
                    p->g1=1+p->lchild->f1;
                }
                else
                {
                    p->f1=max(p->lchild->f1,p->lchild->g1)+max(p->rchild->f1,p->rchild->g1);
                    p->g1=1+max(p->lchild->f1+max(p->rchild->f1,p->rchild->g1),
                                p->rchild->f1+max(p->lchild->f1,p->lchild->g1));
                }
        }
        else
        {
            if ((p->lchild!=0)&&(p->lchild->flag==i))
                p->f1=p->lchild->f1,p->g1=p->lchild->g1;
            else
                p->f1=p->rchild->f1,p->g1=p->rchild->g1;
        }
        p->flag=i;
    }
}

int main()
{
    //freopen("D.in","r",stdin);
    scanf("%d %d",&n,&k);
    for (int i=1;i<=k;i++) scanf("%d %d",&x[i],&y[i]);
    scanf("%d %d %d %d",&a1,&b1,&c1,&d1);
    for (int i=k+1;i<=n;i++)
    {
        x[i]=((LL)x[i-1]*a1+b1)%bigp;
        y[i]=((LL)y[i-1]*c1+d1)%bigp;
    }
    for (int i=1;i<=n;i++) ls[i]=m_p(x[i],y[i]);
    sort(ls+1,ls+n+1);
    for (int i=1;i<=n;i++)
    {
        x[i]=ls[i].w1;
        y[i]=ls[i].w2;
    }
    maketree(root,1,n);

    int left,right,mid;

    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&lc,&rc);
        left=1;right=n;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (x[mid]>=lc) right=mid-1; else left=mid+1;
        }
        qzl=left;
        left=1;right=n;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (x[mid]<=rc) left=mid+1; else right=mid-1;
        }
        qzr=right;
        if (qzl>qzr) printf("0\n"); else
        {
            doit(root,qzl,qzr,i);
            printf("%d\n",max(root->f1,root->g1));
        }
    }

    return 0;
}