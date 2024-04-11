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

const int maxn=100005;

struct tree
{
    tree *lchild,*rchild;
    int left,right,max;
} *root;

int N,Q,o,ic,ie,qzl,qzr,qzmax;
PIII ls[maxn];
int biao[maxn],f[maxn],l[maxn],r[maxn],which[maxn],a[maxn],next[maxn],ans[maxn],hash[maxn],u[maxn],v[maxn],use[maxn],lls[maxn];

void mplus(int s,int flag)
{
    while (s<=N)
    {
        f[s]+=flag;
        s+=s&(-s);
    }
}

int getsum(int s)
{
    int e=0;
    while (s>0)
    {
        e+=f[s];
        s-=s&(-s);
    }
    return e;
}

void maketree(tree *&node,int left,int right)
{
    tree *p=new tree;
    p->lchild=p->rchild=0;
    p->left=left,p->right=right;
    p->max=-maxlongint;
    node=p;
    if (left==right) return;
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
}

void shuait(tree *p,int place,int num)
{
    int l=p->left,r=p->right;
    if ((l>place)||(r<place)) return;
    if (l==r) p->max=num; else
    {
        shuait(p->lchild,place,num);
        shuait(p->rchild,place,num);
        p->max=max(p->lchild->max,p->rchild->max);
    }
}

void dfs(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>qzr)||(r<qzl)) return;
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        qzmax=max(qzmax,p->max);
    }
    else
        if (p->lchild!=0)
        {
            dfs(p->lchild);
            dfs(p->rchild);
        }
}

int getmax(int l,int r)
{
    qzl=l,qzr=r,qzmax=-maxlongint;
    dfs(root);
    return qzmax;
}

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d",&a[i]);
    scanf("%d",&Q);
    for (int i=1;i<=Q;i++) scanf("%d %d",&l[i],&r[i]);
    for (int i=1;i<=Q;i++) ls[i]=m_p(m_p(l[i],r[i]),i);
    sort(ls+1,ls+Q+1);
    for (int i=1;i<=Q;i++)
        l[i]=ls[i].w1.w1,
        r[i]=ls[i].w1.w2,
        which[i]=ls[i].w2;

    memset(biao,0,sizeof(biao));
    memset(hash,0,sizeof(hash));
    memset(f,0,sizeof(f));
    for (int i=1;i<=N;i++)
    {
        if (hash[a[i]]!=0)
            next[hash[a[i]]]=i;
        else
        {
            mplus(i,1);
            biao[i]=1;
        }
        hash[a[i]]=i;
    }

    memset(ans,0,sizeof(ans));
    l[0]=1;
    for (int i=1;i<=Q;i++)
    {
        for (int j=l[i-1];j<l[i];j++)
        {
            mplus(j,-1);
            if (next[j]!=0) mplus(next[j],1);
        }
        ans[which[i]]=getsum(r[i]);
    }

    for (int i=0;i<=N;i++) if (next[i]==0) next[i]=N+1;
    memset(use,0,sizeof(use));
    for (int i=1;i<=N;i++)
    {
        if (use[i]==1) continue;
        o=1,u[o]=i;
        ic=i;
        while (next[ic]<=N)
        {
            v[o]=next[ic]-ic;
            ic=next[ic];
            ++o,u[o]=ic;
            use[ic]=1;
        }
        ic=1;
        while (ic<=o)
        {
            ie=ic;
            while ((ie+1<o)&&(v[ic]==v[ie+1])) ++ie;
            ++ie;
            for (int j=ic;j<=ie-1;j++)
                lls[u[j]]=next[u[ie]]-1;
            ic=ie;
        }
    }

    //for (int i=1;i<=N;i++) cout<<lls[i]<<" ";cout<<endl;
    //memset(ans,0,sizeof(ans));

    maketree(root,1,N);
    for (int i=1;i<=N;i++)
        if (biao[i]==1) shuait(root,i,lls[i]);
    for (int i=1;i<=Q;i++)
    {
        for (int j=l[i-1];j<l[i];j++)
        {
            shuait(root,j,-1);
            if (next[j]!=N+1) shuait(root,next[j],lls[next[j]]);
        }
        if (getmax(l[i],r[i])<r[i]) ans[which[i]]++;
    }

    for (int i=1;i<=Q;i++) printf("%d\n",ans[i]);

    return 0;
}