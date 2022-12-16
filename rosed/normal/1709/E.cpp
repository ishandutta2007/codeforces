/**
 * Created by megurine on 2022/07/21.
 * 
 **/
#include <bits/stdc++.h>

using namespace std;
#ifdef MEGURINE
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#endif

#define fastIO() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define itr(it) begin(it), end(it)
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
#define endl '\n'
#define YES() cout << "YES\n"
#define NO() cout << "NO\n"

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> g(n);
    for (auto &x: a) cin >> x;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<set<int>> st(n);
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int u, int p, int val) {
        bool ok = true;
        for (auto v: g[u]) {
            if (v == p) continue;
            dfs(v, u, val ^ a[u]);
            if (st[u].size() < st[v].size()) swap(st[u], st[v]);
            if (ok) {
                for (auto x: st[v]) {
                    if (st[u].count(x ^ a[u])) {
                        ok = false;
                        break;
                    }
                    //st[u].emplace(x);
                }
                for (auto x: st[v]) {
                    // if (st[u].count(x ^ a[u])) {
                    //     ok = false;
                    //     break;
                    // }
                    st[u].emplace(x);
                }
            }
        }
        if (st[u].count(val)) ok = false;
        if (ok) st[u].emplace(val ^ a[u]);
        else st[u] = set<int>(), ++ans;
    };
    dfs(0, -1, 0);
    cout << ans << endl;
}

int main() {
#ifdef MEGURINE
    fr("/Users/megurine/CLionProjects/codeforces/input.txt");
    fw("/Users/megurine/CLionProjects/codeforces/output.txt");
    clock_t start = clock();
#endif
    fastIO();
    int T = 1;
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) {
        solve();
    }
    cout.flush();
#ifdef MEGURINE
    clock_t end = clock();
    cout << "\n\nRunning Time : " << (double) (end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}