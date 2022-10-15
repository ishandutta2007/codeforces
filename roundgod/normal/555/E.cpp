#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 200005
#define MAXM 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,tot,t,bcc_cnt,mcnt;
vector<int> G[MAXN],H[MAXN],bcc[MAXN];
int st[MAXN],dfn[MAXN],low[MAXN],bccno[MAXN];
int U[MAXM],V[MAXM];
bool isbridge[MAXM];
int pa[MAXLOGN][MAXN];
bool vis[MAXN];
bool f;
int depth[MAXN];
vector<int> tree[MAXN];
int sum[2][MAXN];
vector<int> roots;
//bridge tree:
//edge-biconnected components are connected by bridges
void add_edge(int u,int v)
{
    U[++mcnt]=u;V[mcnt]=v;
    G[u].push_back(mcnt);G[v].push_back(mcnt);
}
int adj(int u,int e)
{
    return U[e]==u?V[e]:U[e];
}
void dfs1(int v,int edge)
{
    dfn[v]=low[v]=++tot;
    st[t++]=v;
    for(auto e:G[v])
    {
        if(e==edge) continue;
        int to=adj(v,e);
        if(!dfn[to])
        {
            dfs1(to,e);
            low[v]=min(low[v],low[to]);
        }
        else low[v]=min(low[v],dfn[to]);
    }
    if(low[v]==dfn[v]&&edge!=-1) isbridge[edge]=true;
}
void dfs2(int v)
{
    dfn[v]=1;
    bccno[v]=bcc_cnt;
    bcc[bcc_cnt].push_back(v);
    for(auto e:G[v])
    {
        int to=adj(v,e);
        if(isbridge[e]) continue;
        if(!dfn[to]) dfs2(to);
    }
}
int tarjan()
{
    bcc_cnt=tot=0;
    memset(dfn,0,sizeof(dfn));
    memset(isbridge,false,sizeof(isbridge));
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs1(i,-1);
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            bcc_cnt++;
            dfs2(i);
        }
    }
    return bcc_cnt;
}
void build_bridge_tree()
{
    tarjan();
    for(int i=1;i<=mcnt;i++)
    {
        if(isbridge[i])
        {
            int u=bccno[U[i]],v=bccno[V[i]];
            tree[u].push_back(v);tree[v].push_back(u);
        }
    }
}
void dfs(int v,int p,int d)
{
    vis[v]=true;
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)tree[v].size();i++)
        if(tree[v][i]!=p) dfs(tree[v][i],v,d+1);
}
void init(int V)
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=V;i++) if(!vis[i]) {dfs(i,0,0); roots.push_back(i);}
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(!pa[k][v]) pa[k+1][v]=0;
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
void dfs3(int v,int p)
{
    for(auto to:tree[v])
    {
        if(to==p) continue;
        dfs3(to,v);
        sum[0][v]+=sum[0][to];
        sum[1][v]+=sum[1][to];
    }
    if(sum[0][v]&&sum[1][v]) f=false;

}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    build_bridge_tree();
    init(bcc_cnt);
    f=true;
    for(int i=0;i<q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u=bccno[u]; v=bccno[v];
        if(u==v) continue;
        int l=lca(u,v);
        if(l==0) {f=false; break;}
        sum[0][u]++; sum[0][l]--;
        sum[1][v]++; sum[1][l]--;
    }
    for(auto v:roots) dfs3(v,0);
    if(f) puts("Yes"); else puts("No");
    return 0;
}