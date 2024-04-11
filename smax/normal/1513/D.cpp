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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct DSU {
    int comp;
    vector<int> par, sz, mn, mx;

    DSU(int n) : comp(n), par(n), sz(n, 1), mn(n), mx(n) {
        iota(par.begin(), par.end(), 0);
        iota(mn.begin(), mn.end(), 0);
        iota(mx.begin(), mx.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        mn[u] = min(mn[u], mn[v]);
        mx[u] = max(mx[u], mx[v]);
        comp--;
        return true;
    }
};

struct PathCompression {
    vector<int> par;

    PathCompression(int n) : par(n) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    // u -> v
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        par[u] = v;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<pair<int, int>> a(n);
        vector<int> b(n);
        for (int i=0; i<n; i++) {
            cin >> a[i].first;
            a[i].second = i;
            b[i] = a[i].first;
        }

        PathCompression l(n), r(n);
        sort(a.begin(), a.end());
        DSU dsu(n);
        long long ret = 0;
        for (auto [x, i] : a) {
            if (x >= p)
                break;
            int ll = dsu.mn[dsu.find(i)];
            if (ll == i) {
                while (ll > 0 && b[dsu.mx[dsu.find(ll - 1)]] % x == 0) {
                    bool done = dsu.sz[dsu.find(ll - 1)] > 1;
                    if (dsu.unite(ll, ll - 1))
                        ret += x;
                    l.unite(ll, ll - 1);
                    if (done)
                        break;
                    ll = l.find(ll);
                }
            }
            int rr = dsu.mx[dsu.find(i)];
            if (rr == i) {
                while (rr + 1 < n && b[dsu.mn[dsu.find(rr + 1)]] % x == 0) {
                    bool done = dsu.sz[dsu.find(rr + 1)] > 1;
                    if (dsu.unite(rr, rr + 1))
                        ret += x;
                    r.unite(rr, rr + 1);
                    if (done)
                        break;
                    rr = r.find(rr);
                }
            }
            // int nl = l[ll], nr = r[rr];
            // if (nl >= 0)
            //     r[nl] = ll;
            // if (nr < n)
            //     l[nr] = rr;
            // DEBUG("HERE");
            // int y = ll;
            // while (y != rr) {
            //     int temp = y;
            //     DEBUG(n, ll, rr, y, r[y]);
            //     if (dsu.unite(y, r[y]))
            //         ret += x;
            //     y = r[y];
            //     DEBUG(n, temp);
            //     l[temp] = nl;
            //     r[temp] = nr;
            // }
            // DEBUG(n, rr);
            // l[rr] = nl;
            // DEBUG(x, i, ret, ll, rr, nl, nr, dsu.comp);
        }
        cout << ret + (long long) (dsu.comp - 1) * p << "\n";
    }

    return 0;
}