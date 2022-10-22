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

class unionfind {
    vector<int> par, rank;

   public:
    void init(int n) {
        par.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y])
            par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
    }

    bool same(int x, int y) { return (find(x) == find(y)); }
};

struct SCC {
    int n;
    VV<int> g, rg;
    V<int> vs, cmp;
    V<bool> vis;

    SCC() {}
    SCC(int n) : n(n) {
        g = rg = VV<int>(n);
        vs = cmp = V<int>(n);
        vis = V<bool>(n);
    }

    void add_edge(int from, int to) {
        g[from].push_back(to);
        rg[to].push_back(from);
    }

    void dfs(int v) {
        vis[v] = true;

        for (int to : g[v]) {
            if (!vis[to]) {
                dfs(to);
            }
        }

        vs.push_back(v);
    }

    void rdfs(int v, int k, V<int>& vec) {
        vis[v] = true;
        cmp[v] = k;
        vec.push_back(v);

        for (int to : rg[v]) {
            if (!vis[to]) {
                rdfs(to, k, vec);
            }
        }
    }

    VV<int> calc() {
        rep(v, n) if (!vis[v]) dfs(v);

        fill(vis.begin(), vis.end(), false);

        int k = 0;
        reverse(vs.begin(), vs.end());

        VV<int> vcomp;

        for (int v : vs) {
            if (!vis[v]) {
                V<int> vec;
                rdfs(v, k++, vec);
                vcomp.push_back(vec);
            }
        }

        return vcomp;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    SCC g(n);
    V<pii> es;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g.add_edge(a, b);
        es.eb(a, b);
    }

    g.calc();
    unionfind uf;
    uf.init(n);
    V<int> cntv(n), cyc(n);

    for (auto& [a, b] : es) {
        uf.unite(a, b);
    }
    rep(i, n) cntv[uf.find(i)]++;
    for (auto& [a, b] : es) {
        if (g.cmp[a] == g.cmp[b]) {
            cyc[uf.find(a)] = 1;
        }
    }

    int ans = 0;
    rep(i, n) {
        if (cyc[i]) {
            ans += cntv[i];
        } else {
            ans += max(0, cntv[i] - 1);
        }
    }
    cout << ans << endl;

    return 0;
}