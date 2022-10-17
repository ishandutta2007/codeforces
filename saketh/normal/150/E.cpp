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
struct edge {
    int uv;
    edge (int _uv = 0, __attribute__((unused))monostate _ = ms) : uv(_uv) {}
    int operator()(int u) const { assert(uv); return uv ^ u; }
    monostate& wt() const { return ms; }
    struct path { int len;
        path operator+(const path& p) const { return {len+p.len}; }
    }; explicit operator path() { return {1}; }
};
template<typename W> struct wedge : edge {
    mutable W w;
    wedge (int _uv = 0, W _w = {}) : edge(_uv), w(_w) {}
    W& wt() const { return w; }
    struct path { int len; //W wt;
        path operator+(const path& p) { return {len+p.len/*, wt+p.wt*/}; }
    }; explicit operator path() { return {1/*, w*/}; }
};

enum INPUT_FORMAT { EDGE_LIST, PARENT_LIST };
template<typename E> struct tree {
    int V, root;
    vector<vector<E>> nbrs, children;

    vi par, depth, subt_sz;
    vi preorder, reverse_preorder;

    tree(int _V = 0, int _root = 0) : V(_V), root(_root),
        nbrs(V), children(V), par(V, -1), depth(V), subt_sz(V) {}

    void add_edge(int u, int v, E e = {}) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        e.uv = u ^ v;
        nbrs[u].pb(e);
        nbrs[v].pb(e);
    }

    template<INPUT_FORMAT FMT = EDGE_LIST, bool FIRST_INDEX = 1>
    friend void re(tree& t) {
        assert(t.V > 0);
        for (int i = 1; i < t.V; i++) {
            int u, v;
            re(u), u -= FIRST_INDEX;
            if (FMT == PARENT_LIST) v = i;
            else re(v), v -= FIRST_INDEX;
            E e{}; re(e.wt());
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void init() {
        traverse(root);
        for (int u = 0; u < V; u++)
            sort_by(nbrs[u], subt_sz[a(u)] > subt_sz[b(u)]);
        build_preorder(root);
        reverse_preorder = preorder, reverse(all(reverse_preorder));
    }

    void traverse(int u) {
        subt_sz[u] = 1;
        for (E e : nbrs[u]) if (int v = e(u); v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            children[u].pb(e);
            subt_sz[u] += subt_sz[v];
        }
        sort_by(children[u], subt_sz[a(u)] > subt_sz[b(u)]);
    }

    void build_preorder(int u) {
        preorder.pb(u);
        for (E e : children[u]) build_preorder(e(u));
    }

    friend void pr(const tree& t) {
        pr("{V=", t.V, " root=", t.root, " |");
        for (int u = 0; u < t.V; u++) {
            pr(" ", u, "--{");
            for (E e : t.children[u])
                pr("(ch=", e(u), " wt=", e.wt(), ")");
            pr("}");
        }
        pr("}");
    }
};
// }}}
// centroid_decomposition {{{
template<typename E, int MAXV, bool ANC_PATH, bool PREORDER>
struct centroid_decomposition {
    static const int L = 33 - __builtin_clz(MAXV - 1);

    const tree<E>& t;
    using P = typename E::path;
    struct visit { int node; E in; };
    vi layer;                        // 0-indexed depth in the centroid tree
    vpii par;                        // {parent, index among parent's children}
    vi child_ct;                     // number of children
    vector<array<P, L>> anc_path;    // paths to ancestors, by layer
    vector<vector<visit>> preorder;  /* preorder traversals recording {node, incoming edge}, where
                                        the edge's uv field is replaced with parent traversal index */
    vvi ch_sz;                       // child tree sizes in traversal order

    centroid_decomposition(const tree<E>& _t) : t(_t),
            layer(t.V, -1), par(t.V), child_ct(t.V) {
        assert(t.V <= MAXV);
        if (ANC_PATH) anc_path.resz(t.V);
        if (PREORDER) preorder.resz(t.V), ch_sz.resz(t.V);
        subt_sz = t.subt_sz, decompose(t.root), subt_sz.clear();
    }

    vi subt_sz;
    int centroid(int r) {
        int c = r;
        FIND: for (E e : t.nbrs[c]) if (int u = e(c); layer[u] == -1) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                c = u; goto FIND;
            }
        }
        return c;
    }

    int ly = 0, rt = 0;
    void traverse(int u, E in, int pi) {
        if (PREORDER) {
            preorder[rt].pb({u, in});
            preorder[rt].back().in.uv = pi;
            pi = sz(preorder[rt]) - 1;
        }
        subt_sz[u] = 1;
        for (E e : t.nbrs[u]) if (int v = e(u); v != in(u) && layer[v] == -1) {
            if (ANC_PATH) anc_path[v][ly] = anc_path[u][ly] + P(e);
            traverse(v, e, pi);
            subt_sz[u] += subt_sz[v];
        }
    }

    void decompose(int r = 0, int p = -1, int i = 0) {
        par[r = centroid(r)] = {p, i}, i = 0;
        layer[r] = ly;
        if (PREORDER) preorder[r] = {{r, E()}};
        subt_sz[r] = 1;
        for (E e : t.nbrs[r]) if (int u = e(r); layer[u] == -1) {
            if (PREORDER) ch_sz[r].pb(-sz(preorder[r]));
            if (ANC_PATH) anc_path[u][ly] = P(e);
            rt = r, traverse(u, e, 0);
            if (PREORDER) ch_sz[r].back() += sz(preorder[r]);
            subt_sz[r] += subt_sz[u], child_ct[r]++;
            ly++, decompose(u, r, i++), ly--;
        }
    }

    int lca(int u, int v) const {
        if (layer[u] < layer[v]) swap(u, v);
        while (layer[u] != layer[v]) u = par[u].f;
        while (u != v) u = par[u].f, v = par[v].f;
        return u;
    }

    P dist(int u, int v) const {
        int clca = lca(u, v);
        return anc_path[u][layer[clca]] + anc_path[v][layer[clca]];
    }
};
// }}}

// segment_tree {{{
template<typename T, typename F> struct segment_tree {
    int SZ;
    T id; F tt;
    vector<T> table;

    segment_tree() {}
    segment_tree(int _SZ, T _id, F _tt) : SZ(_SZ), id(_id), tt(_tt) {
        table.resize(2 * SZ, id);
    }
    template<typename L> void set_leaves(L create) {
        for (int i = 0; i < SZ; i++) table[SZ + i] = create(i);
        for (int i = SZ - 1; i; i--) table[i] = tt(table[2 * i], table[2 * i + 1]);
    }

    // Replaces the element at index i with v
    void join(int i, T v) {
        i += SZ, table[i] = tt(table[i], v);
        for (i /= 2; i > 0; i /= 2) {
            table[i] = tt(table[2 * i], table[2 * i + 1]);
        }
    }

    // Accumulates the elements at indices in [i, j)
    T operator()(int i, int j) const {
        T left = id, right = id;
        for (i += SZ, j += SZ; i < j; i /= 2, j /= 2) {
            if (i&1) left = tt(left, table[i++]);
            if (j&1) right = tt(table[--j], right);
        }
        return tt(left, right);
    }
    const T& operator[](int i) const { return table[SZ + i]; }
};
// }}}

int main() {
    setIO();

    int N, L, R; re(N, L, R); R++;
    using E = wedge<int>; tree<E> tr(N); re(tr);
    centroid_decomposition<E, int(1e5), 0, 1> cd(tr);

    struct p { int bal = INT_MIN / 2, node = -1; };
    auto pp = [](p a, p b) { return a.bal >= b.bal ? a : b; };

    segment_tree st(N, p{}, pp);
    vector<pair<int, p>> insert;

    auto clean = [&]() {
        insert.clear();
        fill(st.table.begin(), st.table.begin() + 2 * st.SZ, p{});
    };

    struct path { int bal, len; };
    vector<path> paths(N);
    vi limit(N, INT_MAX);
    auto find = [&](int med) -> pii {
        F0R (cen, N) if (med < limit[cen]) {
            st.SZ = 1;

            paths[0] = {0,0};
            FOR (i, 1, sz(cd.preorder[cen])) {
                auto [u, in] = cd.preorder[cen][i];
                paths[i] = {
                    paths[in.uv].bal + (in.wt() >= med ? 1 : -1),
                    paths[in.uv].len + 1
                };
                ckmax(st.SZ, paths[i].len + 1);
            }

            st.join(0, {0, cen});

            int t = 1;
            F0R (ci, cd.child_ct[cen]) {
                F0R (i, cd.ch_sz[cen][ci]) {
                    int u = cd.preorder[cen][t].node;
                    p pos = st(max(0, L - paths[t].len), min(max(0, R - paths[t].len), st.SZ));

                    if (paths[t].bal + pos.bal >= 0) {
                        clean();
                        return {u, pos.node};
                    }
                    insert.eb(paths[t].len, p{paths[t].bal, u});

                    t++;
                }

                trav (e, insert) st.join(e.f, e.s);
                insert.clear();
            }
            limit[cen] = med;
            clean();
        }
        return {-1,-1};
    };

    vi uniq; FOR (u, 1, N) uniq.pb(tr.nbrs[u][0].wt());
    dedup(uniq);

    pii ans = {-1, -1};
    int lo = -1, hi = sz(uniq) - 1;
    while (lo < hi) {
        int mi = (lo + 1 + hi) / 2;
        pii res = find(uniq[mi]);
        if (res.f != -1) ans = res, lo = mi;
        else hi = mi - 1;
    }
    ps(ans.f + 1, ans.s + 1);

    // did you check N=1? did you mix up N,M?
    return 0;
}