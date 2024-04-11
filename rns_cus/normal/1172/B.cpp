#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, dp[N], fac[N];
const int mod = 998244353;
vector <int> adj[N];

void dfs(int u, int p = 0) {
    dp[u] = 1;
    int deg = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u), deg ++;
        dp[u] = 1ll * dp[u] * dp[v] % mod;
    }
    dp[u] = 1ll * dp[u] * fac[deg] % mod * (u > 1 ? deg + 1 : n) % mod;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i < N; i ++) fac[i] = 1ll * i * fac[i-1] % mod;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    printf("%d\n", dp[1]);

    return 0;
}