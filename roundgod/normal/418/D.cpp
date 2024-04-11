#include<bits/stdc++.h>
#define MAXN 100005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,tot;
vector<int> G[MAXN];
int st[MAXN],ed[MAXN],pos[MAXN],t;
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
int pa[MAXLOGN][MAXN];
int depth[MAXN];
void dfs(int v,int p,int d)
{
    pa[0][v]=p; st[v]=++t; pos[t]=v;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    ed[v]=t;
}
void init(int V)
{
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
struct segtree
{
    int maxi[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void add(int k,int v)
    {
        lazy[k]+=v; maxi[k]+=v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            maxi[k]=depth[pos[l]];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int ans[MAXN];
vector<pair<int,P> > qry[MAXN];
void dfs2(int v,int p)
{
    if(v!=1)
    {
        seg.update(1,1,n,1,n,1);
        seg.update(1,1,n,st[v],ed[v],-2);
    }
    for(auto q:qry[v])
        ans[q.F]=max(ans[q.F],seg.query(1,1,n,q.S.F,q.S.S));
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
    }
    seg.update(1,1,n,1,n,-1);
    seg.update(1,1,n,st[v],ed[v],2);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    init(n);
    seg.build(1,1,n);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(depth[u]<depth[v]) swap(u,v);
        int w=get(u,(dis(u,v)-1)/2);
        qry[u].push_back(make_pair(i,P(st[w],ed[w])));
        qry[v].push_back(make_pair(i,P(1,st[w]-1)));
        qry[v].push_back(make_pair(i,P(ed[w]+1,n)));
    }
    dfs2(1,0);
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    return 0;
}