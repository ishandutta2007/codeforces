#include<bits/stdc++.h>
#define MAXN 600005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
vector<pair<int,P> > edges;
vector<int> G[MAXN];
int weight[MAXN],dfn[MAXN],pos[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
int p[MAXN],r[MAXN];
void init_dsu(int n)
{
    for(int i=1;i<=n;i++) p[i]=i;
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
int pa[MAXLOGN][MAXN];
int depth[MAXN];
int tot;
void dfs(int v,int p,int d)
{
    pa[0][v]=p; dfn[v]=++tot; pos[tot]=v;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(2*n-1,-1,0);
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
    int omaxi[4*MAXN],omini[4*MAXN],maxi[4*MAXN],mini[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void apply(int k,int type)
    {
        if(type==0) {maxi[k]=-INF; mini[k]=INF;}
        else {maxi[k]=omaxi[k]; mini[k]=omini[k];}
        lazy[k]=type;
    }
    void pushdown(int k)
    {
        if(lazy[k]==-1) return;
        for(int i=k*2;i<=k*2+1;i++) apply(i,lazy[k]);
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=-1; mini[k]=INF; maxi[k]=-INF; 
        if(l==r)
        {
            omaxi[k]=omini[k]=dfn[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);  build(k*2+1,mid+1,r);
        omaxi[k]=max(omaxi[k*2],omaxi[k*2+1]); omini[k]=min(omini[k*2],omini[k*2+1]);
    }
    void update(int k,int l,int r,int x,int y,int type)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            apply(k,type);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,type); update(k*2+1,mid+1,r,x,y,type);
        pushup(k);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges.push_back(make_pair(w,P(u,v)));
    }
    sort(edges.begin(),edges.end());
    init_dsu(2*n-1); int num=n;
    for(int i=0;i<n-1;i++)
    {
        int u=edges[i].S.F,v=edges[i].S.S,w=edges[i].F;
        num++; weight[num]=w;
        add_edge(num,find(u)); add_edge(num,find(v));
        p[find(u)]=num; p[find(v)]=num;
    }
    init(2*n-1);
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int type,l,r;
        scanf("%d",&type);
        if(type!=3)
        {
            scanf("%d%d",&l,&r);
            seg.update(1,1,n,l,r,2-type);
        }
        else
        {
            int v;
            scanf("%d",&v);
            int mini=seg.mini[1],maxi=seg.maxi[1];
            if(mini==INF) {puts("-1"); continue;}
            int ans=weight[lca(v,lca(pos[maxi],pos[mini]))];
            if(ans==0) puts("-1"); else printf("%d\n",ans);
        }
    }
    return 0;
}