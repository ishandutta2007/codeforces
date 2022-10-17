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

// min_cost_flow {{{
template<typename F, typename C> struct min_cost_flow {
    static constexpr int bits = 63 - __builtin_clzll(numeric_limits<F>::max());

    int V, E;
    vvi adj;
    vi dest;
    vector<F> cap;
    vector<C> cost;

    min_cost_flow(int V = 0) : V(V), E(0) {
        adj.resize(V);
    }

    void __arc(int u, int v, F f, C c) {
        E++;
        adj[u].push_back(dest.size());
        dest.push_back(v);
        cap.push_back(f);
        cost.push_back(c);
    }

    // Inserts a directed edge u --> v with capacity f and cost c.
    void arc(int u, int v, F f, C c) {
        __arc(u, v, f, c);
        __arc(v, u, F(0), -c);
    }

    bool dijkstra(auto& imb, auto& flow, auto& pot, F delta) const {
        priority_queue<tuple<C, int, int>> q;
        vi ent(V, -2);
        vector<C> dist(V, numeric_limits<C>::max());
        for (int v = 0; v < V; v++) if (imb[v] >= delta) {
            dist[v] = 0;
            q.push(make_tuple(0., v, -1));
        }

        while (!q.empty()) {
            C d; int v, f; tie(d, v, f) = q.top(); q.pop();
            if (ent[v] != -2) continue;
            dist[v] = -d; ent[v] = f;
            for (int e : adj[v]) if (cap[e] - flow[e] >= delta) {
                double cd = dist[v] + (cost[e] + pot[v] - pot[dest[e]]);
                if (cd < dist[dest[e]]) {
                    dist[dest[e]] = cd;
                    q.push(make_tuple(-cd, dest[e], e ));
                }
            }
        }

        for (int v = 0; v < V; v++) if (ent[v] != -2 && imb[v] <= -delta) {
            for (int u = 0; u < V; u++)
                if (ent[u] != -2) pot[u] += dist[u];
            for (int e = ent[v]; ~e; e = ent[dest[e^1]]) {
                flow[e] += delta;
                flow[e^1] -= delta;
                imb[dest[e]] += delta;
                imb[dest[e^1]] -= delta;
            }
            return true;
        }
        return false;
    }

    // Computes the minimum cost to satisfy the specified imbalances.
    // Runs in O(E^2 * log V * log inf).
    tuple<bool, C, vector<F>> solve(vector<F> imb) const {
        vector<F> flow(E);
        vector<C> pot(V);
        for (F delta = 1ll << bits; delta; delta >>= 1) {
            for (int e = 0; e < E; e++) {
                int u = dest[e^1], v = dest[e];
                F res = cap[e] - flow[e];
                if (res >= delta && cost[e] + pot[u] - pot[v] < 0) {
                    flow[e^1] -= res;
                    flow[e] += res;
                    imb[u] -= res;
                    imb[v] += res;
                }
            }
            while (dijkstra(imb, flow, pot, delta));
        }

        C ans = 0;
        for (int e = 0; e < E; e++) if (flow[e] > 0)  {
            ans += flow[e] * cost[e];
        }
        return { imb == vector<F>(V, 0), ans, flow };
    }
};
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
    tuple<F, vector<F>> max_flow(int s, int t) const {
        assert(s != t);
        F res(0);
        vector<F> flow(cap.size());
        for (vi level; bfs(s, t, level, flow); ) {
            for (vi inx(V, 0); F incr = augment(s, t, level, flow, inx, inf); )
                res += incr;
        }
        return make_tuple(res, flow);
    }
};

// }}}

int main() {
    setIO();

    const string colors = "RUB";

    int N1, N2, M, R, B; re(N1, N2, M, R, B);
    string g1, g2; re(g1, g2); string G = g1 + g2;

    const int N = N1 + N2;
    min_cost_flow<int, ll> mcf(N + 2);
    const int SRC = mcf.V - 2, SNK = mcf.V - 1;

    vi red(M), blue(M);
    F0R (i, M) {
        int u, v; re(u, v); u = u-1, v = v-1 + N1;
        red[i] = mcf.E;
        mcf.arc(u, v, 1, R);
        blue[i] = mcf.E;
        mcf.arc(v, u, 1, B);
    }

    const int INF = 1e9;

    vi imb(N + 2); imb[SRC] = INF, imb[SNK] = -INF;
    mcf.arc(SRC, SNK, INF, 0);

    F0R (i, N) if (G[i] != 'U') {
        if ((G[i] == 'B') ^ (i >= N1)) {
            imb[i] = -1, ++imb[SNK];
            mcf.arc(i, SNK, INF, 0);
        } else {
            imb[i] = +1, --imb[SRC];
            mcf.arc(SRC, i, INF, 0);
        }
    } else {
        mcf.arc(SRC, i, INF, 0);
        mcf.arc(i, SNK, INF, 0);
    }

    auto [ok, cost, flows] = mcf.solve(imb);
    if (!ok) ps(-1), exit(0);

    string assign(M, 'U');
    F0R (i, M) {
        if (flows[red[i]]  > 0) assign[i] = 'R';
        if (flows[blue[i]] > 0) assign[i] = 'B';
    }
    ps(cost), ps(assign);

    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}