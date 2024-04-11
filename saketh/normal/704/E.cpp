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
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// frac {{{
struct frac {
    ll n, d;
    frac(ll _n, ll _d = 1) : n(_n), d(_d) {
        assert(n != 0 || d != 0);
        if (d < 0) { n *= -1; d *= -1; }
        ll g = __gcd(abs(n), d);
        n /= g;
        d /= g;
    }
    explicit operator double() const { return double(n)/d; }
    friend ostream& operator << (ostream& o, const frac& f) {
        return o << f.n << "/" << f.d;
    }

    friend bool operator < (const frac& a, const frac& b) {
        return a.n * b.d < b.n * a.d;
    }
    friend bool operator <= (const frac& a, const frac& b) {
        return a.n * b.d <= b.n * a.d;
    }
    friend bool operator == (const frac& a, const frac& b) {
        return a.n * b.d == b.n * a.d;
    }
    friend bool operator != (const frac& a, const frac& b) {
        return a.n * b.d != b.n * a.d;
    }
    friend bool operator >= (const frac& a, const frac& b) {
        return a.n * b.d >= b.n * a.d;
    }
    friend bool operator > (const frac& a, const frac& b) {
        return a.n * b.d > b.n * a.d;
    }

    friend frac min(const frac a, const frac b) { return a <= b ? a : b; }
    friend frac max(const frac a, const frac b) { return a >= b ? a : b; }

    frac& operator += (const frac& b) { return *this = frac(n*b.d+b.n*d, d*b.d); }
    frac& operator -= (const frac& b) { return *this = frac(n*b.d-b.n*d, d*b.d); }
    frac& operator *= (const frac& b) { return *this = frac(n*b.n, d*b.d); }
    frac& operator /= (const frac& b) { return *this = frac(n*b.d, d*b.n); }
    friend frac operator + (const frac& a, const frac& b) { return frac(a) += b; }
    friend frac operator - (const frac& a, const frac& b) { return frac(a) -= b; }
    friend frac operator * (const frac& a, const frac& b) { return frac(a) *= b; }
    friend frac operator / (const frac& a, const frac& b) { return frac(a) /= b; }

    // canonical continued fraction
    vll to_cont() const {
        if (d == 0) return { LLONG_MAX };
        vll cont;
        for (ll n = this->n, d = this->d; ; swap(n, d)) {
            ll f = (n >= 0 ? n : n - d + 1) / d;
            cont.push_back(f);
            n -= f * d;
            if (n == 0) break;
        }
        return cont;
    }

    static frac from_cont(const vll& cont) {
        ll n = 1, d = 0;
        for (int i = int(cont.size()) - 1; i >= 0; i--) {
            swap(n, d);
            n += d * cont[i];
        }
        return { n, d };
    }

    // "best" fraction in (x, y): minimizes both n and d
    friend frac best_in(const frac x, const frac y) {
        assert(x < y);

        vll x1 = x.to_cont(), y1 = y.to_cont();
        vll x2 = x1; x2.back()--; x2.push_back(1);
        vll y2 = y1; y2.back()--; y2.push_back(1);

        auto z = [](const vll& a, const vll& b) {
            vll c;
            for (int i = 0; ; i++) {
                ll ai = i < a.size() ? a[i] : LLONG_MAX;
                ll bi = i < b.size() ? b[i] : LLONG_MAX;
                if (ai != bi) {
                    c.push_back(min(ai, bi) + 1);
                    return from_cont(c);
                }
                c.push_back(ai);
            }
        };

        frac ans = { 1, 0 };
        for (const frac f : {z(x1, y1), z(x1, y2), z(x2, y1), z(x2, y2)}) {
            if (x < f && f < y && (ans.d == 0 || f.d < ans.d))
                ans = f;
        }
        return ans;
    }
};
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
        trav (e, adj[v]) {
            int u = e[v];
            if (erased[u] || u == p) continue;
            calc_subt_sz(u, v);
            subt_sz[v] += subt_sz[u];
        }
    }

    int centroid(int v) {
        calc_subt_sz(v);
        int c = v;
        FIND: trav (e, adj[c]) {
            int u = e[c];
            if (!erased[u] && subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[v]) {
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
        _par.resz(t.V,-1), _depth.resz(t.V), _subt_sz.resz(t.V), first_visit.resz(t.V);
        auto dfs = [&](auto& self, int loc) -> void {
            _subt_sz[loc] = 1;
            first_visit[loc] = sz(euler_tour);
            euler_tour.pb({loc, _depth[loc], sz(euler_tour)});

            for (int nbr : this->nbrs(loc)) if (nbr != this->par(loc)) {
                _par[nbr] = loc;
                _depth[nbr] = this->depth(loc) + 1;
                self(self, nbr);
                _subt_sz[loc] += this->subt_sz(nbr);
                euler_tour.push_back({loc, this->depth(loc), sz(euler_tour)});
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
        return w != -1 && dist(u, v) == (dist(u, w) + dist(w, v));
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
struct index_t {
    int i; explicit operator int() { return i; }
    friend bool operator < (const index_t& a, const index_t& b) { return a.i < b.i; }
    friend bool operator > (const index_t& a, const index_t& b) { return a.i > b.i; }
    index_t operator + (int b) { return {i+b}; }
    index_t operator - (int b) { return {i-b}; }
    int operator - (index_t b) { return i-b.i; }
    friend ostream& operator << (ostream& o, index_t a) { o << a.i; return o; }
};
using range_t = pair<index_t, index_t>;
using ranges = vector<range_t>;
template<typename E> struct heavy_path_decomposition : lowest_common_ancestor<E> {
    /* Any node identifier represented as a plain int indexes into the original tree's labeling.
     * Any node identifier represented as an index_t indexes into the decomposition's relabeling.*/
    struct heavy_path { index_t index; int htop, hbot; };
    vector<heavy_path> hld;
    vi preorder;

    int par(int v) const { return this->_par[v]; }
    int depth(int v) const { return this->_depth[v]; }
    int subt_sz(int v) const { return this->_subt_sz[v]; }

    heavy_path_decomposition() {}
    heavy_path_decomposition(tree<E> _t) : lowest_common_ancestor<E>(_t) {
        hld.resz(this->t.V), preorder.resz(this->t.V);
        auto dfs = [&](auto& self, int loc, index_t index, int htop) -> index_t {
            hld[loc] = {index, htop, -1};
            preorder[index.i++] = loc;
            const vi& nbrs = this->nbrs(loc);
            vi::const_iterator it = max_element(all(nbrs), [&](int u, int v) {
                if (u == v) return false;
                if (u == this->par(loc)) return true;
                if (v == this->par(loc)) return false;
                return this->subt_sz(u) < this->subt_sz(v);
            });
            if (it != nbrs.end() && *it != this->par(loc)) {
                index = self(self, *it, index, htop);
            } else {
                hld[htop].hbot = loc;
            }
            for (int nbr : nbrs) if (nbr != this->par(loc) && nbr != *it) {
                index = self(self, nbr, index, nbr);
            }
            return index;
        };
        dfs(dfs, 0, index_t{0}, 0);
    }

    index_t index(int v) const { return hld[v].index; }
    int at_index(index_t i) const { return preorder[int(i)]; }
    int htop(int v) const { return hld[v].htop; }
    int hbot(int v) const { return hld[htop(v)].hbot; }

    range_t hpath(int v) const {
        return make_pair(index(htop(v)), index(hbot(v)) + 1);
    }
    range_t subtree(int v) const {
        return {index(v), index(v) + subt_sz(v)};
    }

    // Returns the index of the deeper incident vertex.
    index_t edge_index(int eid) const {
        const E& e = this->t.edges[eid];
        return index(depth(e.u) > depth(e.v) ? e.u : e.v);
    }

    // Returns a closed, oriented interval of indices denoting the
    // intersection between the semi-open range r and the path from u to v.
    static constexpr range_t EMPTY{index_t{-1}, index_t{-1}};
    range_t intersect(range_t r, int u, int v) {
        int ru = at_index(r.f), rv = at_index(r.s - 1), uvl = this->lca(u, v);
        assert(r.f < r.s && htop(ru) == htop(rv));
        if (depth(rv) < depth(uvl)) return EMPTY;
        if (depth(ru) < depth(uvl)) { assert(htop(uvl) == htop(ru)); ru = uvl; }
        if (!this->uv_path_has_w(u, rv, ru)) return {index(this->lca(u, rv)), index(ru)};
        if (!this->uv_path_has_w(v, rv, ru)) return {index(ru), index(this->lca(v, rv))};
        return this->uv_path_has_w(u, v, ru) ? range_t{index(ru),index(ru)} : EMPTY;
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

    void decompose_vertical_path(int u, int v, bool up, ranges& res) const {
        size_t bef = res.size();
        for (assert(depth(u) >= depth(v)); true; u = par(u)) {
            int w = depth(htop(u)) >= depth(v) ? htop(u) : v;
            res.emplace_back(index(up ? u : w), index(up ? w : u));
            if ((u = w) == v) break;
        }
        if (!up) reverse(res.begin() + bef, res.end());
    }

    ranges decompose_path(int u, int v, bool include_lca) const {
        ranges res;
        int w = this->lca(u, v);
        bool give_u_lca = include_lca && u!=w && htop(w) == htop(this->first_step(w, u)),
             give_v_lca = include_lca ^ give_u_lca;
        if (u != w || give_u_lca)
            decompose_vertical_path(u, give_u_lca ? w : this->first_step(w, u), true, res);
        if (v != w || give_v_lca)
            decompose_vertical_path(v, give_v_lca ? w : this->first_step(w, v), false, res);
        return res;
    }

    template<typename FOR, typename FORd>
    void for_each(int u, int v, bool include_lca, FOR f, FORd fd) const {
        for (range_t r : decompose_path(u, v, include_lca)) {
            if (r.f > r.s) fd(r.s, r.f + 1);
            else f(r.f, r.s + 1);
        }
    }
    template<typename FOR>
    void for_each_down(int u, int v, bool include_lca, FOR f) const {
        assert(this->lca(u, v) == u);
        auto fd = [&f](index_t i, index_t j){ assert(j - i <= 1); return f(i, j); };
        for_each(u, v, include_lca, f, /*unused*/fd);
    }
    template<typename FORd>
    void for_each_up(int u, int v, bool include_lca, FORd fd) const {
        assert(this->lca(u, v) == v);
        auto f = [&fd](index_t i, index_t j){ assert(j - i <= 1); return fd(i, j); };
        for_each(u, v, include_lca, /*unused*/f, fd);
    }
    template<typename FOR>
    void for_each_commutative(int u, int v, bool include_lca, FOR f) const {
        for_each(u, v, include_lca, f, f);
    }

    template<typename T, typename OP, typename FOLDL, typename FOLDR>
    T accumulate(int u, int v, bool include_lca, T iv, OP lplus, FOLDL fl, FOLDR fr) const {
        for (range_t r : decompose_path(u, v, include_lca)) {
            if (r.f > r.s) iv = lplus(iv, fr(r.s, r.f + 1));
            else iv = lplus(iv, fl(r.f, r.s + 1));
        }
        return iv;
    }
    template<typename T, typename OP, typename FOLDL>
    T accumulate_down(int u, int v, bool include_lca, T iv, OP lplus, FOLDL fl) const {
        assert(this->lca(u, v) == u);
        auto fr = [&fl](index_t i, index_t j){ assert(j - i <= 1); return fl(i, j); };
        return accumulate(u, v, include_lca, iv, lplus, fl, fr);
    }
    template<typename T, typename OP, typename FOLDR>
    T accumulate_up(int u, int v, bool include_lca, T iv, OP lplus, FOLDR fr) const {
        assert(this->lca(u, v) == v);
        auto fl = [&fr](index_t i, index_t j){ assert(j - i <= 1); return fr(i, j); };
        return accumulate(u, v, include_lca, iv, lplus, fl, fr);
    }
    template<typename T, typename OP, typename FOLD>
    T accumulate_commutative(int u, int v, bool include_lca, T iv, OP lplus, FOLD f) const {
        return accumulate(u, v, include_lca, iv, lplus, f, f);
    }

    ranges decompose_subtree(int u, int r) const {
        if (u == r) return {{index_t{0}, index_t{this->t.V}}};
        int w = this->first_step(u, r);
        if (w == par(u)) return {{index(u), index(u) + subt_sz(u)}};
        return {{index_t{0}, index(w)}, {index(w) + subt_sz(w), index_t{this->t.V}}};
    }
    template<typename T, typename OP, typename FOLD>
    T accumulate_subtree(int u, int r, T iv, OP lplus, FOLD f) const {
        ranges st = decompose_subtree(u, r);
        return std::accumulate(all(st), iv, [&](T v, pii p){ return lplus(v, f(p.f, p.s)); });
    }
};
// }}}

frac inf = { 20001, 1 };

struct suit {
    int u, v, c; frac tu, tv;
    frac loc(frac t) const {
        return u + c * (t - tu);
    }
    friend frac hit(const suit& a, const suit& b) {
        frac t0 = max(a.tu, b.tu), t1 = min(a.tv, b.tv);
        if (t0 > t1) return inf;

        frac a0 = a.loc(t0), a1 = a.loc(t1),
             b0 = b.loc(t0), b1 = b.loc(t1);

        if (a0 == b0) return t0;
        if ((a0 < b0 && a1 >= b1) || (a0 > b0 && a1 <= b1))
            return t0 + (b0 - a0) / (a.c - b.c);
        return inf;
    }
    friend ostream& operator<<(ostream& o, const suit& s) {
        o << "{" << s.u << "(" << s.tu << ") =" << s.c
            << "=> " << s.v << "(" << s.tv << ")";
        return o;
    }
};

int main() {
    setIO();

    using E = wedge<>;
    int N, M; re(N, M); tree<E> tr(N); re(tr);
    heavy_path_decomposition<E> hld(tr);

    vector<vector<suit>> lines(N);
    F0R (m, M) {
        int t, c, u, v; re(t, c, u, v); --v, --u;
        //pd("!-----", t, c, u, v);
        ranges htops;
        hld.for_each(u, v, true, [&](index_t i, index_t j) { htops.eb(i, j-1); },
                                 [&](index_t i, index_t j) { htops.eb(j-1, i); });
        trav (r, htops) {
            int ht = hld.htop(hld.at_index(r.f));
            //pd(r, hld.intersect(hld.hpath(ht), u, v));
            suit s {
                int(r.f - hld.index(ht)),
                int(r.s - hld.index(ht)),
                c,
                t + frac{ hld.dist(u, hld.at_index(r.f)), c },
                t + frac{ hld.dist(u, hld.at_index(r.s)), c }
            };
            int ext = hld.par(hld.at_index(min(r.f, r.s)));
            if (hld.uv_path_has_w(u, v, ext)) {
                frac et = t + frac{ hld.dist(u, ext), c };
                int loc = hld.depth(ext) - hld.depth(ht);
                if (et < s.tu) { s.tu = et; s.u = loc; }
                else { s.tv = et; s.v = loc; }
            }
            if (s.u > s.v) s.c *= -1;
            //pd(s);
            lines[ht].pb(s);
        }
    }

    frac ans = inf;
    trav (line, lines) {
        vi ev(2 * sz(line));
        F0R (i, sz(ev)) ev[i] = i;

        sort(all(ev), [&](int a, int b) {
            frac ta = a&1 ? line[a/2].tv : line[a/2].tu;
            frac tb = b&1 ? line[b/2].tv : line[b/2].tu;
            if (ta != tb) return ta < tb;
            return (a&1) < (b&1);
        });

        frac t = 0;
        auto cmp = [&](int i, int j) {
            frac il = line[i].loc(t), jl = line[j].loc(t);
            return il != jl ? il < jl : line[i].u < line[j].u;
        };
        set<int, decltype(cmp)> active(cmp);

        trav (ei, ev) {
            const suit& s = line[ei/2];
            t = ei&1 ? s.tv : s.tu;
            if (t >= ans) break;
            if (ei&1) { // removal
                auto it = active.find(ei/2);
                assert(it != active.end());
                active.erase(it++);
                if (it != active.end() && it != active.begin())
                    ckmin(ans, hit(line[*it], line[*prev(it)]));
            } else { // insertion
                auto it = active.lb(ei/2);
                if (it != active.end()) ckmin(ans, hit(s, line[*it]));
                if (it != active.begin()) ckmin(ans, hit(s, line[*prev(it)]));
                if (t >= ans) break;
                active.insert(it, ei/2);
            }
        }
    }
    if (ans != inf) ps(double(ans)); else ps(-1);

    // did you check n=1?
    return 0;
}