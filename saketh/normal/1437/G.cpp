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
using vpll = vector<pll>;
using vpdd = vector<pdd>;

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
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// trie {{{
template<char MIN_CHAR, int SIGMA> struct trie {
    struct node {
        // link: contains trie links + failure links
        // suff: link to longest proper suffix that exists in the trie
        // dict: link to longest suffix that exists in the dictionary
        // wct: number of suffixes that are words in the dictionary
        // wid: index of this node's word in the dictionary
        array<int, SIGMA> link;
        int depth, suff, dict, wct, wid;
        node(int _depth) : depth(_depth), suff(0), dict(0), wct(0), wid(-1) {
            fill(all(link), 0);
        }
        int& operator[](char c) { return link[c - MIN_CHAR]; }
        int operator[](char c) const { return link[c - MIN_CHAR]; }
    };

    vector<node> nodes;
    vi wloc, defer;
    vpii tour;

    /*
     * Builds a trie over the given word set and calculates Aho-Corasick links.
     * Runs in O(sum of word lengths).
     */
    trie() {}
    const node& operator[](int i) const { return nodes[i]; }

    trie(auto begin, auto end) : nodes({ node(0) }) {
        for (auto it = begin; it != end; it++) {
            int loc = 0;
            for (char c : *it) {
                assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
                if (!nodes[loc][c]) {
                    nodes[loc][c] = sz(nodes);
                    nodes.push_back(nodes[loc].depth + 1);
                }
                loc = nodes[loc][c];
            }
            if (!nodes[loc].wct++) {
                nodes[loc].dict = loc;
                nodes[loc].wid = int(wloc.size());
            }
            wloc.push_back(loc);
            defer.push_back(nodes[loc].wid);
        }

        vvi ch(sz(nodes));
        for (queue<int> bfs({0}); !bfs.empty(); bfs.pop()) {
            int loc = bfs.front(), fail = nodes[loc].suff;
            if (loc) ch[fail].pb(loc);
            if (!nodes[loc].dict) nodes[loc].dict = nodes[fail].dict;
            nodes[loc].wct += nodes[fail].wct;

            for (char c = MIN_CHAR; c < MIN_CHAR + SIGMA; c++) {
                int& succ = nodes[loc][c];
                if (succ) {
                    nodes[succ].suff = loc ? nodes[fail][c] : 0;
                    bfs.push(succ);
                } else succ = nodes[fail][c];
            }
        }

        int e = 0;
        tour.resz(sz(nodes));
        auto dfs = [&](auto self, int loc) -> void {
            tour[loc].first = e++;
            for (int cloc : ch[loc]) self(self, cloc);
            tour[loc].second = e;
        };
        dfs(dfs, 0);
    }

    /*
     * Computes and returns the number of appearances of each word in the dictionary
     * as a substring of the given string.
     *
     * Runs in O(length of string to be searched + number of words in the dictionary).
     */
    vi matches(const string& text) const {
        vi res(sz(wloc));
        priority_queue<pair<int, int>> found;

        int cloc = 0;
        for (char c : text) {
            cloc = nodes[cloc].link[c - MIN_CHAR];
            int match = nodes[cloc].dict;
            if (match) {
                if (!res[nodes[match].wid]++)
                    found.push({ nodes[match].depth, match });
            }
        }

        while (!found.empty()) {
            int loc = found.top().second; found.pop();
            int nxt = nodes[nodes[loc].suff].dict;
            if (nxt) {
                if (!res[nodes[nxt].wid]) found.push({ nodes[nxt].depth, nxt });
                res[nodes[nxt].wid] += res[nodes[loc].wid];
            }
        }

        for (int i = 0; i < sz(defer); i++)
            if (defer[i] != i) res[i] = res[defer[i]];
        return res;
    }

    /*
     * Computes and returns the total number of appearances of all words in the
     * dictionary as substrings of the given string.
     *
     * Runs in O(length of string to be searched).
     */
    ll search(const string& text) const {
        ll res = 0;
        int loc = 0;
        for (char c : text) {
            loc = nodes[loc].link[c - MIN_CHAR];
            res += nodes[loc].wct;
        }
        return res;
    }
};
// }}}

// tree {{{
struct edge {
    int uv; //int id;
    edge (int _uv = 0, __attribute__((unused))__monostate _ = ms) : uv(_uv) {}
    int operator()(int u) const { assert(uv); return uv ^ u; }
    __monostate& wt() const { return ms; }
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
        for (E e : nbrs[u]) {
            int v = e(u);
            if (v == par[u]) continue;
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

    E first_step(int u, int v) const {
        assert(u != v);
        if (!is_ancestor(u, v)) return t.up_edge(u);
        return *upper_bound(all(t.children[u]), v,
            [&](int v, E c) { return index(v) < index(c(u)) + t.subt_sz[c(u)]; });
    }

    int kth_ancestor(int u, int k) const {
        assert(0 <= k && k <= t.depth[u]);
        while (true) {
            int dist_to_htop = t.depth[u] - t.depth[htop(u)];
            if (k <= dist_to_htop)
                return at_index(index(u) - k);
            u = t.par[htop(u)];
            k -= dist_to_htop + 1;
        }
    }

    int kth_step(int u, int v, int k) const {
        int w = lca(u, v), d = dist(u, v);
        assert(d >= k);
        return k <= t.depth[u] - t.depth[w] ? kth_ancestor(u, k) : kth_ancestor(v, d - k);
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

// segment_tree {{{
template<typename T, typename F> struct segment_tree {
    int SZ;
    T id; F tt;
    vector<T> table;

    segment_tree() {}
    segment_tree(int SZ_, T id_, F tt_) : SZ(SZ_), id(id_), tt(tt_) {
        table.resize(2 * SZ, id);
    }
    template<typename L> void set_leaves(L create) {
        for (int i = 0; i < SZ; i++) table[SZ + i] = create(i);
        for (int i = SZ - 1; i; i--) table[i] = tt(table[2 * i], table[2 * i + 1]);
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
// }}}

int main() {
    setIO();

    int N, M;
    re(N, M);

    vs names(N); re(names);

    trie<'a', 26> ie(all(names));

    int V = sz(ie.nodes);

    tree<edge> ee(V, 0);
    FOR (i, 1, V) {
        int p = ie.nodes[i].suff;
        ee.add_edge(p, i);
    }
    ee.init();
    heavy_path_decomposition<edge> hld(ee);

    auto bigger = [](int a, int b) { return max(a, b); };
    segment_tree<int, decltype(bigger)> st(V, -1, bigger);

    vi SUSP(N);
    vector<priority_queue<pii>> susp(V);
    F0R (i, N) susp[ie.wloc[i]].push({ 0, i });

    F0R (i, N) st.replace(hld.index(ie.wloc[i]).i, 0);

    auto anc_max = [&](int node) {
        return hld.accumulate_commutative(0, node, true, -1, bigger,
                [&](index_t i, index_t j) { return st(i.i, j.i); });
    };

    F0R (m, M) {
        int t; re(t);
        if (t == 1) {
            int i, x; re(i, x); --i;
            SUSP[i] = x;

            int node = ie.wloc[i];
            susp[node].push({ SUSP[i], i });

            while (SUSP[susp[node].top().s] != susp[node].top().f)
                susp[node].pop();

            st.replace(hld.index(node).i, susp[node].top().f);
        } else if (t == 2) {
            string q; re(q);
            int loc = 0, ans = -1;
            trav (c, q) {
                loc = ie[loc][c];
                ckmax(ans, anc_max(loc));
            }
            ps(ans);
        } else assert(false);
    }

    return 0;
}