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

VV<pii> g;
V<int> col, vis;

bool dfs(int v, int c) {
    col[v] = c;
    for (auto [to, d] : g[v]) {
        if (col[to] != -1) {
            if (col[to] != (c ^ 1)) return false;
        } else {
            if (!dfs(to, c ^ 1)) return false;
        }
    }
    return true;
}

V<int> cmp, pl;

bool go(int v, int k, int cur) {
    cmp[v] = k;
    pl[v] = cur;
    vis[v] = 1;
    for (auto [to, d] : g[v]) {
        if (d == 0) continue;
        if (!vis[to]) {
            if (!go(to, k, cur + d)) return false;
        } else {
            if (pl[to] != cur + d) {
                return false;
            }
        }
    }
    return true;
}

VV<pii> g2;

const int INF = TEN(9);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    col = V<int>(n, -1);

    rep(i, m) {
        int u, v, b;
        cin >> u >> v >> b;
        --u, --v;
        if (b == 1) {
            g[u].eb(v, 1);
            g[v].eb(u, -1);
        } else {
            g[u].eb(v, 0);
            g[v].eb(u, 0);
        }
    }

    if (!dfs(0, 0)) {
        cout << "NO" << endl;
        return 0;
    }
    debug(col);

    vis = V<int>(n);
    cmp = V<int>(n);
    pl = V<int>(n);

    int now = 0;
    rep(i, n) {
        if (!vis[i]) {
            if (!go(i, i, 0)) {
                cout << "NO" << endl;
                return 0;
            }
            now++;
        }
    }

    // rep(i, n) pl[i] -= col[cmp[i]];

    debug(cmp);
    debug(pl);

    g2.resize(n);

    set<tuple<int, int, int, int>> used;

    rep(v, n) {
        for (auto [to, d] : g[v]) {
            if (d != 0) continue;
            int a = cmp[v], b = cmp[to];
            if (a == b) {
                if (abs(pl[v] - pl[to]) != 1) {
                    cout << "NO" << endl;
                    return 0;
                }
                continue;
            }

            // debug(a, b, pl[v], pl[to]);
            //|(2 * x_a + col[a] + pl[v]) - (2 * x_b + col[b] + pl[to])| = 1
            int l = -1, r = 1;
            int df = col[a] + pl[v] - col[b] - pl[to];
            l = (l - df) / 2;
            r = (r - df) / 2;

            auto tp = make_tuple(a, b, l, r);
            if (used.count(tp)) continue;
            used.insert(tp);
            tp = make_tuple(b, a, r, l);
            used.insert(tp);

            g2[a].eb(b, -l);
            g2[b].eb(a, r);

            debug(a, b, l, r);
        }
    }

    V<int> mini(n), maxi(n);
    rep(i, n) {
        chmin(mini[cmp[i]], pl[i]);
        chmax(maxi[cmp[i]], pl[i]);
    }

    V<int> ds(n);

    int ans = -1;

    V<int> pt(n);
    V<bool> em(n);
    rep(i, n) em[cmp[i]] = 1;

    rep(s, n) {
        if (!em[s]) continue;
        fill(ALL(ds), INF);
        ds[s] = 0;

        rep(tt, n) {
            rep(v, n) if (ds[v] != INF) {
                for (auto e : g2[v]) {
                    chmin(ds[e.fi], ds[v] + e.se);
                }
            }
        }
        bool ok = true;
        rep(v, n) {
            for (auto e : g2[v]) {
                if (ds[e.fi] > ds[v] + e.se) {
                    ok = false;
                }
            }
        }
        if (ok) {
            debug(s, ds);
            int md = 0;
            rep(i, n) {
                int d = ds[cmp[i]] * 2 + col[cmp[i]] + maxi[cmp[i]] -
                        (ds[s] * 2 + col[s] + mini[s]);
                chmax(md, d);
            }
            if (md > ans) {
                rep(i, n) pt[i] = ds[cmp[i]] * 2 + pl[i] + col[cmp[i]];
                debug(md, ds, pt, pl, col);
                int m = *min_element(ALL(pt));
                rep(i, n) pt[i] -= m;
                ans = md;
            }
        }
    }
    if (ans == -1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << ans << endl;
    rep(i, n) cout << pt[i] << (i == n - 1 ? '\n' : ' ');

    return 0;
}