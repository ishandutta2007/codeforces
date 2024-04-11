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

const int bigp=95542721;
const int maxn=100005;

struct tree
{
    tree *lchild,*rchild;
    int delta,left,right;
    int xz[48];
} *root;

int m,n,flag,lc,rc,ans;
int a[maxn];

void update(tree *p)
{
    for (int i=0;i<=47;i++)
        p->xz[i]=((LL)p->lchild->xz[i]+p->rchild->xz[i])%bigp;
}

void downit(tree *p)
{
    int a[48];
    if (p->delta!=0)
    {
        if (p->lchild!=0)
        {
            p->lchild->delta+=p->delta;
            p->rchild->delta+=p->delta;
            for (int i=0;i<=47;i++) a[i]=p->lchild->xz[i];
            for (int i=0;i<=47;i++) p->lchild->xz[i]=a[(i+p->delta)%48];
            for (int i=0;i<=47;i++) a[i]=p->rchild->xz[i];
            for (int i=0;i<=47;i++) p->rchild->xz[i]=a[(i+p->delta)%48];
        }
        p->delta=0;
    }
}

void maketree(tree *&node,int left,int right)
{
    tree *p=new tree;
    p->lchild=0,p->rchild=0;
    p->left=left,p->right=right;
    p->delta=0;
    node=p;
    if (left==right)
    {
        p->xz[0]=a[left];
        for (int i=1;i<=47;i++)
            p->xz[i]=(LL)(p->xz[i-1])*(p->xz[i-1])%bigp*(p->xz[i-1])%bigp;
    }
    else
    {
        maketree(node->lchild,left,(left+right)/2);
        maketree(node->rchild,(left+right)/2+1,right);
        update(p);
    }
}

void dfs1(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>rc)||(r<lc)) return;
    downit(p);
    if ((l==lc)&&(r<=rc))
    {
        lc=r+1;
        ans=(ans+p->xz[0])%bigp;
    }
    else
    {
        dfs1(p->lchild);
        dfs1(p->rchild);
        update(p);
    }
}

void dfs2(tree *p)
{
    int l=p->left,r=p->right,tc;
    if ((l>rc)||(r<lc)) return;
    downit(p);
    if ((l==lc)&&(r<=rc))
    {
        lc=r+1;
        p->delta=1;
        tc=p->xz[0];
        for (int i=0;i<=46;i++) p->xz[i]=p->xz[i+1];
        p->xz[47]=tc;
        downit(p);
    }
    else
    {
        dfs2(p->lchild);
        dfs2(p->rchild);
        update(p);
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    maketree(root,1,n);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&flag,&lc,&rc);
        if (flag==1)
        {
            ans=0;
            dfs1(root);
            printf("%d\n",ans);
        }
        else
            dfs2(root);
    }

    return 0;
}