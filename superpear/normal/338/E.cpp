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

const int maxn=150005;
int N,M,H,qzl,qzr,qznum,cs,ans;
int a[maxn],b[maxn],gq[maxn],biao[maxn],last[maxn];
PII cc[maxn],ls[maxn];

struct tree
{
    int delta,min,left,right;
    tree *lchild,*rchild;
} *root;

void maketree(tree *&node,int left,int right)
{
    tree *p=new tree;
    p->lchild=p->rchild=0;
    p->left=left,p->right=right;
    p->min=maxlongint/2;
    p->delta=0;
    node=p;
    if (left==right) return;
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
}

void downit(tree *p)
{
    if (p->delta!=0)
    {
        if (p->lchild!=0)
        {
            p->lchild->delta+=p->delta;
            p->lchild->min+=p->delta;
            p->rchild->delta+=p->delta;
            p->rchild->min+=p->delta;
        }
        p->delta=0;
    }
}

void update(tree *p)
{
    p->min=min(p->lchild->min,p->rchild->min);
}

void mplus(int s,int flag)
{
    while (s<=N)
    {
        gq[s]+=flag;
        s+=s&(-s);
    }
}

int getsum(int s)
{
    int ans=0;
    while (s>0)
    {
        ans+=gq[s];
        s-=s&(-s);
    }
    return ans;
}

void insert(tree *p,int place,int num)
{
    int l=p->left,r=p->right;
    if ((l>place)||(r<place)) return;
    downit(p);
    if (l==r)
    {
        p->min=num;
        mplus(place,1);
    }
    else
    {
        insert(p->lchild,place,num);
        insert(p->rchild,place,num);
        update(p);
    }
}

void erase(tree *p,int place)
{
    int l=p->left,r=p->right;
    if ((l>place)||(r<place)) return;
    downit(p);
    if (l==r)
    {
        p->min=maxlongint/2;
        mplus(place,-1);
    }
    else
    {
        erase(p->lchild,place);
        erase(p->rchild,place);
        update(p);
    }
}

void dfs(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>qzr)||(r<qzl)) return;
    downit(p);
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        p->min+=qznum;
        p->delta+=qznum;
        downit(p);
    }
    else
        if (p->lchild!=0)
        {
            dfs(p->lchild);
            dfs(p->rchild);
            update(p);
        }
}

void plusc(int l,int r,int num)
{
    qzl=l,qzr=r,qznum=num;
    dfs(root);
}

int main()
{
    scanf("%d %d %d",&N,&M,&H);
    for (int i=1;i<=M;i++)
    {
        scanf("%d",&b[i]);
        b[i]=H-b[i];
    }
    sort(b+1,b+M+1);
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        a[i]=l_b(b+1,b+M+1,a[i]+1)-b-1;
    }
    //for (int i=1;i<=N;i++) printf("%d ",a[i]);printf("\n");

    maketree(root,0,N);

    for (int i=1;i<=N;i++) cc[i]=m_p(a[i],i);
    sort(cc+1,cc+N+1);
    for (int i=1;i<=N;i++) biao[cc[i].w2]=i;
    for (int i=2;i<=N;i++)
        if (cc[i].w1!=cc[i-1].w1)
            last[cc[i-1].w1]=i-1;
    last[cc[N].w1]=N;

    memset(gq,0,sizeof(gq));
    for (int i=1;i<=M;i++) ls[i]=m_p(a[i],i);
    sort(ls+1,ls+M+1);
    for (int i=1;i<=M;i++)
        insert(root,biao[ls[i].w2],ls[i].w1-i);

    ans=0;
    for (int i=1;i<=N-M+1;i++)
    {
        if (root->min>=0) ++ans;
        //cout<<root->min<<endl;
        if (i==N-M+1) break;
        cs=a[i];
        plusc(biao[i]+1,N,1);
        erase(root,biao[i]);
        cs=a[i+M];
        plusc(biao[i+M]+1,N,-1);
        insert(root,biao[i+M],cs-getsum(last[cs])-1);
    }
    printf("%d\n",ans);

    return 0;
}