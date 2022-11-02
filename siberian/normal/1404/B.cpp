#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

int n, a, b, da, db;
vector<vector<int>> g;
vector<int> dist;

void dfs(int v, int p) {
    for (auto i : g[v]) {
        if (i == p) continue;
        dist[i] = dist[v] + 1;
        dfs(i, v);
    }
}

void solve() {
    cin >> n >> a >> b >> da >> db;
    a--;
    b--;
    g.assign(n, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dist.assign(n, 0);
    dfs(a, -1);
    if (dist[b] <= da) {
        cout << "Alice\n";
        return;
    }
    int pos = max_element(all(dist)) - dist.begin();
    dist[pos] = 0;
    dfs(pos, -1);
    int d = *max_element(all(dist));
    if (d <= 2 * da) {
        cout << "Alice\n";
        return;
    }
    if (2 * da >= db) {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}