#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, s, t, da, db;
        cin >> n >> s >> t >> da >> db;
        --s, --t;

        VV<int> g(n);
        rep(i, n - 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }

        V<int> far(n);
        V<multiset<int>> dw(n);
        V<int> up(n), dep(n);
        auto dfs = [&](auto&& self, int v, int p) -> int {
            int mx = 0;
            for (int to : g[v])
                if (to != p) {
                    dep[to] = dep[v] + 1;
                    int d = 1 + self(self, to, v);
                    dw[v].insert(d);
                    chmax(mx, d);
                }
            return far[v] = mx;
        };
        dfs(dfs, s, -1);

        auto dfs2 = [&](auto&& self, int v, int p, int pl = 0) -> void {
            up[v] = pl;
            for (int to : g[v]) {
                if (to != p) {
                    int d = far[to] + 1;
                    dw[v].erase(dw[v].find(d));
                    int npl = pl;
                    if (dw[v].size()) chmax(npl, *dw[v].rbegin());
                    dw[v].insert(d);
                    self(self, to, v, npl + 1);
                }
            }
        };

        dfs2(dfs2, s, -1);
        debug(up, far);
        rep(i, n) chmax(far[i], up[i]);
        debug(far);

        int st = -1;
        rep(i, n) if (far[i] <= da) { st = 0; }
        if (dep[t] <= da) st = 0;
        if (st == -1 && 2 * da < db) {
            st = 1;
        } else {
            st = 0;
        }
        cout << (st == 0 ? "Alice" : "Bob") << '\n';
    }

    return 0;
}