#include<bits/stdc++.h>
using namespace std;
int dp[100003];
vector<int> adj[1000000];
int col[1000000];
bool vis[1000000];
int in[1000000];
int DP(int v)
{
    if (vis[v])return dp[v];
    dp[v]=0;
    vis[v]=1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (col[v]==0 && col[u]==1)
            dp[v]=max(dp[v],1+DP(u));
        else
            dp[v]=max(dp[v],DP(u));
    }
    return dp[v];
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>col[i];
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        in[u]++;
    }
    for (int i=0;i<n;i++)
        if (in[i]==0)
            adj[n].push_back(i);
    cout<<DP(n)<<endl;
}