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

namespace __util {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> auto find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> auto index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> auto lower_bound(const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](const auto& a, const auto& b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> auto upper_bound(const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](const auto& a, const auto& b) { return a.f < b.f; });
    }
}
using namespace __util;

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

struct monostate {
    friend istream& operator>>(istream& is, __attribute__((unused))monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, __attribute__((unused))monostate& ms) { return os; }
} ms;

template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    int operator[](int loc) const { return u ^ v ^ loc; }
    friend void re(wedge& e) { re(e.u, e.v, e.w); --e.u, --e.v; }
    friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};

template<typename E> struct tree {
    int N; vvi adj; vector<E> edges;

    tree() {}
    tree(int _N) : N(_N) { adj.resz(N); edges.resz(N-1); }
    tree(const vector<E>& __edges) : tree(sz(__edges)+1) { edges = __edges; __init(); }

    void __init() {
        F0R (i, sz(edges)) {
            auto& e = edges[i];
            assert(0 <= e.u && e.u < N), adj[e.u].pb(i);
            assert(0 <= e.v && e.v < N), adj[e.v].pb(i);
        }
    }

    friend void re(tree& t) { re(t.edges); t.__init(); }
    friend void pr(const tree& t) { pr("{N=", t.N, " ", t.edges, "}"); }
};

// union_find {{{
struct uf_monostate {
    uf_monostate(__attribute__((unused)) int id) {}
    void merge(__attribute__((unused)) uf_monostate& o,
            __attribute__((unused)) const monostate& e) {}
};

template<typename C = uf_monostate, typename E = monostate>
struct union_find {
    struct node {
        int par, rnk, size; C state;
        node(int id = 0) : par(id), rnk(0), size(1), state(id) {}
        void merge(node& o, E& e) {
            if (rnk == o.rnk) rnk++;
            if (size < o.size) swap(state, o.state);
            size += o.size;
            state.merge(o.state, e);
        }
    };

    vector<node> uf;
    union_find(int N = 0) : uf(N) {
        for (int i = 0; i < N; i++)
            uf[i] = node(i);
    }

    int rep(int i) {
        if (i != uf[i].par)
            uf[i].par = rep(uf[i].par);
        return uf[i].par;
    }

    bool unio(int a, int b, E& e = ms) {
        a = rep(a), b = rep(b);
        if (a == b) return false;
        if (uf[a].rnk < uf[b].rnk) swap(a, b);
        uf[a].merge(uf[b], e);
        uf[b].par = a;
        return true;
    }

    C& state(int i) { return uf[rep(i)].state; }
};
// }}}

const int INF = 1e9;

using edge = wedge<int>;
vvi adj;
vector<edge> used, rest;
tree<edge> mst;

struct jump { int anc, msm, rep;
    friend void pr(const jump& j) { pr("{", j.anc, " ", j.msm, " ", j.rep, "}"); }
};
vi depth;
vector<vector<jump>> links;

void calc(tree<edge>& tr, int loc, int par = -1, int upe = -1) {
    links[0][loc] = { par, upe == -1 ? 0 : tr.edges[upe].w, INF };
    F0R (l, sz(links) - 1) {
        jump j1 = links[l][loc],
        j2 = links[l][j1.anc];
        links[l+1][loc] = { j2.anc, max(j1.msm, j2.msm), INF };
    }

    trav (ei, tr.adj[loc]) if (ei != upe) {
        auto& e = tr.edges[ei]; const int nbr = e[loc];
        depth[nbr] = depth[loc] + 1;
        calc(tr, nbr, loc, ei);
    }
}

int up(int a, int d) {
    F0R (l, sz(links)) if (d & (1 << l)) a = links[l][a].anc;
    return a;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = up(a, depth[a] - depth[b]);
    if (a == b) return a;
    F0Rd (l, sz(links)) {
        if (links[l][a].anc != links[l][b].anc) {
            a = links[l][a].anc;
            b = links[l][b].anc;
        }
    }
    assert(links[0][a].anc == links[0][b].anc);
    return links[0][a].anc;
}

pair<int, int> get(int a, int b) {
    int c = lca(a, b);
    int ad = depth[a] - depth[c];
    int bd = depth[b] - depth[c];

    int msm = 0, rep = INF;
    F0R (l, sz(links)) {
        if (ad & (1 << l)) {
            auto& j = links[l][a];
            ckmax(msm, j.msm);
            ckmin(rep, j.rep);
            a = j.anc;
        }
        if (bd & (1 << l)) {
            auto& j = links[l][b];
            ckmax(msm, j.msm);
            ckmin(rep, j.rep);
            b = j.anc;
        }
    }

    return { msm, rep };
}

void put_rep(int a, int b, int w) {
    int c = lca(a, b), ad = depth[a] - depth[c], bd = depth[b] - depth[c];
    F0R (l, sz(links)) {
        if (ad & (1 << l)) { auto& j = links[l][a]; ckmin(j.rep, w); a = j.anc; }
        if (bd & (1 << l)) { auto& j = links[l][b]; ckmin(j.rep, w); b = j.anc; }
    }
}

int main() {
    setIO();

    int N, M; re(N, M);

    vector<edge> edges(M); re(edges);
    F0R (i, M) edges[i].i = i;
    sort_by(edges, a.w < b.w);

    union_find uf(N);
    trav (e, edges) (uf.unio(e.u, e.v) ? used : rest).pb(e);

    mst = tree(used);
    depth.resz(N);
    links.resz(32 - __builtin_clz(N), vector<jump>(N, {0,0,INF}));
    calc(mst, 0, 0);

    trav (e, rest) put_rep(e.u, e.v, e.w);

    F0Rd (l, sz(links) - 1) {
        F0R (i, N) {
            auto& j1 = links[l][i];
            auto& j2 = links[l][j1.anc];
            ckmin(j1.rep, links[l+1][i].rep);
            ckmin(j2.rep, links[l+1][i].rep);
        }
    }

    vi ans(M);
    trav (e, used) ans[e.i] = get(e.u, e.v).s;
    trav (e, rest) ans[e.i] = get(e.u, e.v).f;
    pc(ans);

    return 0;
}