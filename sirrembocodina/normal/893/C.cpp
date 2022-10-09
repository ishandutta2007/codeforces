#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<vector<int>> g;
vector<bool> used;
vector<int> c;
int mn;

void dfs(int v) {
    used[v] = true;
    mn = min(mn, c[v]);
    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    used.resize(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            mn = 2e18;
            dfs(i);
            ans += mn;
        }
    }
    cout << ans;
}