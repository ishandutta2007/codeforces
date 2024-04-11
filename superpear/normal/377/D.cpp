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

const int maxN=300000;

struct tree
{
    tree *lchild,*rchild;
    int left,right,max,delta;
} *root;

vector<PII> smx[maxN+10];
int l[100005],r[100005],v[100005];
int N,ans,qzl,qzr,qznum,L,R;

void downit(tree *p)
{
    if (p->delta!=0)
    {
        if (p->lchild!=0)
        {
            p->lchild->delta+=p->delta;
            p->lchild->max+=p->delta;
            p->rchild->delta+=p->delta;
            p->rchild->max+=p->delta;
        }
        p->delta=0;
    }
}

void update(tree *p)
{
    p->max=max(p->lchild->max,p->rchild->max);
}

void maketree(tree *&node,int left,int right)
{
    tree *p=new tree;
    p->lchild=p->rchild=0;
    p->left=left,p->right=right;
    p->max=0,p->delta=0;
    node=p;
    if (left==right) return;
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
}

void doit(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>qzr)||(r<qzl)) return;
    downit(p);
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        p->max+=qznum;
        p->delta+=qznum;
        downit(p);
    }
    else
        if (p->lchild!=0)
        {
            doit(p->lchild);
            doit(p->rchild);
            update(p);
        }
}

void mplus(int l,int r,int num)
{
    qzl=l,qzr=r,qznum=num;
    doit(root);
}

void downall(tree *p)
{
    downit(p);
    if (p->left==p->right)
    {
        if (p->max==ans) R=p->left;
    }
    else
    {
        downall(p->lchild);
        downall(p->rchild);
    }

}

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d %d %d",&l[i],&v[i],&r[i]);
    for (int i=1;i<=N;i++)
    {
        smx[l[i]].p_b(m_p(v[i],r[i]));
        smx[v[i]+1].p_b(m_p(-v[i],-r[i]));
    }

    maketree(root,1,maxN+1);

    ans=0;
    for (int i=1;i<=maxN+1;i++)
    {
        for (int j=0;j<smx[i].size();j++)
            if (smx[i][j].w1>0)
                mplus(smx[i][j].w1,smx[i][j].w2,1);
            else
                mplus(-smx[i][j].w1,-smx[i][j].w2,-1);
        ans=max(ans,root->max);
    }
    for (int i=1;i<=maxN+1;i++)
    {
        for (int j=0;j<smx[i].size();j++)
            if (smx[i][j].w1>0)
                mplus(smx[i][j].w1,smx[i][j].w2,1);
            else
                mplus(-smx[i][j].w1,-smx[i][j].w2,-1);
        if (root->max==ans)
        {
            L=i;
            R=0;
            downall(root);
            break;
        }
    }
    printf("%d\n",ans);
    for (int i=1;i<=N;i++)
        if ((l[i]<=L)&&(L<=v[i])&&(v[i]<=R)&&(R<=r[i])) printf("%d ",i);
    printf("\n");

    return 0;
}