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

// sparse_table {{{
template<typename T, typename F> struct sparse_table {
    int SZ;
    F tt; // idempotent
    vector<T> table;

    T& entry(int l, int i) { return table[l * SZ + i]; }
    const T& entry(int l, int i) const { return table[l * SZ + i]; }

    sparse_table() {}
    sparse_table(const vector<T>& elts, F _tt) : SZ(sz(elts)), tt(_tt) {
        const int L = 32 - __builtin_clz(max(SZ - 1, 1));
        table.resize(L * SZ);
        copy(all(elts), table.begin());

        for (int l = 0; l + 1 < L; l++) {
            for (int i = 0; i < SZ; i++) {
                entry(l + 1, i) = entry(l, i);
                if (i + (1 << l) < SZ)
                    entry(l + 1, i) = tt(entry(l + 1, i), entry(l, i + (1 << l)));
            }
        }
    }

    // Accumulates the elements at indices in [i, j) in O(1)
    T operator()(int i, int j) const {
        assert(0 <= i && i < j && j <= SZ);
        int l = j - i - 1 ? 31 - __builtin_clz(j - i - 1) : 0;
        return tt(entry(l, i), entry(l, j - (1 << l)));
    }
};
// }}}
// tree {{{
template<typename E> struct tree {
    int V;
    vvi nbrs;
    vector<E> edges;
    vector<vector<E>> adj;

    vi subt_sz;
    vb erased;

    tree() {}
    tree(int _V) : V(_V) {
        edges.resz(V-1);
        nbrs.resz(V), adj.resz(V), subt_sz.resz(V), erased.resz(V);
    }
    tree(const vector<E>& __edges) : tree(sz(__edges) + 1) {
        edges = __edges;
        init();
    }

    void init() {
        F0R (i, sz(edges)) {
            auto& e = edges[i]; e.i = i;
            assert(0 <= e.u && e.u < V && 0 <= e.v && e.v < V);
            adj[e.u].pb(e), nbrs[e.u].pb(e.v);
            adj[e.v].pb(e), nbrs[e.v].pb(e.u);
        }
    }

    friend void re(tree& t) { re(t.edges); t.init(); }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edges, "}"); }

    void erase(int v) { erased[v] = true; }

    void calc_subt_sz(int v, int p = -1) {
        subt_sz[v] = 1;
        trav (e, adj[v]) if (int u = e[v]; !erased[u] && u != p) {
            calc_subt_sz(u, v);
            subt_sz[v] += subt_sz[u];
        }
    }

    int centroid(int v) {
        calc_subt_sz(v);
        int c = v;
        FIND: trav (e, adj[c]) if (int u = e[c]; !erased[u]) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[v]) {
                c = u; goto FIND;
            }
        }
        return c;
    }
};
// }}}
// lowest_common_ancestor {{{
template<typename E> struct lowest_common_ancestor {
    tree<E> t;
    int root;
    vi _par, _depth, _subt_sz;

    const vi& nbrs(int v) const { return t.nbrs[v]; }
    int par(int v) const { return _par[v]; }
    int depth(int v) const { return _depth[v]; }
    int subt_sz(int v) const { return _subt_sz[v]; }

    struct visit { int node, depth, index; };
    struct adder {
        visit operator()(const visit& a, const visit& b) const {
            if (a.depth != b.depth) return a.depth < b.depth ? a : b;
            return a.index > b.index ? a : b;
        }
    } vv;

    vector<visit> euler_tour;
    vi first_visit;
    sparse_table<visit, adder> table;

    lowest_common_ancestor() {}
    lowest_common_ancestor(tree<E> _t, int _root = 0) : t(_t), root(_root) {
        _par.resz(t.V), _depth.resz(t.V), _subt_sz.resz(t.V), first_visit.resz(t.V);
        auto dfs = [&](auto& self, int loc) -> void {
            _subt_sz[loc] = 1;
            first_visit[loc] = sz(euler_tour);
            euler_tour.pb({loc, _depth[loc], sz(euler_tour)});

            for (int nbr : nbrs(loc)) if (nbr != par(loc)) {
                _par[nbr] = loc;
                _depth[nbr] = depth(loc) + 1;
                self(self, nbr);
                _subt_sz[loc] += subt_sz(nbr);
                euler_tour.push_back({loc, depth(loc), sz(euler_tour)});
            }
        };
        dfs(dfs, root);
        table = sparse_table<visit, adder>(euler_tour, vv);
    }

    int lca(int u, int v) const {
        u = first_visit[u], v = first_visit[v];
        if (u > v) swap(u, v);
        return table(u, v + 1).node;
    }

    int dist(int u, int v) const {
        return depth(u) + depth(v) - 2 * depth(lca(u, v));
    }

    bool uv_path_has_w(int u, int v, int w) const {
        return dist(u, v) == (dist(u, w) + dist(w, v));
    }

    // Returns the neighbor of u on the simple path from u to v
    int first_step(int u, int v) const {
        assert(u != v);
        if (lca(u, v) != u) return par(u);
        return euler_tour[table(first_visit[u], first_visit[v]).index + 1].node;
    }

    template<typename T, typename F> vector<T> prefix_sums(T id, F op) {
        vector<T> res(t.V, id);
        auto dfs = [&](auto& self, int loc) -> void {
            for (int eid : t.eids[loc]) {
                E& e = t.edges[eid]; int nbr = e[loc];
                if (nbr == par(loc)) continue;
                res[nbr] = op(res[loc], e);
                self(self, nbr);
            }
        };
        dfs(dfs, root);
        return res;
    }
    template<typename T> T read_path(vector<T> prefix_sums, int u, int v) {
        return prefix_sums[u] + prefix_sums[v] - 2 * prefix_sums[lca(u, v)];
    }
};
// }}}
// heavy_path_decomposition {{{
template<typename E> struct heavy_path_decomposition : lowest_common_ancestor<E> {
    struct heavy_path { int index, htop, hbot; };
    vector<heavy_path> hld;
    vi preorder;

    int par(int v) const { return this->_par[v]; }
    int depth(int v) const { return this->_depth[v]; }
    int subt_sz(int v) const { return this->_subt_sz[v]; }

    heavy_path_decomposition() {}
    heavy_path_decomposition(tree<E> _t) : lowest_common_ancestor<E>(_t) {
        hld.resz(this->t.V), preorder.resz(this->t.V);
        auto dfs = [&](auto& self, int loc, int index, int htop) -> int {
            preorder[index] = loc;
            hld[loc] = {index++, htop, -1};
            const vi& nbrs = this->nbrs(loc);
            vi::const_iterator it = max_element(all(nbrs), [&](int u, int v) {
                if (u == v) return 0;
                return u == par(loc) ? 1 : v == par(loc) ? 0 : subt_sz(u) < subt_sz(v);
            });
            if (it != nbrs.end() && *it != par(loc)) {
                index = self(self, *it, index, htop);
            } else {
                hld[htop].hbot = loc;
            }
            for (int nbr : nbrs) if (nbr != par(loc) && nbr != *it) {
                index = self(self, nbr, index, nbr);
            }
            return index;
        };
        dfs(dfs, 0, 0, 0);
    }

    int index(int v) const { return hld[v].index; }
    int at_index(int i) const { return preorder[i]; }
    pii subtree(int v) const { return {index(v), index(v) + subt_sz(v)}; }

    int htop(int v) const { return hld[v].htop; }
    int hbot(int v) const { return hld[htop(v)].hbot; }
    pii hpath(int v) const {
        return make_pair(index(htop(v)), index(hbot(v)) + 1);
    }

    int edge_index(int eid) const {
        const E& e = this->t.edges[eid];
        return index(depth(e.u) > depth(e.v) ? e.u : e.v);
    }

    int kth_ancestor(int u, int k) const {
        assert(0 <= k && k <= depth(u));
        while (true) {
            if (k <= depth(u) - depth(htop(u)))
                return at_index(index(u) - k);
            k -= depth(u) - depth(htop(u)) + 1;
            u = par(htop(u));
        }
    }

    // Returns the kth node on the simple path from u to v
    int kth_step(int u, int v, int k) const {
        int w = this->lca(u, v), d = this->dist(u, v);
        assert(d >= k);
        return k <= depth(u) - depth(w) ? kth_ancestor(u, k) : kth_ancestor(v, d - k);
    }

    void decompose_vertical_path(int u, int v, bool up, vpii& res) const {
        size_t bef = res.size();
        for (assert(depth(u) >= depth(v)); true; u = par(u)) {
            int w = depth(htop(u)) >= depth(v) ? htop(u) : v;
            res.emplace_back(index(up ? u : w), index(up ? w : u));
            if ((u = w) == v) break;
        }
        if (!up) reverse(res.begin() + bef, res.end());
    }

    vpii decompose_path(int u, int v, bool include_lca) const {
        vpii res;
        int w = this->lca(u, v);
        if (u != w) decompose_vertical_path(u, this->first_step(w, u), true, res);
        if (include_lca) res.emplace_back(index(w), index(w));
        if (v != w) decompose_vertical_path(v, this->first_step(w, v), false, res);
        return res;
    }

    template<typename FOR, typename FORd>
    void for_each(int u, int v, bool include_lca, FOR f, FORd fd) const {
        for (pii r : decompose_path(u, v, include_lca)) {
            if (r.f > r.s) fd(r.s, r.f + 1);
            else f(r.f, r.s + 1);
        }
    }
    template<typename FOR>
    void for_each_down(int u, int v, bool include_lca, FOR f) const {
        assert(this->lca(u, v) == u);
        auto fd = [&f](int i, int j){ assert(j - i <= 1); return f(i, j); };
        for_each(u, v, include_lca, f, /*unused*/fd);
    }
    template<typename FORd>
    void for_each_up(int u, int v, bool include_lca, FORd fd) const {
        assert(this->lca(u, v) == v);
        auto f = [&fd](int i, int j){ assert(j - i <= 1); return fd(i, j); };
        for_each(u, v, include_lca, /*unused*/f, fd);
    }
    template<typename FOR>
    void for_each_commutative(int u, int v, bool include_lca, FOR f) const {
        for_each(u, v, include_lca, f, f);
    }

    template<typename T, typename OP, typename FOLDL, typename FOLDR>
    T accumulate(int u, int v, bool include_lca, T iv, OP lplus, FOLDL fl, FOLDR fr) const {
        for (pii r : decompose_path(u, v, include_lca)) {
            if (r.f > r.s) iv = lplus(iv, fr(r.s, r.f + 1));
            else iv = lplus(iv, fl(r.f, r.s + 1));
        }
        return iv;
    }
    template<typename T, typename OP, typename FOLDL>
    T accumulate_down(int u, int v, bool include_lca, T iv, OP lplus, FOLDL fl) const {
        assert(this->lca(u, v) == u);
        auto fr = [&fl](int i, int j){ assert(j - i <= 1); return fl(i, j); };
        return accumulate(u, v, include_lca, iv, lplus, fl, /*unused*/fr);
    }
    template<typename T, typename OP, typename FOLDR>
    T accumulate_up(int u, int v, bool include_lca, T iv, OP lplus, FOLDR fr) const {
        assert(this->lca(u, v) == v);
        auto fl = [&fr](int i, int j){ assert(j - i <= 1); return fr(i, j); };
        return accumulate(u, v, include_lca, iv, lplus, /*unused*/fl, fr);
    }
    template<typename T, typename OP, typename FOLD>
    T accumulate_commutative(int u, int v, bool include_lca, T iv, OP lplus, FOLD f) const {
        return accumulate(u, v, include_lca, iv, lplus, f, f);
    }

    vpii decompose_subtree(int u, int r) const {
        if (u == r) return {{0, this->t.V}};
        int w = this->first_step(u, r);
        if (w == par(u)) return {{index(u), index(u) + subt_sz(u)}};
        return {{0, index(w)}, {index(w) + subt_sz(w), this->t.V}};
    }
    template<typename T, typename OP, typename FOLD>
    T accumulate_subtree(int u, int r, T iv, OP lplus, FOLD f) const {
        vpii st = decompose_subtree(u, r);
        return std::accumulate(all(st), iv, [&](T v, pii p){ return lplus(v, f(p.f, p.s)); });
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
        F0R (i, SZ) table[SZ + i] = create(i);
        FORd (i, 1, SZ) table[i] = tt(table[2 * i], table[2 * i + 1]);
    }

    // Replaces the element at index i with v
    void replace(int i, T v) {
        table[i += SZ] = v;
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

template<typename T, typename F> struct full_segment_tree : segment_tree<T, F> {
    // Internal size is rounded up so that all layers are full
    full_segment_tree() {}
    full_segment_tree(int _SZ, T _id, F _tt) :
        segment_tree<T, F>(1 << (32 - __builtin_clz(_SZ - 1)), _id, _tt) {}

    /*
     * Returns the first i in [0, S] such that comp(this(0, i))
     * evaluates to true. Returns -1 if no such i exists.
     * Requires that comp(this(0, i)) is non-decreasing in i.
     */
    template<typename C> int lower_bound(C comp) const {
        if (!comp(this->table[1])) return -1;
        if (comp(T{})) return 0;

        int loc = 1;
        for (T cur{}; loc < this->SZ; ) {
            T mid = this->tt(cur, this->table[2 * loc]);
            if (comp(mid)) {
                loc = 2 * loc;
            } else {
                cur = mid;
                loc = 2 * loc + 1;
            }
        }
        return loc - this->SZ + 1;
    }
};
// }}}

int main() {
    setIO();

    int N, Q; re(N, Q);
    vi f(N - 1); re(f); f.insert(f.begin(), 0);

    using E = wedge<int>;
    tree<E> tr(N); re(tr);
    heavy_path_decomposition hld(tr);

    struct query { int u, v, l, i; };
    vector<query> qq(Q);
    F0R (qi, Q) {
        auto& q = qq[qi];
        re(q.u, q.v, q.l);
        --q.u, --q.v;
        q.i = qi;
    }

    sort_by(qq, a.l > b.l);
    sort_by(tr.edges, a.w > b.w);

    struct node { int f, b, l, ans; };
    auto nn = [&](node a, node b) {
        node nn{ a.f + (a.f == a.l ? b.f : 0),
                 b.b + (b.b == b.l ? a.b : 0),
                 a.l + b.l,
                 a.ans + b.ans
        };
        if (a.f < a.l && b.b < b.l) {
            nn.ans += f[a.b + b.f];
        }
        return nn;
    };
    auto NN = [&](node a, node b){ return nn(b, a); };
    segment_tree st(N, node{0,0,0,0}, nn);
    segment_tree ST(N, node{0,0,0,0}, NN);
    st.set_leaves([](int _){ return node{0,0,1,0}; });
    ST.set_leaves([](int _){ return node{0,0,1,0}; });

    vi ans(Q);
    int t = 0;
    trav (q, qq) {
        for (; t < sz(tr.edges) && tr.edges[t].w >= q.l; t++) {
            st.replace(hld.edge_index(tr.edges[t].i), node{1,1,1,0});
            ST.replace(hld.edge_index(tr.edges[t].i), node{1,1,1,0});
        }
        node qn = hld.accumulate(q.u, q.v, false, node{0,0,0,0}, nn,
                [&](int i, int j){ return st(i, j); },
                [&](int i, int j){ return ST(i, j); });
        ans[q.i] = qn.ans + f[qn.f] + (qn.f != qn.l ? f[qn.b] : 0);
    }
    pc(ans);

    return 0;
}