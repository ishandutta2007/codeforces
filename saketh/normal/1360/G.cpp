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
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
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
    int arc(int u, int v, F c) {
        __arc(u, v, c);
        __arc(v, u, F(0));
        return sz(dest) - 2;
    }

    mutable vi level;
    void bfs(int s, vector<F>& flow) const {
        level.resz(V), fill(all(level), -1), level[s] = 0;
        for (queue<int> q({s}); !q.empty(); q.pop()) {
            for (int e : adj[q.front()]) {
                if (level[dest[e]] == -1 && flow[e] < cap[e]) {
                    level[dest[e]] = level[q.front()] + 1;
                    q.push(dest[e]);
                }
            }
        }
    }

    mutable vi inx;
    F augment(int s, int t, vector<F>& flow, F cur = inf) const {
        if (s == t) return cur;
        for (; inx[s] < adj[s].size(); inx[s]++) {
            int e = adj[s][inx[s]];
            if (level[dest[e]] != level[s] + 1) continue;
            if (flow[e] == cap[e]) continue;
            if (F incr = augment(dest[e], t, flow, min(cur, cap[e] - flow[e]))) {
                flow[e] += incr;
                flow[e^1] -= incr;
                return incr;
            }
        }
        return 0;
    }

    /*
     * Computes a maximum flow from node s to node t.
     *
     * Runs in O(V^2 * E) in the general case.
     * Runs in O(min{ V^(2/3), E^(1/2) } * E) if all edges have unit capacity.
     * Runs in O(V^(1/2) * E) for bipartite matching.
     */
    struct max_flow {
        F res;
        vector<F> flow;
    };
    max_flow solve(int s, int t) const {
        assert(s != t);
        F res = 0;
        vector<F> flow(cap.size());
        while (bfs(s, flow), ~level[t]) {
            inx.resz(V), fill(all(inx), 0);
            while (F incr = augment(s, t, flow))
                res += incr;
        }
        return max_flow{res, flow};
    }
};
// }}}

void solve() {
    int N, M, A, B; re(N, M, A, B);

    if (N * A != M * B || (A > M) || (B > N)) {
        ps("NO");
        return;
    }

    dinic<int> g(1 + N + M + 1);

    F0R (i, N) F0R (j, M) {
        g.arc(1 + i, 1 + N + j, 1);
    }

    F0R (i, N) {
        g.arc(0, 1 + i, A);
    }

    F0R (j, M) {
        g.arc(1 + N + j, g.V - 1, B);
    }

    auto [mf, assign] = g.solve(0, g.V - 1);


    ps("YES");

    F0R (i, N) {
        F0R (j, M) {
            int e = 2 * (i * M + j);
            pr(assign[e]);
        }
        ps();
    }
}

int main() {
    setIO();

    int T; re(T); F0R (t, T) {
        //pr("Case #", t+1, ": ");
        solve();
    }

    return 0;
}