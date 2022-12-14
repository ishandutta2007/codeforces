#include<bits/stdc++.h>
using namespace std;
int disc[1000000];
int low[1000000];
int par[1000000];
int vv[1000000];
vector<int> G[1000000];
int p[1000000];
long long val[1000000];
long long sz[1000000];
int tim;
vector<pair<int,int> > bridges;
vector<pair<int,int> > nope;
vector<int> adj[1000000];
void pre(int v)
{
    vv[v]=1;
    low[v]=disc[v]=tim++;
    for (auto u:G[v])
    {
        if (vv[u])
        {
            if (u==p[v])continue;
            low[v]=min(low[v],disc[u]);
            nope.push_back({v,u});
        }
        else{
            p[u]=v;
            pre(u);
            low[v]=min(low[v],low[u]);
            if (low[u]>disc[v]) {
                bridges.push_back({u,v});
            } else {
                nope.push_back({v,u});
            }
        }
    }
}
int get(int x)
{
    if (par[x]==x)return x;
    return par[x]=get(par[x]);
}
void add(int u,int v)
{
    u = get(u);
    v = get(v);
    if (u==v)return;
    val[v]+=val[u];
    sz[v]+=sz[u];
    par[u]=v;
}
vector<int> vec;
int ppp[1000000];
bool vis[1000000];
long long ret=0;
long long dp[1000000];
void dfs(int v,int pa=-1)
{
    ppp[v]=pa;
    if (sz[v]>1)vec.push_back(v);
    dp[v]=val[v];
    for (auto u:adj[v])
    {
        if (u==pa)continue;
        dfs(u,v);
        dp[v]=max(dp[v],dp[u]+val[v]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>val[i];
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s;
    cin>>s;
    pre(s);
    for (int i=1;i<=n;i++)par[i]=i,sz[i]=1;
    for (auto e:nope) {
        if (e.first==e.second)continue;
        add(e.first,e.second);
    }
    for (auto e:bridges)
    {
        int u = get(e.first);
        int v = get(e.second);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    s = get(s);
    dfs(s);
    for (auto x:vec)
    {
        int v = x;
        while(v!=-1 && !vis[v])
        {
            vis[v]=1;
            ret+=val[v];
            v=ppp[v];
        }
    }
    long long ans=ret;
    for (int i=1;i<=n;i++)
        if (!vis[i])
            ans=max(ans,ret+dp[i]);
    cout<<ans<<endl;
}