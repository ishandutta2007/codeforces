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

const int MAXV = 3001;
ll cover[MAXV][MAXV];
ll   ans[MAXV][MAXV];

int main() {
    setIO();

    using E = edge;
    int N; re(N); tree<E> tr(N, 0);

    vvi adj(N);
    F0R (i, N-1) {
        int u, v; re(u, v); --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
        tr.add_edge(u, v);
    }

    vvpii paths(N);

    F0R (u, N) fill(cover[u], cover[u] + MAXV, 1);
    F0R (u, N) {
        tr.reroot(u);
        F0R (v, N) if (v != u)
            cover[u][v] *= tr.subt_sz[v], cover[v][u] *= tr.subt_sz[v];
        FOR (v, u+1, N) paths[tr.depth[v]].eb(u, v);
    }

    for (auto [u, v] : paths[1]) ans[u][v] = cover[u][v];

    ll ANS = 0;
    FOR (len, 1, sz(paths)) {
        for (auto [u, v] : paths[len]) {
            ckmax(ANS, ans[u][v]);
            trav (n, adj[u]) if (cover[n][v] < cover[u][v]) {
                ckmax(n < v ? ans[n][v] : ans[v][n], ans[u][v] + cover[n][v]);
            }
            trav (n, adj[v]) if (cover[u][n] < cover[u][v]) {
                ckmax(u < n ? ans[u][n] : ans[n][u], ans[u][v] + cover[u][n]);
            }
        }
    }
    ps(ANS);

    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}