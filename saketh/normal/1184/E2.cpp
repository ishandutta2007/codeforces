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

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

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
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
        pr("}");
    }
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

#define sort_by(x, c) sort(all(x), [&](const auto& a, const auto& b) { return (a)c < (b)c; })
}
using namespace __util;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

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

struct monostate {} ms;
struct uf_monostate {
    uf_monostate(__attribute__((unused)) int id) {}
    void merge(__attribute__((unused)) uf_monostate& o,
            __attribute__((unused)) const monostate& e,
            __attribute__((unused)) const monostate& g) {}
};

template<typename C = uf_monostate,
    typename E = monostate, typename G = monostate>
struct union_find {
    struct node {
        int par, rnk, size; C state;
        node(int id = 0) : par(id), rnk(0), size(1), state(id) {}
        void merge(node& o, E& e, G& g) {
            if (rnk == o.rnk) rnk++;
            if (size < o.size) swap(state, o.state);
            size += o.size;
            state.merge(o.state, e, g);
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

    bool unio(int a, int b, E& e = ms, G& g = ms) {
        a = rep(a), b = rep(b);
        if (a == b) return false;
        if (uf[a].rnk < uf[b].rnk) swap(a, b);
        uf[b].par = a;
        uf[a].merge(uf[b], e, g);
        return true;
    }

    C& state(int i) { return uf[rep(i)].state; }
};

int main() {
    setIO();

    int N, M; re(N, M);

    struct edge { int a, b, c, i; };
    vector<edge> edges(M);
    F0R (i, M) {
        auto& e = edges[i];
        re(e.a, e.b, e.c);
        --e.a, --e.b;
        e.i = i;
    }
    sort_by(edges, .c);

    vector<edge> mst, rest;

    union_find uf(N);
    trav (e, edges) (uf.unio(e.a, e.b) ? mst : rest).pb(e);

    const int R = sz(rest);
    sort_by(rest, .i);

    vvi adj(N);
    F0R (i, R) {
        adj[rest[i].a].pb(i);
        adj[rest[i].b].pb(i);
    }

    vi ans(R);
    struct globals {
        vector<edge>& rest;
        vi& ans;
        vvi& adj;
    } g{ rest, ans, adj };

    struct component {
        unordered_set<int> elts;
        component(int id) { elts.insert(id); }
        void merge(component& o, edge& edge, globals& g) {
            assert(sz(elts) >= sz(o.elts));
            trav (e, o.elts) trav(i, g.adj[e]) {
                int p = g.rest[i].a + g.rest[i].b - e;
                if (elts.count(p)) {
                    g.ans[i] = edge.c;
                }
            }
            elts.insert(all(o.elts));
        }
    };

    union_find<component, edge, globals> uf2(N);

    trav (e, mst) {
        uf2.unio(e.a, e.b, e, g);
    }

    F0R (i, R) {
        if (i) pr(" ");
        pr(ans[i]);
    }
    ps();

    return 0;
}