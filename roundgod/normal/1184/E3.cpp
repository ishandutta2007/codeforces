#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 100005
#define MAXE 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int u,v,cost,id;};
int pa[MAXLOGN][MAXN],maxi[MAXLOGN][MAXN];
int depth[MAXN];
int tot,eid[MAXN];
int fa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
edge es[MAXE],backup[MAXE];
int V,E;
int p[MAXN],r[MAXN];
bool use[MAXE],uu[MAXE];
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
struct segtree
{
    int mini[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void pushdown(int k)
    {
        if(lazy[k]==-1) return;
        for(int i=k*2;i<=k*2+1;i++)
        {
            lazy[i]=lazy[k];
            mini[i]=lazy[k];
        }
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=-1;
        mini[k]=INF;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            lazy[k]=v;
            mini[k]=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return INF;
        if(l>=x&&r<=y) return mini[k];
        pushdown(k);
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}tree;
struct ee{int to,cost,id;};
vector<ee> G[MAXN];
void dfs1(int v,int p,int d)
{
    dep[v]=d;fa[v]=p;sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to==p) continue;
        eid[to]=G[v][i].id;
        dfs1(to,v,d+1);
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
        int to=G[v][i].to;
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
}
void hld_init()
{
    tot=0;
    memset(wson,0,sizeof(wson));
    dfs1(1,1,1);
    dfs2(1,0,1);
    tree.build(1,1,V);
}
void hld_update(int u,int v,int w)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        tree.update(1,1,V,spos[top[u]],spos[u],w);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    tree.update(1,1,V,spos[v]+1,spos[u],w);
}
int hld_query(int u,int v)
{
    int res=INF;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=min(res,tree.query(1,1,V,spos[top[u]],spos[u]));
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    res=min(res,tree.query(1,1,V,spos[v],spos[u]));
    return res;
}
void init_dsu(int n)
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
void unite(int x,int y,int w,int id)
{
    int xx=x,yy=y;
    x=find(x);
    y=find(y);
    if(x==y) return;
    G[xx].push_back((ee){yy,w,id}); G[yy].push_back((ee){xx,w,id});
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
int kruskal()
{
    sort(es,es+E,cmp);
    init_dsu(V);
    int res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            use[e.id]=true;
            uu[i]=true;
            unite(e.u,e.v,e.cost,e.id);
            res+=e.cost;
        }
    }
    return res;
}
void dfs(int v,int p,int d,int cost)
{
    pa[0][v]=p;
    maxi[0][v]=cost;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i].to!=p) dfs(G[v][i].to,v,d+1,G[v][i].cost);
}
void init(int V)
{
    dfs(1,-1,0,-INF);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) 
            {
                pa[k+1][v]=-1;
                maxi[k+1][v]=maxi[k][v];
            }
            else 
            {
                pa[k+1][v]=pa[k][pa[k][v]];
                maxi[k+1][v]=max(maxi[k][v],maxi[k][pa[k][v]]);
            }
        }
    }
}
P get(int v,int x)
{
    int res=-INF;
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
        {
            res=max(res,maxi[k][v]);
            v=pa[k][v];
        }
    return P(v,res);
}
int get_ans(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    P p=get(v,depth[v]-depth[u]);
    v=p.F;
    int ans=p.S;
    if(u==v) return ans;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            ans=max(ans,maxi[k][u]);
            ans=max(ans,maxi[k][v]);
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    ans=max(ans,maxi[0][u]);
    ans=max(ans,maxi[0][v]);
    assert(ans!=-INF);
    return ans;
}
int ans[MAXE];
int main()
{
    scanf("%d%d",&V,&E);
    memset(use,false,sizeof(use));
    memset(uu,false,sizeof(uu));
    for(int i=0;i<E;i++)
    {
        int a,b,e;
        scanf("%d%d%d",&a,&b,&e);
        es[i]=backup[i]=(edge){a,b,e,i};
    }
    kruskal();
    init(V);
    for(int i=0;i<E;i++)
    {
        if(!use[i]) ans[i]=get_ans(backup[i].u,backup[i].v);
    }
    hld_init();
    for(int i=E-1;i>=0;i--)
    {
        if(!uu[i]) hld_update(es[i].u,es[i].v,es[i].cost);
    }
    for(int i=2;i<=V;i++) ans[eid[i]]=hld_query(i,i);
    for(int i=0;i<E;i++) printf("%d\n",ans[i]);
    return 0;
}