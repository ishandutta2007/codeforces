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
        ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
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
};
template<typename W> struct wedge : edge {
    W w;
    wedge (int _uv = 0, W _w = {}) : edge(_uv), w(_w) {}
    W  wt() const { return w; }
    W& wt()       { return w; }
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
// heavy_path_decomposition {{{
struct index_t {
    int i; explicit operator int() { return i; }
    friend bool operator  < (const index_t& a, const index_t& b) { return a.i  < b.i; }
    friend bool operator <= (const index_t& a, const index_t& b) { return a.i <= b.i; }
    friend bool operator  > (const index_t& a, const index_t& b) { return a.i  > b.i; }
    index_t operator + (int b) { return {i+b}; }
    index_t operator - (int b) { return {i-b}; }
    int operator - (index_t b) { return i-b.i; }
    friend ostream& operator << (ostream& o, index_t a) { o << a.i; return o; }
};
using range_t = pair<index_t, index_t>;
using ranges = vector<range_t>;
template<typename E> struct heavy_path_decomposition {
    const tree<E>& t;
    /* Any node identifier represented as a plain int indexes into the original tree's labeling.
     * Any node identifier represented as an index_t indexes into the decomposition's relabeling.*/
    struct heavy_path { index_t index; int htop; };
    vector<heavy_path> hld;

    heavy_path_decomposition() {}
    heavy_path_decomposition(const tree<E>& _t) : t(_t), hld(t.V) {
        for (int i = 0; i < t.V; i++) {
            int u = t.preorder[i];
            hld[u] = {
                index_t{i},
                i > 0 && t.preorder[i-1] == t.par[u] ? hld[t.par[u]].htop : u
            };
        }
    }

    index_t index(int v) const { return hld[v].index; }
    int at_index(index_t i) const { return t.preorder[int(i)]; }
    int htop(int v) const { return hld[v].htop; }

    int lca(int u, int v) const {
        while (htop(u) != htop(v)) {
            int& jump = index(htop(u)) > index(htop(v)) ? u : v;
            jump = t.par[htop(jump)];
        }
        return t.depth[u] < t.depth[v] ? u : v;
    }

    int dist(int u, int v) const {
        return t.depth[u] + t.depth[v] - 2 * t.depth[lca(u, v)];
    }

    bool uv_path_has_w(int u, int v, int w) const {
        return w != -1 && dist(u, v) == (dist(u, w) + dist(w, v));
    }

    bool is_ancestor(int anc, int desc) const {
        return index(anc) <= index(desc) && index(desc) < index(anc) + t.subt_sz[anc];
    }

    int first_step(int u, int v) const {
        assert(u != v);
        if (!is_ancestor(u, v)) return t.par[u];
        return *upper_bound(all(t.children[u]), v,
            [&](int v, int c) { return index(v) < index(c) + t.subt_sz[c]; });
    }

    mutable int path_lca;
    mutable ranges path_up, path_down;
    void decompose_path(int u, int v, bool include_lca) const {
        path_up.clear(), path_down.clear();
        while (htop(u) != htop(v)) {
            int& jump = index(htop(u)) > index(htop(v)) ? u : v;
            (jump == u ? path_up : path_down).eb(index(htop(jump)), index(jump) + 1);
            jump = t.par[htop(jump)];
        }
        path_lca = t.depth[u] < t.depth[v] ? u : v;
        if (u != v || include_lca) {
            (u != path_lca ? path_up : path_down).eb(
                    index(path_lca) + !include_lca, index(path_lca^u^v) + 1);
        }
        reverse(all(path_down));
    }

    template<typename FOR, typename FORd>
    void for_each(int u, int v, bool include_lca, const FOR& f, const FORd& fd) const {
        decompose_path(u, v, include_lca);
        for (range_t r : path_up)    f(r.f, r.s);
        for (range_t r : path_down) fd(r.f, r.s);
    }
    template<typename FOR>
    void for_each_commutative(int u, int v, bool include_lca, const FOR& f) const {
        for_each(u, v, include_lca, f, f);
    }

    template<typename T, typename OP, typename FOLDL, typename FOLDR>
    T accumulate(int u, int v, bool include_lca, T iv,
            const OP& lplus, const FOLDL& fl, const FOLDR& fr) const {
        decompose_path(u, v, include_lca);
        for (range_t r : path_up)   iv = lplus(iv, fr(r.f, r.s));
        for (range_t r : path_down) iv = lplus(iv, fl(r.f, r.s));
        return iv;
    }
    template<typename T, typename OP, typename FOLD>
    T accumulate_commutative(int u, int v, bool include_lca, T iv,
            const OP& lplus, const FOLD& f) const {
        return accumulate(u, v, include_lca, iv, lplus, f, f);
    }
};
// }}}

int main() {
    setIO();

    int V = 4;

    using E = edge;

    int Q; re(Q); vi ops(Q); re(ops);

    tree<E> tr(2 * Q + 4);

    F0R (u, 3) tr.add_edge(0, 1 + u);

    F0R (q, Q) {
        --ops[q];
        F0R (_, 2) tr.add_edge(ops[q], V++);
    }

    tr.init();

    heavy_path_decomposition<E> lca(tr);

    int diam = 0;
    int deepest = 0;

    auto intro = [&](int u) {
        if (tr.depth[u] > tr.depth[deepest]) {
            diam++;
            deepest = u;
        } else {
            ckmax(diam, lca.dist(deepest, u));
        }
    };

    F0R (u, 4) intro(u);

    F0R (q, Q) {
        intro(4 + 2 * q);
        intro(4 + 2 * q + 1);
        ps(diam);
    }

    // did you check N=1? did you mix up N,M?
    return 0;
}