#include <bits/stdc++.h>
using namespace std;

#define N 300300
typedef pair <int, int> pii;
typedef long long ll;
int n, w[N];
ll ans, dp[N];
vector <pii> adj[N];

void dfs(int u, int pa = 0) {
    ll s_mx = 0;
    for (auto p : adj[u]) {
        int v = p.first, w = p.second;
        if (v == pa) continue;
        dfs(v, u);
        ll x = dp[v] - w;
        if (dp[u] < x) s_mx = dp[u], dp[u] = x;
        else if (s_mx < x) s_mx = x;
    }
    dp[u] += w[u];
    ans = max(ans, dp[u] + s_mx);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    for (int i = 1, u, v, w; i < n; i ++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}