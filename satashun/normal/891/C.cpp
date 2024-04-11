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
#define ALL(c) (c).begin(), (c).end()

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

const int maxw = 500010;

V<pii> com[maxw];
V<pii> re[maxw];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    V<pair<pii, int>> edges(m);
    rep(i, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        edges[i] = mp(mp(u, v), w);
        re[w].eb(u, v);
    }

    int q;
    scanf("%d", &q);

    rep(i, q) {
        int k;
        scanf("%d", &k);
        rep(j, k) {
            int e;
            scanf("%d", &e);
            --e;
            com[edges[e].se].eb(i, e);
        }
    }

    V<bool> ok(q, true);
    unionfind uf;
    uf.init(n);

    for (int i = 1; i < maxw; ++i) {
        sort(ALL(com[i]));
        if (com[i].size()) {
            debug(i, com[i]);
        }
        for (int j = 0; j < com[i].size();) {
            int k = j;
            V<int> vec;
            int id = com[i][j].fi;

            while (k < com[i].size() && com[i][j].fi == com[i][k].fi) {
                vec.pb(com[i][k].se);
                k++;
            }

            V<int> nodes;
            for (int e : vec) {
                nodes.pb(uf.find(edges[e].fi.fi));
                nodes.pb(uf.find(edges[e].fi.se));
            }
            sort(ALL(nodes));
            nodes.erase(unique(ALL(nodes)), nodes.end());

            unionfind test;
            test.init(nodes.size());
            debug(id, vec, nodes);
            for (int e : vec) {
                int a, b;
                tie(a, b) = edges[e].fi;
                a = uf.find(a), b = uf.find(b);
                debug(edges[e]);
                a = lower_bound(ALL(nodes), a) - nodes.begin();
                b = lower_bound(ALL(nodes), b) - nodes.begin();
                debug(a, b);
                if (test.same(a, b)) {
                    ok[id] = false;
                    break;
                }
                test.unite(a, b);
            }

            j = k;
        }

        if (re[i].size()) {
            debug(re[i]);
        }

        for (auto e : re[i]) {
            uf.unite(e.fi, e.se);
        }
    }

    rep(i, q) { puts(ok[i] ? "YES" : "NO"); }

    return 0;
}