#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int N = 200009;
vector<int> g[N];
bitset<N> used;
int dep[N];

void dfs_dep(int v) {
    dep[v] = 1;
    int ku = 2e9;
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs_dep(u);
            ku = min(ku, dep[u]);
        }
    }
    if (ku != 2e9) {
        dep[v] = ku + 1;
    }
}

int A = 0;

void dfs(int v, int next, int dist_next) {
    A = max(A, dist_next);
    used[v] = true;
    vector<pair<int, int>> h;
    for (auto u : g[v]) {
        if (!used[u]) {
            h.pb({dep[u], u});
        }
    }
    if (h.empty()) return;
    sort(h.begin(), h.end());
    if (dist_next == 0) {
        for (int i = 0; i < (int) h.size() - 1; i++) {
            int u = h[i].second;
            dfs(u, h[i + 1].second, 2);
        }
        dfs(h.back().second, next, dist_next + 1);
    } else {
        h.pb(h[0]);
        for (int i = 1; i < (int) h.size() - 1; i++) {
            int u = h[i].second;
            dfs(u, h[i + 1].second, 2);
        }
        dfs(h.front().second, next, dist_next + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        A = 0;
        int n;
        cin >> n;
        for (int x = 0; x < n; x++) {
            g[x] = {};
            dep[x] = 0;
        }
        used.reset();
        for (int _ = 0; _ < n - 1; _++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs_dep(0);
        used.reset();
        dfs(0, 0, 0);
        cout << A << '\n';
    }
}