#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
struct Query{
    int l, k, id;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1), ans(q + 1);
        vector<vector<int>> G(n + 1);
        vector<vector<Query>> Q(n + 1);
        for (int i = 1; i <= n; i += 1) cin >> a[i];
        for (int i = 2, p; i <= n; i += 1) {
            cin >> p;
            G[p].push_back(i);
        }
        for (int i = 1; i <= q; i += 1) {
            int v, l, k;
            cin >> v >> l >> k;
            Q[v].push_back({l, k, i});
        }
        vector<int> c(n + 1);
        set<pair<int, int>> s;
        int m = 1;
        while (m <= n + 1) m <<= 1;
        vector<int> bit(m);
        auto add = [&](int x, int d) {
            for (; x < m; x += x & -x) bit[x] += d;
        };
        auto sum = [&](int x) {
            int res = 0;
            for (; x; x -= x & -x) res += bit[x];
            return res;
        };
        for (int i = 1; i <= n; i += 1) {
            s.emplace(0, i);
            add(0 + 1, 1);
        }
        function<void(int)> DFS = [&](int u) {
            s.erase({c[a[u]], a[u]});
            add(c[a[u]] + 1, -1);
            c[a[u]] += 1;
            s.emplace(c[a[u]], a[u]);
            add(c[a[u]] + 1, 1);
            for (auto [l, k, id] : Q[u]) {
                int p = sum(l) + k;
                if (p > n) ans[id] = -1;
                else {
                    int L = 0, R = m;
                    while (L < R) {
                        int M = (L + R) >> 1;
                        if (bit[M] < p) {
                            p -= bit[M];
                            L = M + 1;
                        }
                        else R = M;
                    }
                    ans[id] = s.lower_bound({L - 1, 0})->second;
                }
            };
            for (int v : G[u])
                DFS(v);
            s.erase({c[a[u]], a[u]});
            add(c[a[u]] + 1, -1);
            c[a[u]] -= 1;
            s.emplace(c[a[u]], a[u]);
            add(c[a[u]] + 1, 1);
        };
        DFS(1);
        for (int i = 1; i <= q; i += 1) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}