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

// }}}
// tree {{{
template<typename E> struct tree {
    int V;
    vvi nbrs, eids;
    vector<E> edges;

    tree() {}
    tree(int _V) : V(_V) {
        nbrs.resz(V), eids.resz(V), edges.resz(V-1);
    }
    tree(const vector<E>& __edges) : V(sz(edges) + 1), edges(__edges)  {
        nbrs.resz(V), eids.resz(V);
        init();
    }

    void init() {
        F0R (i, sz(edges)) {
            auto& e = edges[i];
            assert(0 <= e.u && e.u < V && 0 <= e.v && e.v < V);

            nbrs[e.u].pb(e.v);
            nbrs[e.v].pb(e.u);

            e.i = i;
            eids[e.u].pb(i);
            eids[e.v].pb(i);
        }
    }

    friend void re(tree& t) { re(t.edges); t.init(); }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edges, "}"); }
};
// }}}
// lowest_common_ancestor {{{
template<typename E> struct lowest_common_ancestor {
    tree<E> t;
    int root;
    vi par, depth, subt_sz;

    struct visit { int node, depth, index; };
    vector<visit> euler_tour;
    vi first_visit;
    sparse_table<visit> table;

    lowest_common_ancestor(tree<E> _t, int _root = 0) : t(_t), root(_root) {
        par.resz(t.V), depth.resz(t.V), subt_sz.resz(t.V), first_visit.resz(t.V);
        auto dfs = [&](auto& self, int loc) -> void {
            subt_sz[loc] = 1;
            first_visit[loc] = sz(euler_tour);
            euler_tour.pb({loc, depth[loc], sz(euler_tour)});

            for (int nbr : t.nbrs[loc]) if (nbr != par[loc]) {
                par[nbr] = loc;
                depth[nbr] = depth[loc] + 1;
                self(self, nbr);
                subt_sz[loc] += subt_sz[nbr];
                euler_tour.push_back({loc, depth[loc], sz(euler_tour)});
            }
        };
        dfs(dfs, root);

        table = sparse_table<visit>(euler_tour, [&](visit a, visit b) {
            if (a.depth != b.depth) return a.depth < b.depth ? a : b;
            return a.index > b.index ? a : b;
        });
    }

    int lca(int u, int v) const {
        u = first_visit[u], v = first_visit[v];
        if (u > v) swap(u, v);
        return table(u, v + 1).node;
    }

    int dist(int u, int v) const {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool uv_path_has_w(int u, int v, int w) const {
        return dist(u, v) == (dist(u, w) + dist(w, v));
    }

    // Returns the neighbor of u on the shortest path to v
    int first_step(int u, int v) const {
        assert(u != v);
        if (int w = lca(u, v); u != w) return par[u];
        return euler_tour[table(first_visit[u], first_visit[v]).index + 1].node;
    }
};
// }}}
// heavy_path_decomposition {{{
template<typename E> struct heavy_path_decomposition : lowest_common_ancestor<E> {
    struct heavy_path { int index, htop; };
    vector<heavy_path> hld;

    const vi& nbrs(int v) const { return this->t.nbrs[v]; }
    int fpar(int v) const { return this->par[v]; }
    int fdepth(int v) const { return this->depth[v]; }
    int fsubt_sz(int v) const { return this->subt_sz[v]; }

    heavy_path_decomposition(tree<E> _t) : lowest_common_ancestor<E>(_t) {
        hld.resz(this->t.V);
        auto dfs = [&](auto& self, int loc, int index, int htop) -> int {
            hld[loc] = {index++, htop};
            auto it = max_element(all(nbrs(loc)), [&](int u, int v) {
                if (u == v) return 0;
                return u == fpar(loc) ? 1 : v == fpar(loc) ? 0 : fsubt_sz(u) < fsubt_sz(v);
            });
            if (*it != fpar(loc)) {
                index = self(self, *it, index, htop);
            }
            for (int nbr : nbrs(loc)) if (nbr != fpar(loc) && nbr != *it) {
                index = self(self, nbr, index, nbr);
            }
            return index;
        };
        dfs(dfs, 0, 0, 0);
    }

    int index(int v) const { return hld[v].index; }
    int htop(int v) const { return hld[v].htop; }

    int edge_index(int eid) const {
        const E& e = this->t.edges[eid];
        return index(fdepth(e.u) > fdepth(e.v) ? e.u : e.v);
    }

    void decompose_vertical_path(int u, int v, bool up, vpii& res) const {
        size_t bef = res.size();
        for (assert(fdepth(u) >= fdepth(v)); true; u = fpar(u)) {
            int w = fdepth(htop(u)) >= fdepth(v) ? htop(u) : v;
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
    void for_each_commutative(int u, int v, bool include_lca, FOR f) const {
        for_each(u, v, include_lca, f, f);
    }

    template<typename T, typename OP, typename LFOLD, typename RFOLD>
    T accumulate(int u, int v, bool include_lca, T iv, OP op, LFOLD lf, RFOLD rf) const {
        for (pii r : decompose_path(u, v, include_lca)) {
            if (r.f > r.s) iv = op(iv, rf(r.s, r.f + 1));
            else iv = op(iv, lf(r.f, r.s + 1));
        }
        return iv;
    }
    template<typename T, typename OP, typename FOLD>
    T accumulate_commutative(int u, int v, bool include_lca, T iv, OP op, FOLD f) const {
        return accumulate(u, v, include_lca, iv, op, f, f);
    }
};
// }}}
// segment_tree {{{
template<typename T> struct segment_tree {
    using F = function<T(const T&, const T&)>;

    size_t SZ;
    T id;
    F combine;
    vector<T> table;

    segment_tree() {}
    segment_tree(size_t _SZ, T _id, F _combine) : SZ(_SZ), id(_id), combine(_combine) {
        table.resize(2 * SZ);
    }

    segment_tree(auto begin, auto end, T _id, F _combine)
        : segment_tree(distance(begin, end), _id, _combine) {
        copy(begin, end, table.begin() + SZ);
        FORd (i, 1, SZ) table[i] = combine(table[2 * i], table[2 * i + 1]);
    }

    // Replaces the element at index i with v
    void replace(int i, T v) {
        table[i += SZ] = v;
        for (i /= 2; i > 0; i /= 2) {
            table[i] = combine(table[2 * i], table[2 * i + 1]);
        }
    }

    // Accumulates the elements at indices in [i, j)
    T operator()(int i, int j) const {
        T left = id, right = id;
        for (i += SZ, j += SZ; i < j; i /= 2, j /= 2) {
            if (i&1) left = combine(left, table[i++]);
            if (j&1) right = combine(table[--j], right);
        }
        return combine(left, right);
    }
    const T& operator[](int i) const { return table[SZ + i]; }
};
// }}}

// tarjan {{{
tuple<int, vi> strongly_connected_components(const vvi& graph) {
    const int N = sz(graph);
    int C = 0, V = 0, top = 0;
    vi comp(N, -1), inx(N, -1), stack(N + 1, -1);

    auto tarjan = [&](auto&& self, int loc) -> int {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int nbr : graph[loc]) {
            if (inx[nbr] == -1) low = min(low, self(self, nbr));
            else if (comp[nbr] == -1) low = min(low, inx[nbr]);
        }
        if (low == inx[loc]) {
            while (stack[top] != loc)
                comp[stack[--top]] = C;
            C++;
        }
        return low;
    };

    for (int i = 0; i < N; i++) {
        if (inx[i] == -1)
            tarjan(tarjan, i);
    }
    return { C, comp };
}
// }}}
// two_sat {{{
struct two_sat {
    vvi graph;
    two_sat() {}

    int new_var() {
        graph.pb({});
        graph.pb({});
        return sz(graph) - 1;
    }

    void implies(int a, int b) {
        if (a < 0 || b < 0) return;
        graph[a].pb(b);
        graph[b^1].pb(a^1);
    }

    template<typename F> int nullable(int a, int b, F op) {
        return a < 0 ? b : b < 0 ? a : op(a, b);
    }

    int make_and(int a, int b) {
        return nullable(a, b, [&](int _a, int _b){
            int v = new_var();
            implies(v, _a);
            implies(v, _b);
            return v;
        });
    }

    int make_or(int a, int b) {
        return nullable(a, b, [&](int _a, int _b){
            int v = new_var();
            implies(_a, v);
            implies(_b, v);
            return v;
        });
    }

    // adds constraint that at most one of a or b can be true.
    int make_at_most_one(int a, int b) {
        return nullable(a, b, [&](int _a, int _b) {
            implies(_a, _b^1); // contrapositive is automatic
            return make_or(_a, _b);
        });
    }

    vb solve() {
        int C; vi comp; tie(C, comp) = strongly_connected_components(graph);
        vb res(sz(graph));
        for (int v = 0; v < sz(res); v++) {
            if (comp[v] == comp[v^1]) return {};
            res[v] = comp[v] > comp[v^1];
        }
        return res;
    }
};
// }}}

int main() {
    setIO();

    using edge = wedge<>;

    int N; re(N); tree<edge> tr(N); re(tr);
    heavy_path_decomposition hl(tr);

    int M; re(M);
    vi seg(2 * N, -1), ants(M);
    two_sat ts;

    F0R (i, M) {
        ants[i] = ts.new_var();
        F0R (j, 2) {
            int u, v; re(u, v); --u, --v;
            hl.for_each_commutative(u, v, false, [&](int l, int r) {
                for (l += N, r += N; l < r; l /= 2, r /= 2) {
                    if (l&1) { seg[l] = ts.make_at_most_one(seg[l], ants[i]^j); l++; }
                    if (r&1) { r--; seg[r] = ts.make_at_most_one(seg[r], ants[i]^j); }
                }
            });
        }
    }

    FORd (i, 1, N) seg[i] = ts.make_at_most_one(seg[i], ts.make_or(seg[2*i], seg[2*i+1]));

    vb res = ts.solve();
    if (!sz(res)) { ps("NO"); return 0; }
    ps("YES");
    F0R (i, M) ps(1 + res[ants[i]]);

    return 0;
}