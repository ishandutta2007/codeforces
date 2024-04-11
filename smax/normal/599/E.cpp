#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> edges;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.emplace_back(u, v);
    }
    vector<vector<pair<int, int>>> lca(n);
    for (int i=0; i<q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        lca[c].emplace_back(a, b);
    }

    vector<vector<int>> valid(1 << n, vector<int>(n));
    for (int mask=0; mask<1<<n; mask++)
        for (int u=0; u<n; u++)
            if (~mask & (1 << u)) {
                valid[mask][u] = true;
                for (auto [a, b] : lca[u])
                    valid[mask][u] &= (u == a || mask & (1 << a)) && (u == b || mask & (1 << b));
            }

    vector<vector<long long>> dp(1 << n, vector<long long>(n, -1));

    auto solve = [&] (auto &self, int mask, int u) -> long long {
        long long &ret = dp[mask][u];
        if (ret != -1)
            return ret;
        if (mask == 0)
            return ret = 1;
        ret = 0;
        int highest = __lg(mask);
        for (int sub=mask; sub>0; sub=(sub-1)&mask)
            if (__lg(sub) == highest) {
                int x = sub;
                while (x > 0) {
                    int v = __lg(x & -x);
                    x -= x & -x;
                    bool ok = valid[sub ^ (1 << v)][v];
                    for (auto [a, b] : edges) {
                        if (u == a) {
                            if (v != b)
                                ok &= bool(~sub & (1 << b));
                        } else if (u == b) {
                            if (v != a)
                                ok &= bool(~sub & (1 << a));
                        } else {
                            if (sub & (1 << a))
                                ok &= bool(sub & (1 << b));
                            else if (sub & (1 << b))
                                ok &= bool(sub & (1 << a));
                        }
                    }
                    for (auto [a, b] : lca[u]) {
                        if (sub & (1 << a))
                            ok &= bool(~sub & (1 << b));
                        else if (sub & (1 << b))
                            ok &= bool(~sub & (1 << a));
                    }
                    if (ok)
                        ret += self(self, sub ^ (1 << v), v) * self(self, mask ^ sub, u);
                }
            }
        return ret;
    };

    cout << solve(solve, (1 << n) - 2, 0) << "\n";

    return 0;
}