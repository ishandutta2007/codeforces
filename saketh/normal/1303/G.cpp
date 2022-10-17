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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct monostate {
    friend istream& operator>>(istream& is, const monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const monostate& ms) { return os; }
    friend monostate operator+(const monostate& a, const monostate& b) { return a; }
} ms;
#pragma GCC diagnostic pop

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
    int uv; //int id;
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
    struct path { int len; W wt;
        path operator+(const path& p) { return {len+p.len, wt+p.wt}; }
    }; explicit operator path() { return {1, w}; }
};

enum INPUT_FORMAT { EDGE_LIST, PARENT_LIST };
template<typename E> struct tree {
    int V, root;
    vector<vector<E>> nbrs, children;

    vi par, depth, subt_sz;
    vi preorder, reverse_preorder;

    tree() : V(0), root(-1) {}
    tree(int _V, int _root) : V(_V), root(_root), nbrs(V) {}

    const E& up_edge(int u) const {
        assert(u != root);
        return nbrs[u].front();
    }

    void add_edge(int u, int v, E e = {}) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        e.uv = u ^ v;
        nbrs[u].pb(e);
        nbrs[v].pb(e);
    }

    template<INPUT_FORMAT FMT = EDGE_LIST, bool FIRST_INDEX = 1>
    friend void re(tree& t) {
        assert(t.V > 0);
        for (int i = 0; i < t.V - 1; i++) {
            int u, v;
            re(u), u -= FIRST_INDEX;
            if (FMT == PARENT_LIST) v = i+1;
            else re(v), v -= FIRST_INDEX;
            E e{}; re(e.wt()); // e.id = i
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void init() {
        children.resz(V), par.resz(V), depth.resz(V), subt_sz.resz(V);
        par[root] = -1, depth[root] = 0;

        traverse(root);
        for (int u = 0; u < V; u++) {
            sort_by(nbrs[u], subt_sz[a(u)] > subt_sz[b(u)]);
            children[u].clear();
            copy(nbrs[u].begin() + (u != root), nbrs[u].end(), back_inserter(children[u]));
        }

        preorder.clear(), preorder.reserve(V), build_preorder(root);
        reverse_preorder = preorder, reverse(all(reverse_preorder));
    }
    void reroot(int _root) { root = _root; init(); }

    void traverse(int u) {
        subt_sz[u] = 1;
        for (E e : nbrs[u]) if (int v = e(u); v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            subt_sz[u] += subt_sz[v];
        }
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

// line_container {{{
template<typename T> struct line {
    T a, b;
    bool q;
    mutable T l;
    T eval(T x) const { return a * x + b; }

    bool operator < (const line& o) const {
        return (q || o.q) ? l < o.l : a < o.a;
    }

    static constexpr T inf = numeric_limits<T>::has_infinity ?
        numeric_limits<T>::infinity() : numeric_limits<T>::max();

    template<typename _T = T> static
    typename enable_if<is_integral<_T>::value, _T>::type div(const _T a, const _T b) {
        return a / b - ((a ^ b) < 0 && (a % b));
    }
    template<typename _T = T> static
    typename enable_if<!is_integral<_T>::value, _T>::type div(const _T a, const _T b) {
        return a / b;
    }

    T boundary(const line<T>& o) const {
        if (a == o.a) return b > o.b ? inf : -inf;
        return div(o.b - b, a - o.a);
    }
};

/*
 * insert_line(a, b): inserts the line f(x) = a * x + b
 * maximum(x0): returns the maximum value at x0 among all inserted lines
 */
template<typename T> struct line_container : multiset<line<T>> {
    bool set_boundary(auto x, auto y) {
        if (y == this->end()) { x->l = line<T>::inf; return false; }
        return (x->l = x->boundary(*y)) >= y->l;
    }

    bool covered(auto y) {
        return y != this->begin() && set_boundary(prev(y), y);
    }

    // amortized log(container size)
    void insert_line(T a, T b) {
        auto it = this->insert({ a, b, false });
        while (set_boundary(it, next(it))) this->erase(next(it));
        if (covered(it)) set_boundary(prev(it), it = this->erase(it));
        while (it != this->begin() && covered(prev(it))) {
            this->erase(prev(it));
            set_boundary(prev(it), it);
        }
    }

    // worst case log(container size)
    T maximum(T x0) {
        assert(!this->empty());
        return this->lower_bound({ 0, 0, true, x0 })->eval(x0);
    }
};

/*
 * Better performance constant for when all lines are inserted before all queries.
 */
template<typename T> struct line_container_static {
    vector<line<T>> hull;

    line_container_static() {}
    line_container_static(auto begin, auto end) {
        vector<line<T>> lines(begin, end);
        sort(all(lines));
        for (auto elt : lines) {
            while (hull.size() >= 2 && (hull.end() - 2)->l >= (hull.end() - 2)->boundary(elt))
                hull.pop_back();
            if (hull.size()) hull.back().l = hull.back().boundary(elt);
            hull.push_back({ elt.a, elt.b, false, line<T>::inf });
        }
    }

    // binary search in log(container size)
    T maximum(T x0) const {
        return lower_bound(all(hull), line<T>({ 0, 0, true, x0 }))->eval(x0);
    }
};
// }}}

// centroid_decomposition {{{
template<typename E, int MAXV, bool PREORDER>
struct centroid_decomposition {
    static const int L = 33 - __builtin_clz(MAXV - 1);

    const tree<E>& t;
    using P = typename E::path;
    struct visit { int node; E in; };
    vi layer;                        // 0-indexed depth in the centroid tree
    vpii par;                        // {parent, index among parent's children}
    vi child_ct;                     // number of children
    vector<array<P, L>> anc_path;    // paths to ancestors, by layer
    vector<vector<visit>> preorder;  // preorder traversals recording {node, incoming edge}
    vvi ch_sz;                       // child tree sizes in traversal order

    centroid_decomposition(const tree<E>& _t) : t(_t),
            layer(t.V, -1), par(t.V), child_ct(t.V), anc_path(t.V) {
        assert(t.V <= MAXV);
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
    void traverse(int u, E in) {
        if (PREORDER) preorder[rt].pb({u, in});
        subt_sz[u] = 1;
        for (E e : t.nbrs[u]) if (int v = e(u); v != in(u) && layer[v] == -1) {
            anc_path[v][ly] = anc_path[u][ly] + P(e);
            traverse(v, e);
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
            rt = r, anc_path[u][ly] = P(e), traverse(u, e);
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

int main() {
    setIO();

    int N; re(N); tree<edge> tr(N, 0); re(tr);
    vi node_wt(N); re(node_wt);

    centroid_decomposition<edge, int(1.51e5), 1> cd(tr);

    vi depth(N);
    vll simple_sum(N);
    vll path_sum(N);
    vll rev_path_sum(N);

    ll ans = *max_element(all(node_wt));

    F0R (cen, N) {
        depth[cen] = 0;
        simple_sum[cen] = node_wt[cen];
        path_sum[cen] = node_wt[cen];
        rev_path_sum[cen] = node_wt[cen];

        int done = 1;
        line_container<ll> pref, suff;
        pref.insert_line(1, node_wt[cen]); // just root as prefix
        suff.insert_line(node_wt[cen], node_wt[cen]); // just root as suffix

        trav (ssz, cd.ch_sz[cen]) {
            vpll ins_pre, ins_suf;

            FOR (inx, done, done + ssz) {
                auto [node, in_edge] = cd.preorder[cen][inx];
                int par = in_edge(node);

                depth[node] = depth[par] + 1;
                simple_sum[node] = simple_sum[par] + node_wt[node];
                path_sum[node] = path_sum[par] + node_wt[node] * ll(depth[node] + 1);
                rev_path_sum[node] = rev_path_sum[par] + simple_sum[node];

                // this path as prefix (no root)
                ckmax(ans, rev_path_sum[node] - node_wt[cen] * ll(depth[node] + 1)
                        + suff.maximum(depth[node]));

                // this path as suffix (no root)
                ckmax(ans, path_sum[node] - simple_sum[node]
                        + pref.maximum(simple_sum[node] - node_wt[cen]));

                // this path as future prefix (w/ root)
                ins_pre.eb(depth[node] + 1, rev_path_sum[node]);

                // this path as future suffix (w/ root)
                ins_suf.eb(simple_sum[node], path_sum[node]);
            }

            done += ssz;

            for (auto [a, b] : ins_pre) pref.insert_line(a, b);
            for (auto [a, b] : ins_suf) suff.insert_line(a, b);
        }
    }

    ps(ans);

    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}