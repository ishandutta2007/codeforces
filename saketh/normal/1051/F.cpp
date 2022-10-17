#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::iterator find(vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename C, typename T> vector<T> prefixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); F0R (i, sz(v)) res[i+1] = res[i] + v[i]; return res;
    }
    template<typename C, typename T> vector<T> suffixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); F0Rd (i, sz(v)) res[i] = v[i] + res[i+1]; return res;
    }
}
using namespace __algorithm;

struct monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))monostate& ms) { return os; }
} ms;

template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    wedge<W>(int _u=-1, int _v=-1, int _i=-1) : u(_u), v(_v), i(_i) {}
    int operator[](int loc) const { return u ^ v ^ loc; }
    friend void re(wedge& e) { re(e.u, e.v, e.w); --e.u, --e.v; }
    friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

template<typename T> struct sparse_table {
    using F = function<T(const T&, const T&)>;

    int SZ;
    F combine;
    vector<T> table;

    T& entry(int l, int i) { return table[l * SZ + i]; }
    const T& entry(int l, int i) const { return table[l * SZ + i]; }

    sparse_table() {}
    sparse_table(const vector<T>& elts, F _combine) : SZ(sz(elts)), combine(_combine) {
        const int L = 32 - __builtin_clz(max(SZ - 1, 1));
        table.resize(L * SZ);
        copy(all(elts), table.begin());

        for (int l = 0; l + 1 < L; l++) {
            for (int i = 0; i < SZ; i++) {
                entry(l + 1, i) = entry(l, i);
                if (i + (1 << l) < SZ)
                    entry(l + 1, i) = combine(entry(l + 1, i), entry(l, i + (1 << l)));
            }
        }
    }

    // Accumulates the elements at indices in [i, j) in O(1)
    T operator()(int i, int j) const {
        assert(0 <= i && i < j && j <= SZ);
        int l = j - i - 1 ? 31 - __builtin_clz(j - i - 1) : 0;
        return combine(entry(l, i), entry(l, j - (1 << l)));
    }
};

/*
 * Supports O(1) lowest common ancestor queries on an immutable forest.
 */
struct lowest_common_ancestor {
    struct visit {
        int node, depth, index;
        static visit shallower(const visit& a, const visit& b) {
            if (a.depth != b.depth) return a.depth < b.depth ? a : b;
            return a.index > b.index ? a : b;
        }
    };

    int V;
    vector<visit> tour;
    sparse_table<visit> table;
    vi first, depth, par, comp;

    lowest_common_ancestor(const vvi& tree = {}, vi roots = {}) : V(sz(tree)) {
        depth.resz(V), comp.resz(V, -1), first.resz(V, -1), par.resz(V, -1);

        int cc = 0;
        auto dfs = [&](auto& self, int loc) -> void {
            comp[loc] = cc, first[loc] = sz(tour);
            tour.push_back({loc, depth[loc], sz(tour)});
            for (int nbr : tree[loc]) if (nbr != par[loc]) {
                par[nbr] = loc;
                depth[nbr] = depth[loc] + 1;
                self(self, nbr);
                tour.push_back({loc, depth[loc], sz(tour)});
            }
        };
        for (int i : roots) {
            assert(comp[i] == -1);
            dfs(dfs, i), cc++;
        }
        for (int i = 0; i < V; i++) {
            if (comp[i] == -1)
                dfs(dfs, i), cc++;
        }

        table = sparse_table<visit>(tour, visit::shallower);
    }

    // Returns the lowest common ancestor of u and v
    // Returns -1 if they are in different components
    int lca(int u, int v) {
        if (comp[u] != comp[v]) return -1;
        u = first[u], v = first[v];
        if (u > v) swap(u, v);
        return table(u, v + 1).node;
    }

    int dist(int u, int v) {
        assert(comp[u] == comp[v]);
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    // Checks if btw is on the path from u to v
    bool on_path(int u, int v, int btw) {
        return dist(u, v) == (dist(u, btw) + dist(btw, v));
    }

    // Returns the neighbor of u on the shortest path to v
    int first_step(int u, int v) {
        assert(u != v && comp[u] == comp[v]);
        int w = lca(u, v);
        return u == w ? tour[table(first[u], first[v]).index+1].node : par[u];
    }
};

// Extension for weighted trees to support path weight queries.
struct weighted_lowest_common_ancestor {
    int V;
    vll weighted_depth;
    vi root;
    lowest_common_ancestor lca;
    weighted_lowest_common_ancestor(const vvpii& tree = {}, vi roots = {}) : V(tree.size()) {
        vvi adj(V);
        for (int v = 0; v < sz(tree); v++)
            for (pii e : tree[v])
                adj[v].push_back(e.first);
        lca = lowest_common_ancestor(adj, roots);

        weighted_depth.resize(V, LLONG_MIN);
        root.resize(V);

        int cc = 0;
        auto dfs = [&](auto& self, int loc, int par, int rt) -> void {
            root[loc] = rt;
            for (pii e : tree[loc]) if (e.first != par) {
                weighted_depth[e.first] = weighted_depth[loc] + e.second;
                self(self, e.first, loc, rt);
            }
        };
        for (int i : roots) {
            assert(weighted_depth[i] == LLONG_MIN);
            weighted_depth[i] = 0;
            dfs(dfs, i, i, i), cc++;
        }
        for (int i = 0; i < V; i++) {
            if (weighted_depth[i] == LLONG_MIN) {
                weighted_depth[i] = 0;
                dfs(dfs, i, i, i), cc++;
            }
        }
    }

    ll path_weight(int u, int v) {
        assert(lca.comp[u] == lca.comp[v]);
        return weighted_depth[u] + weighted_depth[v] - 2 * weighted_depth[lca.lca(u, v)];
    }
};

int main() {
    setIO();

    int N, M; re(N, M);

    vvpii adj(N), forest(N);

    F0R (m, M) {
        int u, v, d; re(u, v, d); --u, --v;
        adj[u].eb(v, d);
        adj[v].eb(u, d);
    }

    queue<int> leaf; vi deg(N); vb gone(N);
    F0R (i, N) {
        deg[i] = sz(adj[i]);
        if (deg[i] == 1) leaf.push(i);
    }
    while (!leaf.empty()) {
        int loc = leaf.front(); leaf.pop();
        gone[loc] = true;
        for (auto [nbr, wt] : adj[loc]) if (!gone[nbr]) {
            forest[loc].eb(nbr, wt);
            forest[nbr].eb(loc, wt);
            if (--deg[nbr] == 1) leaf.push(nbr);
        }
    }

    vi spec; int fg = -1;
    F0R (i, N) {
        if (!gone[i]) {
            if (fg == -1) fg = i;
            assert(deg[i] >= 2);
            if (deg[i] >= 3) spec.pb(i);
        }
    }
    if (!sz(spec) && fg != -1) {
        spec.pb(fg);
    }

    trav (e, spec) gone[e] = true;
    vi spid(N, -1); F0R (i, sz(spec)) spid[spec[i]] = i;

    vvi paths; vi pid(N, -1), pinx(N, -1);
    vi st, en; vvll pref;

    vvll dist(sz(spec), vll(sz(spec), LLONG_MAX / 2));
    trav (e, spec) {
        for (const auto [nbr, wt] : adj[e]) if (!gone[nbr]) {
            vi elts; vll sums;
            int loc = nbr; ll in = wt;
            while (!gone[loc]) {
                assert(pid[loc] == -1);
                pid[loc] = sz(paths); pinx[loc] = sz(elts); elts.pb(loc);
                sums.pb((sums.empty() ? 0 : sums.back()) + in);
                gone[loc] = true;
                for (auto [NBR, WT] : adj[loc]) if (!gone[NBR]) {
                    loc = NBR;
                    in = WT;
                    break;
                }
            }

            bool skipped = false;
            for (auto [NBR, WT] : adj[loc]) if (spid[NBR] != -1) {
                if (NBR == e) {
                    if (sz(elts) > 1 || WT != wt || skipped) {
                        // it's ok
                    } else {
                        skipped = true;
                        continue;
                    }
                }

                sums.pb(sums.back() + WT);
                ckmin(dist[spid[e]][spid[NBR]], sums.back());
                ckmin(dist[spid[NBR]][spid[e]], sums.back());
                st.pb(e);
                en.pb(NBR);
                break;
            }
            paths.pb(move(elts));
            pref.pb(move(sums));
        } else if (spid[nbr] != -1) ckmin(dist[spid[e]][spid[nbr]], ll(wt));
    }

    F0R (i, sz(spec)) dist[i][i] = 0;
    F0R (k, sz(spec)) F0R (i, sz(spec)) F0R (j, sz(spec))
        ckmin(dist[i][j], dist[i][k] + dist[k][j]);

    vi roots;
    F0R (loc, N) if (deg[loc] == 1) {
        for (auto [nbr, wt] : adj[loc]) {
            if (deg[nbr] > 1) {
                roots.pb(nbr);
            }
        }
    }
    dedup(roots);
    weighted_lowest_common_ancestor wlca(forest, roots);

    int Q; re(Q); F0R (q, Q) {
        int u, v; re(u, v); --u, --v;
        if (wlca.lca.comp[u] == wlca.lca.comp[v]) {
            ps(wlca.path_weight(u, v));
        } else {
            ll ans = 0;
            if (deg[u] == 1) {
                ans += wlca.weighted_depth[u];
                u = wlca.root[u];
                assert(deg[u] > 1);
            }
            if (deg[v] == 1) {
                ans += wlca.weighted_depth[v];
                v = wlca.root[v];
                assert(deg[v] > 1);
            }

            ll add = LLONG_MAX;
            if (pid[u] != -1 && pid[v] != -1 && pid[u] == pid[v])
                ckmin(add, abs(pref[pid[u]][pinx[u]] - pref[pid[v]][pinx[v]]));

            vector<pair<int, ll>> optu, optv;
            if (pid[u] == -1) optu.eb(u, 0);
            else optu.eb(st[pid[u]], pref[pid[u]][pinx[u]]),
                 optu.eb(en[pid[u]], pref[pid[u]].back() - pref[pid[u]][pinx[u]]);
            if (pid[v] == -1) optv.eb(v, 0);
            else optv.eb(st[pid[v]], pref[pid[v]][pinx[v]]),
                 optv.eb(en[pid[v]], pref[pid[v]].back() - pref[pid[v]][pinx[v]]);
            for (auto [ui, uc] : optu) for (auto [vi, vc] : optv)
                ckmin(add, dist[spid[ui]][spid[vi]] + uc + vc);

            ps(ans+add);
        }
    }

    return 0;
}