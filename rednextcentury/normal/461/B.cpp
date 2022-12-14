#include<bits/stdc++.h>
using namespace std;
long long dp[100005][2];
vector<int> adj[1000000];
long long mod = 1000000007;
bool vis[1000000];
int x[1000000];
int n;
void dfs(int v)
{
    dp[v][x[v]]=1;
    for (auto u:adj[v])
    {
        dfs(u);
        dp[v][1]=(dp[v][0]*dp[u][1]+dp[v][1]*(dp[u][0]+dp[u][1]))%mod;
        dp[v][0]=(dp[v][0]*(dp[u][0]+dp[u][1]))%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        p++;
        adj[p].push_back(i);
    }
    for (int i=1;i<=n;i++)
        cin>>x[i];
    dfs(1);
    cout<<dp[1][1]<<endl;
}