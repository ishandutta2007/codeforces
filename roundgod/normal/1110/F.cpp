#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge
{
    int to,cost;
};
struct qq
{
    int l,r,id;
};
vector<edge> G[MAXN];
vector<qq> query[MAXN];
int n,q,tot,st[MAXN],ed[MAXN];
bool isleaf[MAXN];
ll dis[MAXN],res[MAXN];
void add_edge(int u,int v,int cost)
{
    G[u].push_back((edge){v,cost});
    G[v].push_back((edge){u,cost});
}
void dfs1(int v,int p,ll d)
{
    st[v]=++tot;
    if(v!=1&&(int)G[v].size()==1) isleaf[v]=true;
    dis[v]=d;
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        dfs1(e.to,v,d+e.cost);
    }
    ed[v]=tot;
}
struct segtree
{
    ll lazy[4*MAXN],ans[4*MAXN];
    void pushup(int k)
    {
        ans[k]=min(ans[k*2],ans[k*2+1]);
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++)
        {
            ans[i]+=lazy[k];
            lazy[i]+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            if(isleaf[l]) ans[k]=dis[l]; else ans[k]=INF;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }
    void add(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            ans[k]+=v;
            lazy[k]+=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        add(k*2,l,mid,x,y,v);add(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return ans[k];
        pushdown(k);
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
void dfs2(int v,int p)
{
    for(auto qq:query[v]) res[qq.id]=seg.query(1,1,n,qq.l,qq.r);
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        seg.add(1,1,n,1,n,e.cost);
        seg.add(1,1,n,st[e.to],ed[e.to],-2*e.cost);
        dfs2(e.to,v);
        seg.add(1,1,n,1,n,-e.cost);
        seg.add(1,1,n,st[e.to],ed[e.to],2*e.cost);
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int p,w;
        scanf("%d%d",&p,&w);
        add_edge(i,p,w);
    }
    tot=0;dfs1(1,0,0);
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int v,l,r;
        scanf("%d%d%d",&v,&l,&r);
        query[v].push_back((qq){l,r,i});
    }
    dfs2(1,0);
    for(int i=0;i<q;i++) printf("%lld\n",res[i]);
    return 0;
}