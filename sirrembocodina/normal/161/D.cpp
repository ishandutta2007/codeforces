#include <bits/stdc++.h>

#define int int64_t

using namespace std;

vector<vector<int>> g;
vector<vector<int>> dp;

int ans = 0;
int k;

void dfs(int v, int p) {
    vector<int> sons;
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        sons.push_back(to);
        dfs(to, v);
    }
    dp[v].resize(k);
    dp[v][0] = 1;
    for (int to: sons) {
        for (int x = 0; x <= k - 1; x++) {
            ans += dp[to][x] * dp[v][k - 1 - x];
        }
        for (int x = 0; x + 1 < k; x++) {
            dp[v][x + 1] += dp[to][x];
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n >> k;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp.resize(n);
    dfs(0, -1);
    cout << ans;
}