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

const int maxn=300005;

struct tree
{
    tree *lchild,*rchild;
    int left,right,min,mini1,mini2,delta;
} *root;

int n,cs,qzl,qzr,qzn,c1,c2,a[maxn],hash[maxn];
LL ans;

void update(tree *p)
{
    int t=min(p->lchild->min,p->rchild->min);
    p->min=t;
    p->mini1=0,p->mini2=0;
    if (p->lchild->min==t) p->mini1+=p->lchild->mini1,p->mini2+=p->lchild->mini2; else
        if (p->lchild->min==t+1) p->mini2+=p->lchild->mini1;
    if (p->rchild->min==t) p->mini1+=p->rchild->mini1,p->mini2+=p->rchild->mini2; else
        if (p->rchild->min==t+1) p->mini2+=p->rchild->mini1;
}

void downit(tree *p)
{
    if (p->delta!=0)
    {
        if (p->lchild!=0)
        {
            p->lchild->min+=p->delta;
            p->rchild->min+=p->delta;
            p->lchild->delta+=p->delta;
            p->rchild->delta+=p->delta;
        }
        p->delta=0;
    }
}

void doit(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>qzr)||(r<qzl)) return;
    downit(p);
    if ((l==qzl)&&(r<=qzr))
    {
        p->min+=qzn;
        p->delta=qzn;
        downit(p);
        qzl=r+1;
    }
    else
    {
        doit(p->lchild);
        doit(p->rchild);
        update(p);
    }
}

void mplus(int l,int r,int flag)
{
    qzl=l,qzr=r,qzn=flag;
    //cout<<l<<"    "<<r<<"    "<<flag<<endl;
    doit(root);
}

void maketree(tree *&node,int l,int r)
{
    tree *p=new tree;
    p->left=l,p->right=r;
    p->lchild=0,p->rchild=0;
    p->min=1;
    p->mini1=0,p->mini2=0;
    p->delta=0;
    node=p;
    if (l==r)
    {
        p->mini1=1;
        return;
    }
    maketree(node->lchild,l,(l+r)/2);
    maketree(node->rchild,(l+r)/2+1,r);
    update(node);
}

int main()
{
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&cs),a[cs]=i,hash[i]=cs;
    ans=0;
    maketree(root,1,n);
    for (int i=n;i>=1;i--)
    {
        if (a[i]!=n) c1=hash[a[i]+1]; else c1=-1;
        if (a[i]!=1) c2=hash[a[i]-1]; else c2=-1;
        if (c1<i) c1=-1;
        if (c2<i) c2=-1;
        if (c1>c2) swap(c1,c2);
        //cout<<c1<<" "<<c2<<endl;
        if (c1!=-1)
        {
            mplus(i+1,c1-1,1);
            mplus(c2,n,-1);
        }
        else
            if ((c1==-1)&&(c2!=-1))
            {
                mplus(i+1,c2-1,1);
            }
            else
                mplus(i+1,n,1);
        if (root->min==1) ans+=(LL)root->mini1+root->mini2; else
        if (root->min==2) ans+=(LL)root->mini1;
        //cout<<root->min<<" "<<root->mini1<<" "<<root->mini2<<endl;
        ans-=i;
    }
    printf("%I64d\n",ans);

    return 0;
}