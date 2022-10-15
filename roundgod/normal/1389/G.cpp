#include<bits/stdc++.h>
#define MAXN 300005
#define MAXM 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,tot,t,bcc_cnt,mcnt;
vector<int> G[MAXN],bcc[MAXN];
int st[MAXN],dfn[MAXN],low[MAXN],bccno[MAXN],c[MAXN],w[MAXM];
ll val[MAXN];
bool is_special[MAXN];
int cnt[MAXN];
int U[MAXM],V[MAXM];
bool isbridge[MAXM];
vector<P> tree[MAXN];
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
            tree[u].push_back(P(v,i));tree[v].push_back(P(u,i));
        }
    }
}
int sz[MAXN];
ll dp[MAXN],ans[MAXN];
void dfs3(int v,int p)
{
    sz[v]=cnt[v];
    for(auto e:tree[v])
    {
        int to=e.F,cost=w[e.S];
        if(to==p) continue;
        dfs3(to,v);
        sz[v]+=sz[to];
    }
    dp[v]=val[v];
    for(auto e:tree[v])
    {
        int to=e.F,cost=w[e.S];
        if(sz[to]==k||sz[to]==0)
        {
            dp[v]+=max(0LL,dp[to]);
        }
        else dp[v]+=max(0LL,dp[to]-cost);
    }
}
void change_root(int v,int to,int cost)
{
    if(sz[to]==k||sz[to]==0)
    {
        dp[v]-=max(0LL,dp[to]);
    }
    else dp[v]-=max(0LL,dp[to]-cost);
    sz[v]-=sz[to]; sz[to]+=sz[v];
    if(sz[v]==k||sz[v]==0)
    {
        dp[to]+=max(0LL,dp[v]);
    }
    else dp[to]+=max(0LL,dp[v]-cost);
}
void dfs4(int v,int p)
{
    ans[v]=dp[v];
    for(auto e:tree[v])
    {
        int to=e.F,cost=w[e.S];
        if(to==p) continue;
        change_root(v,to,cost);
        dfs4(to,v);
        change_root(to,v,cost);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(is_special,false,sizeof(is_special));
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        is_special[x]=true;
    }
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    build_bridge_tree();
    for(int i=1;i<=n;i++) if(is_special[i]) cnt[bccno[i]]++;
    for(int i=1;i<=n;i++) val[bccno[i]]+=c[i];
    dfs3(1,0);
    dfs4(1,0);
    for(int i=1;i<=n;i++) printf("%lld ",ans[bccno[i]]);
    return 0;
}