#include<bits/stdc++.h>
#define MAXN 300005
#define MAXM 500005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,p[MAXN],r[MAXN];
vector<P> G[MAXN];
bool added[MAXM];
int res[MAXN];
int tot;
int pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void add_edge(int u,int v,int w)
{
    G[u].push_back(P(v,w)); G[v].push_back(P(u,w));
}
vector<pair<int,P> > edges; 
vector<int> roots;
bool vis[MAXN];
struct segtree
{
    int maxi[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void add(int k,int v)
    {
        maxi[k]+=v;
        lazy[k]+=v;
    }
    void build(int k,int l,int r)
    {
        maxi[k]=lazy[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
void dfs(int v,int p)
{
    vis[v]=true;
    for(auto e:G[v])
    {
        int to=e.F,cost=e.S;
        if(to==p) continue;
        dfs(to,v);
    }
}
void dfs1(int v,int p,int d,int val)
{
    dep[v]=d;pa[v]=p;sz[v]=1;res[v]=val;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].F,cost=G[v][i].S;
        if(to==p) continue;
        dfs1(to,v,d+1,val^cost);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        sz[v]+=sz[to];
    }
}
void dfs2(int v,int p,int num)
{
    top[v]=num;
    spos[v]=++tot;
    tpos[tot]=v;
    if(wson[v]) dfs2(wson[v],v,num);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].F,cost=G[v][i].S;
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
}
void init_HLD()
{
    tot=0;
    memset(wson,0,sizeof(wson));//important when multiple test cases!!!
    dfs1(0,-1,1,0);
    dfs2(0,-1,0);
    seg.build(1,1,n+1);
}
int query_max(int u,int v)
{
    int res=-INF;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=max(res,seg.query(1,1,n+1,spos[top[u]],spos[u]));
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    if(u!=v) res=max(res,seg.query(1,1,n+1,spos[v]+1,spos[u]));
    assert(res!=-INF);
    return res;
}
void add_one(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        seg.update(1,1,n+1,spos[top[u]],spos[u],1);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    if(u!=v) seg.update(1,1,n+1,spos[v]+1,spos[u],1);
}
int main()
{
    scanf("%d%d",&n,&q);
    init(n);
    memset(added,false,sizeof(added));
    for(int i=0;i<q;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges.push_back(make_pair(w,P(u,v)));
        if(!same(u,v))
        {
            added[i]=true;
            add_edge(u,v,w);
            unite(u,v);
        }
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,0);
            roots.push_back(i);
        }
    }
    for(auto v:roots) add_edge(0,v,0);
    init_HLD();
    for(int i=0;i<q;i++)
    {
        if(added[i]) {puts("YES"); continue;}
        int u=edges[i].S.F,v=edges[i].S.S,w=edges[i].F;
        if((res[u]^res[v]^w)!=1) {puts("NO"); continue;}
        int tmp=query_max(u,v);
        if(tmp==1) {puts("NO"); continue;}
        add_one(u,v);
        puts("YES");
    }
    return 0;
}