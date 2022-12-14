
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
vector<int> adj[1000001];
vector<int> len[1000001];
bool vis[1000001];
long long b[1000000];
long long c[1000000];
long long dp[1000001][2];
long long cost[1000001][2];
void dfs(int v,int p)
{
    vis[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vis[u]) continue;
        dfs(u,v);
    }
    int tot=0;
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (u==p) continue;
        b[tot]=u;
        c[tot++]=len[v][i];
    }
    dp[0][0]=dp[0][1]=0;
    for (int i=0;i<tot;i++)
    {
        dp[i+1][0]=dp[i][0]+cost[b[i]][0]+2*c[i];
        dp[i+1][1]=min(dp[i][0]+cost[b[i]][1]+c[i],dp[i][1]+cost[b[i]][0]+2*c[i]);
    }
    cost[v][0]=dp[tot][0];
    cost[v][1]=dp[tot][1];
}
int main()
{
    long long n;
    cin>>n;
    for (long long i=0;i<n-1;i++)
    {
        long long s,e,w;
        cin>>s>>e>>w;
        adj[s].push_back(e);
        len[s].push_back(w);
        len[e].push_back(w);
        adj[e].push_back(s);
    }
    dfs(1,0);
    cout<<cost[1][1]<<endl;
}