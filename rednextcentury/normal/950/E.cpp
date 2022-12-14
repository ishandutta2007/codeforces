# include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())
vector<int> in;
map<pair<int,int> ,int> mp;
map<pair<int,int> ,int> MP;
struct graph {
  int n;
  vector<vector<int>> adj;
  graph(int n) : n(n), adj(n) { }
  void add_edge(int src, int dst) {
    adj[src].push_back(dst);
  }

  vector<vector<int>> strongly_connected_components() {
    vector<int> open, id(n);
    vector<vector<int>> scc;
    int t = -n-1;
    auto argmin = [&](int u, int v) { return id[u] < id[v] ? u : v; };
    function<int(int)> dfs = [&](int u) {
      open.push_back(u);
      id[u] = t++;
      int w = u;
      for (int v: adj[u]) {
        if      (id[v] == 0) w = argmin(w, dfs(v));
        else if (id[v]  < 0) w = argmin(w, v);
      }
      if (w == u) {
        scc.push_back({});
        while (1) {
          int v = open.back();
          open.pop_back();
          id[v] = scc.size();
          scc.back().push_back(v);
          if (u == v) break;
        }
      }
      return w;
    };
    for (int u = 0; u < n; ++u)
      if (id[u] == 0) dfs(u);
    in = id;
    return scc;
  }
};

vector<vector<int> > SCC;
vector<int> adj[100002];
int tot;
int in_SCC[100002];
int a[100002];
int cost[100002];
int vis[100002];
int dp[100002];
int cur;
int solve(int v)
{
    if (vis[v]==cur)return 0;
    if (vis[v])
    {
        vis[v]=cur;
        return dp[v];
    }
    vis[v]=cur;
    dp[v]=cost[v];
    for (int i=0;i<adj[v].size();i++)
        dp[v]+=solve(adj[v][i]);
    return dp[v];
}
vector<int> ret;
int n;
void dfs(int v)
{
    if (vis[v])return;
    vis[v]=1;
    assert(ret.size()<=n);
    for (int i=0;i<SCC[v].size();i++)
        ret.push_back(SCC[v][i]);
    for (int i=0;i<adj[v].size();i++)
        dfs(adj[v][i]);
}
void getSol(int v)
{
    memset(vis,0,sizeof(vis));
    dfs(v);
    int sz=ret.size();
    printf("%d\n",sz);
    for (int i=0;i<ret.size();i++)
        printf("%d ",ret[i]+1);
    printf("\n");
}
int main()
{
    int r;
    int m,h;
    scanf("%d%d%d",&n,&m,&h);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    graph G(n);
    for (int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d",&u); scanf("%d",&v);
        u--,v--;
        if ((a[u]+1)%h == a[v] && ++MP[{u,v}]==1)
            G.add_edge(u,v);
        if ((a[v]+1)%h == a[u] && ++MP[{v,u}]==1)
            G.add_edge(v,u);
    }
    SCC = G.strongly_connected_components();
    tot = SCC.size();
    for (int i=0;i<tot;i++)
    {
        for (int j=0;j<SCC[i].size();j++)
        {
            cost[i]++;
            in_SCC[SCC[i][j]]=i;
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<G.adj[i].size();j++)
        {
            int u=G.adj[i][j];
            if (in_SCC[i]!=in_SCC[u] && ++mp[{in_SCC[i],in_SCC[u]}]==1)
            {
                adj[in_SCC[i]].push_back(in_SCC[u]);
            }
        }
    }
    int mn=1e9;
    int best= -1;
    for (int i=0;i<tot;i++)
    {
        if (adj[i].size()==0)
        {
            if (SCC[i].size()<mn)
            {
                mn=SCC[i].size();
                best = i;
            }
        }
    }
    assert(mn<=n);
    getSol(best);
    assert(mn==ret.size());
}