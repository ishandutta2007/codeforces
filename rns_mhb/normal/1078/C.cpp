#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

#define N 300010

vector <int> adj[N];
int n, dp[N][3];

void dfs(int x, int p) {
    dp[x][0] = 1, dp[x][1] = 1, dp[x][2] = 0;
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i];
        if(y == p) continue;
        dfs(y, x);
        dp[x][0] = 1ll*dp[x][0]*(dp[y][0]+dp[y][2]) % mod;
        dp[x][2] = (1ll*dp[x][2]*(dp[y][0]+2ll*dp[y][2])%mod+1ll*dp[x][1]*dp[y][1])%mod;
        dp[x][1] = 1ll*dp[x][1]*(dp[y][0]+2ll*dp[y][2])%mod;
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1, x, y; i < n; i ++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    printf("%d\n", (dp[1][0] + dp[1][2])%mod);
}