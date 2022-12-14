#include<bits/stdc++.h>
using namespace std;
long long dp[1000000][3];
vector<int> adj[1000000];
long long mod = 998244353 ;
void dfs(int v)
{
    dp[v][0]=1;
    dp[v][1]=0;
    for (auto u:adj[v])
    {
        dfs(u);
        dp[v][2]=(dp[v][2]*((dp[u][0]+dp[u][1])%mod))%mod+(dp[v][1]*(dp[u][1])%mod)%mod;
        dp[v][2]%=mod;
        dp[v][1]=(dp[v][1]*(dp[u][0]))%mod+(dp[v][0]*dp[u][1])%mod;
        dp[v][1]%=mod;
        dp[v][0]=(dp[v][0]*dp[u][0])%mod;
    }
    dp[v][1]+=dp[v][2];
    dp[v][1]%=mod;
    dp[v][0]+=dp[v][2];
    dp[v][0]%=mod;
    dp[v][2]=0;
    if (adj[v].size()==0)dp[v][1]=1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    dfs(1);
    cout<<dp[1][0]<<endl;
}