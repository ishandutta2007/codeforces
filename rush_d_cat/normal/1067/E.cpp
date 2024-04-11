#include <iostream>
#include <vector>
using namespace std;
const int N=500000+10;
typedef long long LL;
const LL MOD = 998244353;
int n;
LL dp[N][2],po[N],ans=0,sz[N];
vector<int> g[N];
void dfs(int u,int p){
    sz[u]=1; dp[u][0]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==p)continue;
        dfs(v,u);sz[u]+=sz[v];
        // u is taken
        dp[u][1] = dp[u][1] * ((dp[v][0]+dp[v][1])%MOD + (dp[v][0]+dp[v][1])%MOD) % MOD;
        dp[u][1] = (dp[u][1] + dp[u][0]*dp[v][0])%MOD;
        // u is gou
        dp[u][0] = dp[u][0] * ((dp[v][0]+dp[v][1])%MOD + dp[v][1])%MOD;
    }
    ans = ans + dp[u][1] * po[n+1-sz[u]]; ans %= MOD;
}
int main(){
    po[0]=1; for(int i=1;i<N;i++)po[i]=po[i-1]*2%MOD;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,1); cout<<ans<<endl;
}