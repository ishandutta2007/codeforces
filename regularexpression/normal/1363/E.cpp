#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;
const int INF = 2e18 + 7;

int n;
vector<int> g[N];
int a[N], b[N], c[N], ans = 0;

pair<int, int> dfs(int u, int par = -1, int cost = INF) {
    cost = min(cost, a[u]);
    pair<int, int> res = {0, 0};
    if (b[u] == 0 && c[u] == 1) res.first++;
    if (b[u] == 1 && c[u] == 0) res.second++;
    for (auto v : g[u]) {
        if (v != par) {
            auto kek = dfs(v, u, cost);
            res.first += kek.first;
            res.second += kek.second;
        }
    }
    int val = min(res.first, res.second);
    ans += val * cost * 2;
    res.first -= val;
    res.second -= val;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto kek = dfs(0);
    if (kek.first != 0 || kek.second != 0) cout << "-1\n"; else cout << ans;
    return 0;
}