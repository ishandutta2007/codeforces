#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
const LL MOD = 1e9 + 7;
vector<int> g[N];
int n, sz[N];
LL dp[N][2];

void dfs(int u,int p) {
    sz[u] = 1;
    for(auto v: g[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    dp[u][1] = 1;
  
    if (g[u].size()) {
        for(int i=0;i<g[u].size();i++) {
            int v=g[u][i];
            LL f[2] = {0};
            for(int x=0;x<2;x++) for(int y=0;y<2;y++) {
                (f[(x+y)%2] += 1LL * dp[u][x] * dp[v][y]) %= MOD;
            }
            for(int x=0;x<2;x++) dp[u][x] = f[x];
        }
        (dp[u][0] *= 2) %= MOD, (dp[u][1] *= 2) %= MOD;
        
        //printf("u = %d, (%lld, %lld)\n", u,dp[u][0],dp[u][1]);
        LL sub[2]={0}; 

        sub[0]=1, sub[1]=0;
        for(auto v: g[u]) {
            LL tmp[2];
            tmp[0] = (sub[0] + sub[1] * (dp[v][0] - 1)) % MOD; 
            tmp[1] = (sub[1] + sub[0] * (dp[v][0] - 1)) % MOD;
            sub[0] = tmp[0], sub[1] = tmp[1];
        }
       // printf("# %lld, %lld\n", sub[0], sub[1]);
        dp[u][1] = ((dp[u][1] - sub[1] - sub[0] + 2 * MOD) % MOD + MOD) % MOD;
        
        sub[0]=1, sub[1]=0;
        for(auto v: g[u]) {
            LL tmp[2];
            tmp[0] = (sub[0] + sub[1] * dp[v][1] % MOD) % MOD;
            tmp[1] = (sub[1] + sub[0] * dp[v][1] % MOD) % MOD;
            sub[0] = tmp[0], sub[1] = tmp[1];
        }
        //printf("$ %lld, %lld\n", sub[0], sub[1]);
        dp[u][0] = ((dp[u][0] - sub[1] + MOD) % MOD + MOD) % MOD;
    }   
    if(u > 1) dp[u][0] ++;
}
int main() {
    scanf("%d", &n);
    for(int i=2;i<=n;i++) {
        int p; scanf("%d", &p);
        g[p].push_back(i);
    }
    for(int i=1;i<=n;i++) sort(g[i].begin(), g[i].end());
    dfs(1,1);
    printf("%lld\n", ((dp[1][0]+dp[1][1])%MOD + MOD) % MOD);
}