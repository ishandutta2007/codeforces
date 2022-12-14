#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long dp[1000000][2];
vector<pair<int,int> > adj[1000000];
int n,k;
void dfs(int v,int pa,int w)
{
    vector<long long> vec;
    dp[v][0]=0;
    dp[v][1]=0;
    for (auto p:adj[v])
    {
        int u = p.first, W = p.second;
        if (u==pa)continue;
        dfs(u,v,W);
        vec.push_back(dp[u][1]-dp[u][0]);
        dp[v][0]+=dp[u][0];
        dp[v][1]+=dp[u][0];
    }
    sort(vec.begin(),vec.end());reverse(vec.begin(),vec.end());
    int m = vec.size();
    for (int i=0;i<min(m,k-1);i++)dp[v][0]+=vec[i],dp[v][1]+=vec[i];
    if (m>=k) {
        dp[v][0]+=vec[k-1];
    }
    dp[v][1]+=w;
    dp[v][1]=max(dp[v][1],dp[v][0]);
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++)adj[i].clear();
        for (int i=1;i<n;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1,0,0);
        printf("%lld\n",dp[1][1]);
    }
}