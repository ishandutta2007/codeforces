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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int maxn=100005;

struct tree
{
    tree *lchild,*rchild;
    int left,right,sum;
} *root[maxn*20];

vector<PII> oper[maxn];
int m,n,xc,yc,o,first[maxn],last[maxn],ans[maxn],final[maxn];
vector<int> a[maxn];

void dfs(int s,int fa)
{
    int c;
    ++o;
    first[s]=o;
    for (int i=0;i<a[s].size();i++)
    {
        c=a[s][i];
        if (c!=fa) dfs(c,s);
    }
    last[s]=o;
}

void maketree(tree *&node,int left,int right)
{
    tree *p;
    p=new tree;
    p->left=left;p->right=right;
    p->lchild=0;p->rchild=0;
    p->sum=0;
    node=p;
    if (left==right) return;
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
}

int check(tree *p,int place)
{
    while (p!=0)
    {
        if (p->right-p->left+1==p->sum) return 1;
        if (p->lchild==0) break;
        if (p->rchild==0) break;
        if (p->lchild->right>=place) p=p->lchild; else p=p->rchild;
    }
    return 0;
}

void makenew(tree *&node,tree *p,int left,int right)
{
    int l=p->left,r=p->right;
    //cout<<l<<" "<<r<<" "<<left<<" "<<right<<endl;
    if ((left>r)||(right<l)) return;
    tree *w;
    w=new tree;
    w->lchild=0;w->rchild=0;
    w->left=l;w->right=r;
    w->sum=p->sum;
    node=w;
    if (w->sum==(r-l+1)) return;
    if ((left==l)&&(right==r))
    {
        w->sum=r-l+1;
        w->lchild=p->lchild;
        w->rchild=p->rchild;
    }
    else
    {
        if (left<=(l+r)/2) makenew(node->lchild,p->lchild,left,min(right,(l+r)/2));
        if (right>(l+r)/2) makenew(node->rchild,p->rchild,max((l+r)/2+1,left),right);
        if (w->lchild==0) w->lchild=p->lchild;
        if (w->rchild==0) w->rchild=p->rchild;
        w->sum=w->lchild->sum+w->rchild->sum;
    }
}

void doit(int s,int fa)
{
    int c,o=final[fa],xc,yc;
    for (int i=0;i<oper[s].size();i++)
    {
        xc=oper[s][i].first;
        yc=oper[s][i].second;
        makenew(root[o+1],root[o],xc,yc);
        ++o;
    }
    final[s]=o;
    ans[s]=root[o]->sum;
    if (check(root[o],first[s])!=0) --ans[s];
    for (int i=0;i<a[s].size();i++)
    {
        c=a[s][i];
        if (c!=fa) doit(c,s);
    }
}

int main()
{
    //freopen("E.in","r",stdin);
    scanf("%d %d",&n,&m);
    for (int i=1;i<n;i++)
    {
        scanf("%d %d",&xc,&yc);
        a[xc].p_b(yc);
        a[yc].p_b(xc);
    }
    memset(first,0,sizeof(first));
    memset(last,0,sizeof(last));
    o=0;
    dfs(1,0);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        oper[xc].p_b(m_p(first[yc],last[yc]));
        oper[yc].p_b(m_p(first[xc],last[xc]));
        oper[xc].p_b(m_p(first[xc],last[xc]));
        oper[yc].p_b(m_p(first[yc],last[yc]));
    }
    maketree(root[1],1,n);
    memset(ans,0,sizeof(ans));
    memset(final,0,sizeof(final));
    final[0]=1;
    doit(1,0);
    for (int i=1;i<n;i++) printf("%d ",ans[i]);printf("%d\n",ans[n]);

    return 0;
}