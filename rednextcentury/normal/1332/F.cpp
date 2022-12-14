#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n;
ll dp[1000000][2][2];
vector<int> adj[1000000];
void dfs(int v=1, int p=-1){
    dp[v][0][0]=dp[v][0][1]=1;
    for (auto u:adj[v]){
        if (u==p)
            continue;
        dfs(u,v);
        dp[v][1][1]=((dp[v][1][1]*(dp[u][1][0]+dp[u][1][1]+dp[u][0][0]))%mod +((dp[v][0][1]+dp[v][1][1])*(dp[u][0][0]+dp[u][1][0]))%mod)%mod;
        dp[v][1][0]=((dp[v][1][0]*(dp[u][1][0]+dp[u][1][1]+dp[u][0][0]))%mod +((dp[v][0][0]+dp[v][1][0])*((dp[u][0][0]+dp[u][0][1]+dp[u][1][1]+dp[u][1][0])%mod))%mod)%mod;
        dp[v][0][0]=(dp[v][0][0]*(dp[u][1][0]+dp[u][1][1]+dp[u][0][0]))%mod;
        dp[v][0][1]=(dp[v][0][1]*(dp[u][1][0]+dp[u][1][1]+dp[u][0][0]))%mod;
    }

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i+1<n;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    dfs();
    ll ret = dp[1][1][1]+dp[1][1][0]+dp[1][0][0]-1+mod;
    ret%=mod;
    cout<<ret<<endl;
}