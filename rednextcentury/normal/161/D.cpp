#include<bits/stdc++.h>
using namespace std;
long long dp[50005][505];
vector<int> adj[1000000];
bool vis[1000000];
int n,k;
long long ret=0;
void dfs(int v)
{
    vis[v]=1;
    dp[v][0]=1;
    for (auto u:adj[v])
    {
        if (vis[u])continue;
        dfs(u);
        for (int i=0;i<k;i++)
            ret+=dp[u][i]*dp[v][k-i-1];
        for (int i=0;i<k;i++)
            dp[v][i+1]+=dp[u][i];
    }
}
int main()
{
    cin>>n>>k;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<ret<<endl;
}