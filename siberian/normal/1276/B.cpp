#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, m, a, b;
vector<vector<int>> g;

void dfs(int v, int ban, set<int> & have) {
    have.insert(v);
    for (auto i : g[v]) {
        if (have.count(i)) continue;
        if (i == ban) continue;
        dfs(i, ban, have);
    }
}

void solve() {
    cin >> n >> m >> a >> b;
    a--;
    b--;
    g.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<int> A;
    dfs(a, b, A);
    set<int> B;
    dfs(b, a, B);
    int cnt = 1;
    for (auto i : A) {
        if (B.count(i)) {
            cnt++;
        }
    }
    cout << (ll) (A.size() - cnt) * (B.size() - cnt) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}