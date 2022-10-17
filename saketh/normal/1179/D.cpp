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
    template<typename T> typename vector<T>::iterator find(const vector<T>& v, const T& x) {
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
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

template<typename E> struct tree {
    int N; vvi adj; vector<E> edges;

    tree() {}
    tree(int _N) : N(_N) {
        adj.resz(N);
        edges.resz(N-1);
    }
    tree(const vector<E>& __edges)  {
        adj.resz(sz(edges) + 1);
        edges = __edges;
        __init();
    }
    void __init() {
        F0R (i, sz(edges)) {
            auto& e = edges[i];
            assert(0 <= e.u && e.u < N), adj[e.u].pb(i);
            assert(0 <= e.v && e.v < N), adj[e.v].pb(i);
            e.i = i;
        }
    }

    friend void re(tree& t) { re(t.edges); t.__init(); }
    friend void pr(const tree& t) { pr("{N=", t.N, " ", t.edges, "}"); }

    template<typename T> void go(vector<T>& down, int loc, int ine) const {
        trav (ei, adj[loc]) if (ei != ine) {
            int cloc = edges[ei][loc];
            down[loc].pre_process(down[cloc]);
            go(down, cloc, ei);
            down[loc].attach(down[cloc].extend());
        }
        down[loc].post_process();
    }
    template<typename T> vector<T> down(int root) const {
        vector<T> down(N);
        F0R (i, N) down[i] = T::leaf(i);
        go(down, root, -1);
        return down;
    }

    template<typename T> void again(vector<T>& down, vector<T>& up, int loc, int ine) const {
        const int D = sz(adj[loc]);
        vector<T> pref(D), suff(D);
        F0R (i, D) {
            const E& e = edges[adj[loc][i]];
            pref[i] = suff[i] = ((e.i != ine) ? down[e[loc]] : up[loc]).extend();
        }
        F0R (i, D-1) pref[i+1].accumulate(pref[i]);
        F0Rd (i, D-1) suff[i].accumulate(suff[i+1]);
        F0R (i, D) {
            const E& e = edges[adj[loc][i]];
            if (e.i != ine) {
                int cloc = e[loc];
                T& cres = up[cloc] = T::leaf(loc);
                if (i) cres.attach(pref[i-1]);
                if (i+1<D) cres.attach(suff[i+1]);
                cres.post_process();
                again(down, up, e[loc], e.i);
            }
        }
    }
    template<typename T> array<vector<T>, 3> both() const {
        vector<T> down(N); go(down, 0, -1);
        vector<T> up(N); again(down, up, 0, -1);
        vector<T> root = down;
        FOR (i, 1, N) {
            root[i].attach(up[i].extend());
            root[i].post_process();
        }
        return {down, up, root};
    }
};
using edge = wedge<>;

ll nc2(ll v) { return v * (v - 1) / 2; }

int N;
struct subtree {
    int id, size, depth;
    ll ans, rpath;
    vector<pair<int, ll>> cchoice;

    // base case
    static subtree leaf(int id) { return {id, 1, 0, LLONG_MAX, 0ll, {}}; }

    // called before recursion to each child subtree
    void pre_process(subtree& child) { child.depth = depth + 1; }

    // extend an edge from the root of the subtree (to be attached to parent)
    const subtree& extend() { return *this; }

    // attach subtree(s) that have been "extended" with an edge
    void attach(const subtree& o) {
        size += o.size;
        cchoice.eb(o.size, o.rpath);
        ckmin(ans, o.ans);
    }

    // called after all subtrees have been attached
    const subtree& post_process() {
        decltype(cchoice) shrunk;
        sort(all(cchoice));
        trav (elt, cchoice)
            if (sz(shrunk) < 2 || shrunk[sz(shrunk)-2].f != elt.f)
                shrunk.pb(elt);

        rpath = nc2(size);
        for (auto [ss, rc] : shrunk) ckmin(rpath, rc + nc2(size - ss));

        for (auto it1 = shrunk.begin(); it1 != shrunk.end(); it1++) {
            ckmin(ans, it1->s + nc2(N - it1->f));
            for (auto it2 = next(it1); it2 != shrunk.end(); it2++) {
                ckmin(ans, it1->s + it2->s + nc2(N - it1->f - it2->f));
            }
        }
        return *this;
    }

    // combine multiple "extended" subtrees that are yet to be attached to a root
    // only needed when computing dp from all roots (both "down" and "up" subtrees)
    void accumulate(const subtree& o) { assert(false); }

    friend void pr(const subtree& s) {
        pr("{id=", s.id, " sz=", s.size, " depth=", s.depth, "}");
    }
};

int main() {
    setIO();

    re(N); tree<edge> tr(N); re(tr);
    auto down = tr.down<subtree>(0);
    ps(2 * nc2(N) - down[0].ans);

    return 0;
}