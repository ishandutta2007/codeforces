#include <bits/stdc++.h>

using namespace std;
long long dp[1000000];
vector<int> adj[1000000];
int main()
{
    long long n,m;
    cin>>n>>m;
    for (long long i=0;i<m;i++)
    {
        long long s,e;
        cin>>s>>e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    dp[1]=1;
    for (long long i=2;i<=n;i++)
    {
        for (long long j=0;j<adj[i].size();j++)
        {
            dp[i]=max(dp[i],dp[adj[i][j]]+1);
        }
    }
    long long ans=0;
    for (long long i=1;i<=n;i++)
        ans=max(ans,dp[i]*adj[i].size());
    cout<<ans<<endl;
}