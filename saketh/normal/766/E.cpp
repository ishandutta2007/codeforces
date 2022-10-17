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
    template<class T> void pr(const deque<T>& x);
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
    template<class T> void pr(const deque<T>& x) { prContain(x); }
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
    template<typename C, typename T, typename OP> vector<T> prefixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0R (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;

struct monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))monostate& ms) { return os; }
} ms;

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// tree {{{
template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    wedge<W>(int _u=-1, int _v=-1, int _i=-1, W _w = W{}) : u(_u), v(_v), i(_i), w(_w) {}
    int operator[](int loc) const { return u ^ v ^ loc; }
    friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }

    template<bool FIRST_INDEX = 1>
    friend void re(wedge& e) { re(e.u, e.v, e.w); if (FIRST_INDEX) --e.u, --e.v; }
    template<bool FIRST_INDEX = 1>
    friend void re(wedge& e, int _u) { e.u = _u; re(e.v, e.w); if (FIRST_INDEX) --e.v; }
};

enum INPUT_FORMAT { EDGE_LIST, PARENT_LIST };
template<typename E> struct tree {
    vector<E> edge_list;

    int V, root;
    vector<vector<E>> edges;

    vvi nbrs, children;
    vi par, depth, subt_sz;

    vi preorder, reverse_preorder;

    vb erased;
    void erase(int u) { erased[u] = true; }

    tree(int _V = 0) : V(_V) {}
    tree(const vector<E>& __edge_list, int _root = 0) : edge_list(__edge_list),
            V(sz(__edge_list) + 1), root(_root), edges(V),
            nbrs(V), children(V), par(V, -1), depth(V), subt_sz(V), erased(V) {
        for (E& e : edge_list) {
            assert(0 <= e.u && e.u < V && 0 <= e.v && e.v < V);
            nbrs[e.u].push_back(e.v);
            nbrs[e.v].push_back(e.u);
            edges[e.u].pb(e);
            edges[e.v].pb(e);
        }

        init(root);
        build_preorder(root);
        reverse_preorder = preorder;
        reverse(all(reverse_preorder));
    }

    void init(int u) {
        subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            init(v);
            subt_sz[u] += subt_sz[v];

            children[u].pb(v);
            if (subt_sz[v] > subt_sz[children[u].front()])
                swap(children[u].front(), children[u].back());
        }
    }

    void build_preorder(int u) {
        preorder.pb(u);
        for (int v : children[u]) build_preorder(v);
    }

    template<INPUT_FORMAT FMT = EDGE_LIST, bool FIRST_INDEX = 1>
    friend void re(tree& t) {
        assert(t.V > 0);
        vector<E> __edge_list(t.V - 1);
        for (int i = 0; i < t.V - 1; i++) {
            E& e = __edge_list[i];
            if (FMT == EDGE_LIST) re<FIRST_INDEX>(e);
            else re<FIRST_INDEX>(e, i + 1);
            e.i = i;
        }
        t = tree<E>(__edge_list);
    }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edge_list, "}"); }

    mutable vi __subt_sz;
    void __calc_subt_sz(int u, bool avoid_erased, int p) const {
        __subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != p && (!avoid_erased || !erased[v])) {
            __calc_subt_sz(v, avoid_erased, u);
            __subt_sz[u] += __subt_sz[v];
        }
    }

    vi centroids(int r = 0, bool avoid_erased = 1) const {
        if (__subt_sz.empty()) __subt_sz.resz(V);
        __calc_subt_sz(r, avoid_erased, -1);
        int c = r, p = -1;
        FIND: for (int u : nbrs[c]) if (!avoid_erased || !erased[u]) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                p = c, c = u; goto FIND;
            }
        }
        return subt_sz[c] * 2 == subt_sz[r] ? vi{c,p} : vi{c};
    }
};
// }}}
// centroid_decomposition {{{
template<typename E> struct centroid_decomposition {
    const tree<E>& t;

    vi layer;        // 1-indexed depth in the centroid tree
    vvi ch;          // children in centroid tree
    vpii par;        // {parent in centroid tree, index among its children}
    vi layer_order;  // preorder traversal of the centroid tree
    vvpii preorder;  // preorder traversals of centroid subtrees recording {node, traversal parent}
    vvi anc_dist;    // distances to ancestors in the centroid tree, by layer

    centroid_decomposition(const tree<E>& _t) : t(_t),
            layer(t.V, -1), ch(t.V), par(t.V), preorder(t.V), anc_dist(t.V), __subt_sz(t.V) {
        decompose();
        for (int u : layer_order)
            for (pii v : preorder[u])
                anc_dist[v.f].pb(1 + (~v.s ? anc_dist[v.s].back() : -1));
    }

    vi __subt_sz;
    void calc_subt_sz(int u, int p) {
        __subt_sz[u] = 1;
        for (int v : t.nbrs[u]) if (v != p && layer[v] == -1) {
            calc_subt_sz(v, u);
            __subt_sz[u] += __subt_sz[v];
        }
    }
    pii centroids(int r) {
        calc_subt_sz(r, -1);
        int c = r, p = -1;
        FIND: for (int u : t.nbrs[c]) if (layer[u] == -1) {
            if (__subt_sz[u] < __subt_sz[c] && 2 * __subt_sz[u] >= __subt_sz[r]) {
                p = c, c = u; goto FIND;
            }
        }
        return __subt_sz[c] * 2 == __subt_sz[r] ? pii{c,p} : pii{c,-1};
    }

    void calc_preorder(int u, int p, int r) {
        preorder[r].pb({u, p});
        for (int v : t.nbrs[u]) if (v != p && layer[v] == -1) {
            calc_preorder(v, u, r);
        }
    }
    int decompose(int r = 0, int p = -1, int pi = 0, int ly = 1) {
        par[r = centroids(r).f] = {p, pi};
        layer[r] = ly, layer_order.pb(r);
        calc_preorder(r, -1, r);
        for (int u : t.nbrs[r]) if (layer[u] == -1) {
            ch[r].pb(decompose(u, r, sz(ch[r]), ly + 1));
        }
        return r;
    }
};
// }}}

int main() {
    setIO();

    int N; re(N);
    vi city(N); re(city);
    using E = wedge<>; tree<E> tr(N); re(tr);
    centroid_decomposition<E> cd(tr);

    vvi path_xor(N);
    trav (u, cd.layer_order)
        trav (v, cd.preorder[u])
            path_xor[v.f].pb(city[v.f] ^ (~v.s ? path_xor[v.s].back() : 0));

    vector<array<array<int, 20>, 2>> tot(N);
    vector<vector<array<array<int, 20>, 2>>> contrib(N);
    F0R (u, N) contrib[u].resz(sz(cd.ch[u]));

    ll ans = 0;

    F0R (u, N) {
        int p = u, pi = -1;
        F0Rd (ly, cd.layer[u]) {
            F0R (b, 20) {
                bool v = (path_xor[u][ly] >> b)&1;

                tot[p][v][b] += 1;
                if (pi != -1) contrib[p][pi][v][b] += 1;

                bool pv = (city[p] >> b)&1;
                bool match = 1 ^ pv ^ v;
                int ct = tot[p][match][b] - (pi != -1 ? contrib[p][pi][match][b] : 0);
                ans += ll(ct) << b;
            }

            tie(p, pi) = cd.par[p];
        }
    }

    ps(ans);

    // did you check N=1? did you mix up N,M?
    return 0;
}