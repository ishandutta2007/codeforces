/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-17 21:08:56
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,q,n,k,a[MAXN];
int pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],st[MAXN],ed[MAXN],tpos[MAXN];
vector<int> G[MAXN];
struct segtree
{
    int sum[4*MAXN],suf[4*MAXN];
    bool lazy[4*MAXN];
    void Lazy(int k,int l,int r)
    {
        lazy[k*2]=lazy[k*2+1]=true;
        suf[k*2]=suf[k*2+1]=-1;
        int mid=(l+r)/2;
        sum[k*2]=-(mid-l+1);sum[k*2+1]=-(r-mid);
        lazy[k]=false;
    }
    void merge(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
        suf[k]=max(suf[k*2+1],suf[k*2]+sum[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        lazy[k]=false;
        if(l==r) {sum[k]=-1; suf[k]=-1; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        merge(k);
    }
    void update1(int k,int l,int r,int p,int val)
    {
        if(l==r) {sum[k]+=val; suf[k]=sum[k]; return;}
        if(lazy[k]) Lazy(k,l,r);
        int mid=(l+r)/2;
        if(p<=mid) update1(k*2,l,mid,p,val); else update1(k*2+1,mid+1,r,p,val);
        merge(k);
    }
    void update2(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y)
        {
            lazy[k]=true;
            sum[k]=-(r-l+1);suf[k]=-1;
            return;
        }
        if(lazy[k]) Lazy(k,l,r);
        int mid=(l+r)/2;
        update2(k*2,l,mid,x,y);update2(k*2+1,mid+1,r,x,y);
        merge(k);
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(l>=x&&r<=y) return P(sum[k],suf[k]);
        if(lazy[k]) Lazy(k,l,r);
        int mid=(l+r)/2;
        if(mid+1>y) return query(k*2,l,mid,x,y);
        else if(mid<x) return query(k*2+1,mid+1,r,x,y);
        else
        {
            P p=query(k*2,l,mid,x,y); P q=query(k*2+1,mid+1,r,x,y);
            int ss=p.F+q.F;
            int ff=max(q.S,q.F+p.S);
            return P(ss,ff);
        }
    }
}tree;
void dfs1(int v,int p,int d)
{
    dep[v]=d;pa[v]=p;sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs1(to,v,d+1);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        sz[v]+=sz[to];
    }
}
void dfs2(int v,int p,int num)
{
    top[v]=num;
    st[v]=++tot;
    tpos[tot]=v;
    if(wson[v]) dfs2(wson[v],v,num);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
    ed[v]=tot;
}
void init()
{
    tot=0;dfs1(1,1,1);
    dfs2(1,0,1);
    tree.build(1,1,n);
}
void update1(int v,int val)
{
    tree.update1(1,1,n,st[v],val);
}
void update2(int v)
{
    tree.update2(1,1,n,st[v],ed[v]);
}
int query(int v)
{
    int ans=-INF,sum=0;
    while(top[v]!=1)
    {
        P p=tree.query(1,1,n,st[top[v]],st[v]);
        ans=max(ans,sum+p.S);
        sum+=p.F;
        v=pa[top[v]];
    }
    P p=tree.query(1,1,n,st[top[v]],st[v]);
    ans=max(ans,sum+p.S);sum+=p.F;
    return ans;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int v;
        scanf("%d",&v);
        G[i].push_back(v);G[v].push_back(i);
    }
    init();
    int type,v;
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&type,&v);
        if(type==1) update1(v,1);
        else if(type==2) 
        {
            update2(v);
            int res=query(v);
            if(res>=0) update1(v,-res-1);
        }
        else 
        {
            if(query(v)>=0) puts("black"); else puts("white");
        }
    }
    return 0;
}