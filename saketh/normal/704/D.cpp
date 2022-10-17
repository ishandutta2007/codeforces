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

    template<typename C, typename T> vector<T> prefixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); F0R (i, sz(v)) res[i+1] = res[i] + v[i]; return res;
    }
    template<typename C, typename T> vector<T> suffixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); F0Rd (i, sz(v)) res[i] = v[i] + res[i+1]; return res;
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

// dinic {{{
template<typename F> struct dinic {
    static const F inf = numeric_limits<F>::max();

    int V;
    vvi adj;
    vi dest;
    vector<F> cap;

    dinic (int V = 0) : V(V) {
        adj.resize(V);
    }

    void __arc(int u, int v, F c) {
        adj[u].push_back(dest.size());
        dest.push_back(v);
        cap.push_back(c);
    }

    // Inserts a directed edge u --> v with capacity c.
    void arc(int u, int v, F c) {
        __arc(u, v, c);
        __arc(v, u, F(0));
    }

    bool bfs(int s, int t, vi& level, vector<F>& flow) const {
        level = vi(V, -1);
        level[s] = 0;
        for (queue<int> q({s}); !q.empty(); q.pop()) {
            int u = q.front();
            for (int e : adj[u]) {
                if (level[dest[e]] == -1 && flow[e] < cap[e]) {
                    level[dest[e]] = level[u] + 1;
                    q.push(dest[e]);
                }
            }
        }
        return level[t] != -1;
    }

    F augment(int s, int t, vi& level, vector<F>& flow, vi& inx, F cur) const {
        if (s == t) return cur;
        for (int e; inx[s] < adj[s].size(); inx[s]++) {
            e = adj[s][inx[s]];
            if (level[dest[e]] != level[s] + 1) continue;
            if (flow[e] == cap[e]) continue;
            F incr = augment(dest[e], t, level, flow, inx, min(cur, cap[e] - flow[e]));
            if (incr > F(0)) {
                flow[e] += incr;
                flow[e^1] -= incr;
                return incr;
            }
        }
        return F(0);
    }

    /*
     * Computes a maximum flow from node s to node t.
     *
     * Runs in O(V^2 * E) in the general case.
     * Runs in O(min{ V^(2/3), E^(1/2) } * E) if all edges have unit capacity.
     * Runs in O(V^(1/2) * E) for bipartite matching.
     */
    tuple<F, vector<F>> max_flow(int s, int t, vector<F> flow = {}) const {
        assert(s != t);
        F res(0);
        if (flow.empty()) flow.resz(sz(cap));
        for (vi level; bfs(s, t, level, flow); ) {
            for (vi inx(V, 0); F incr = augment(s, t, level, flow, inx, inf); )
                res += incr;
        }
        return make_tuple(res, flow);
    }
};

// }}}

pii bound(int V, int D) {
    ckmin(D, V);
    int lo = (V-D+1)/2;
    if (lo > V - lo) { ps(-1); exit(0); }
    return {lo, V-lo};
}

int main() {
    setIO();

    int N, M, R, B; re(N, M, R, B);

    vi x(N), y(N);
    F0R (i, N) re(x[i], y[i]);
    vi xc = x; dedup(xc);
    vi yc = y; dedup(yc);

    vi xd(sz(xc), N), yd(sz(yc), N);
    F0R (j, M) {
        int t, l, d; re(t, l, d);
        if (t == 1) {
            auto it = lb(all(xc), l);
            if (it != xc.end() && *it == l) ckmin(xd[it-xc.begin()], d);
        } else {
            auto it = lb(all(yc), l);
            if (it != yc.end() && *it == l) ckmin(yd[it-yc.begin()], d);
        }
    }

    vi xe(sz(xc)), ye(sz(yc));
    F0R (i, N) {
        xe[index(xc, x[i])]++;
        ye[index(yc, y[i])]++;
    }

    int tot_min = 0;

    dinic<int> g(4 + sz(xc) + sz(yc));
    F0R (i, sz(xc)) {
        pii xb = bound(xe[i], xd[i]);
        g.arc(2, 4 + i, xb.s - xb.f);
        g.arc(0, 4 + i, xb.f);
        g.arc(2, 1, xb.f);
        tot_min += xb.f;
    }
    F0R (j, sz(yc)) {
        pii yb = bound(ye[j], yd[j]);
        g.arc(4 + sz(xc) + j, 3, yb.s - yb.f);
        g.arc(0, 3, yb.f);
        g.arc(4 + sz(xc) + j, 1, yb.f);
        tot_min += yb.f;
    }
    g.arc(3, 2, INT_MAX);

    vi eid(N);
    F0R (i, N) {
        eid[i] = sz(g.cap);
        g.arc(4 + index(xc, x[i]), 4 + sz(xc) + index(yc, y[i]), 1);
    }

    int fv; vi fl; tie(fv, fl) = g.max_flow(0, 1);
    if (fv != tot_min) { ps(-1); return 0; }
    tie(fv, fl) = g.max_flow(2, 3, fl);

    ps(ll(fv) * min(R, B) + ll(N - fv) * max(R, B));
    F0R (i, N) pr(fl[eid[i]]>0 ^ R>B ? 'r' : 'b');
    ps();

    return 0;
}