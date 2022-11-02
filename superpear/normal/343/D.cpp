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

struct tree1
{
    tree1 *lchild,*rchild;
    int left,right,max;
} *root1;

struct tree2
{
    tree2 *lchild,*rchild;
    int left,right,num,flag;
} *root2;

const int maxn=500005;

int N,Q,o,qzl,qzr,qznum,qzans,xc,yc,flag,full,empty;
int ll[maxn],rr[maxn];
vector<int> f[maxn];

void dfs(int s,int fa)
{
    ++o;
    ll[s]=o;
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=fa)
            dfs(f[s][i],s);
    rr[s]=o;
}

void maketree1(tree1 *&node,int left,int right)
{
    tree1 *p=new tree1;
    p->lchild=0,p->rchild=0;
    p->left=left,p->right=right,p->max=0;
    node=p;
    if (left==right) return;
    maketree1(node->lchild,left,(left+right)/2);
    maketree1(node->rchild,(left+right)/2+1,right);
}

void maketree2(tree2 *&node,int left,int right)
{
    tree2 *p=new tree2;
    p->lchild=0,p->rchild=0;
    p->left=left,p->right=right,p->num=0,p->flag=0;
    node=p;
    if (left==right) return;
    maketree2(node->lchild,left,(left+right)/2);
    maketree2(node->rchild,(left+right)/2+1,right);
}

void downit(tree2 *p)
{
    if (p->flag!=0)
    {
        p->flag=0;
        if (p->lchild!=0)
        {
            p->lchild->num=p->num;
            p->rchild->num=p->num;
            p->lchild->flag=1;
            p->rchild->flag=1;
        }
    }
}

void doit(tree2 *p)
{
    int l=p->left,r=p->right;
    if ((l>qzr)||(r<qzl)) return;
    downit(p);
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        p->num=qznum;
        p->flag=1;
        downit(p);
    }
    else
        if (p->lchild!=0)
        {
            doit(p->lchild);
            doit(p->rchild);
        }
}

void shua(int l,int r,int num)
{
    qzl=l,qzr=r,qznum=num;
    doit(root2);
}

void update(tree1 *p,int place,int num)
{
    int l=p->left,r=p->right;
    if ((l>place)||(r<place)) return;
    if (l==r) p->max=num; else
    {
        update(p->lchild,place,num);
        update(p->rchild,place,num);
        p->max=max(p->lchild->max,p->rchild->max);
    }
}

int get2(tree2 *p,int place)
{
    if (p->left==p->right)
        return p->num;
    else
    {
        downit(p);
        if (place<=p->lchild->right)
            return get2(p->lchild,place);
        else
            return get2(p->rchild,place);
    }
}

void doe(tree1 *p)
{
    int l=p->left,r=p->right;
    if ((l>qzr)||(r<qzl)) return;
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        qzans=max(qzans,p->max);
    }
    else
        if (p->lchild!=0)
        {
            doe(p->lchild);
            doe(p->rchild);
        }
}

int getlast(int l,int r)
{
    qzl=l,qzr=r;
    qzans=0;
    doe(root1);
    return qzans;
}

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N-1;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }
    memset(ll,0,sizeof(ll));
    memset(rr,0,sizeof(rr));
    o=0;
    dfs(1,0);

    //for (int i=1;i<=N;i++) cout<<ll[i]<<" "<<rr[i]<<endl;

    maketree1(root1,1,N);
    maketree2(root2,1,N);

    scanf("%d",&Q);
    for (int i=1;i<=Q;i++)
    {
        scanf("%d %d",&flag,&xc);
        if (flag==1)
            shua(ll[xc],rr[xc],i);
        if (flag==2)
            update(root1,ll[xc],i);
        if (flag==3)
        {
            full=get2(root2,ll[xc]);
            empty=getlast(ll[xc],rr[xc]);
            //cout<<full<<"  "<<empty<<endl;
            if (full>empty) printf("1\n"); else printf("0\n");
        }
    }

    return 0;
}