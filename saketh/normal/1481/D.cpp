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

#include <cstdlib>
#include <queue>
#include <cassert>
#include <algorithm>
#include <cstring>

template<typename EdgeWeight>
struct WeightedDirectedGraph {
    struct Edge {
        int neighbor;
        EdgeWeight weight;
    };

    int N;
    std::vector<std::vector<Edge>> adj;

    WeightedDirectedGraph (int _N) : N(_N), adj(_N) {}

    void add_directed_edge(int u, int v, EdgeWeight w) {
        adj[u].push_back({v, w});
    }
};

template<typename PathWeight>
struct ShortestPathTree {
    std::vector<int> parent;
    std::vector<PathWeight> shortest_path_wt;

    template<typename EdgeWeight, typename JoinPathAndEdge, typename PathWeightLessThan>
    ShortestPathTree(WeightedDirectedGraph<EdgeWeight> g, const std::vector<int> &sources,
            PathWeight init, JoinPathAndEdge join, PathWeightLessThan less_than) {
        struct Path {
            int destination;
            PathWeight weight;
        };

        auto path_cmp = [&less_than](const Path &a, const Path &b) {
            return less_than(b.weight, a.weight);
        };

        std::priority_queue<Path, std::vector<Path>, decltype(path_cmp)> pq(path_cmp);

        parent.assign(g.N, -1);
        shortest_path_wt.assign(g.N, init);

        for (int source : sources) {
            parent[source] = source;
            pq.push({ source, shortest_path_wt[source] });
        }

        while (!pq.empty()) {
            Path path = pq.top();
            pq.pop();

            if (memcmp(&path.weight, &shortest_path_wt[path.destination], sizeof(PathWeight)))
                continue;

            for (auto edge : g.adj[path.destination]) {
                PathWeight candidate = join(path.weight, edge.weight);
                if (parent[edge.neighbor] == -1 || less_than(candidate, shortest_path_wt[edge.neighbor])) {
                    parent[edge.neighbor] = path.destination;
                    shortest_path_wt[edge.neighbor] = candidate;
                    pq.push({ edge.neighbor, shortest_path_wt[edge.neighbor] });
                }
            }
        }
    }

    bool is_reachable(int destination) const {
        return parent[destination] != -1;
    }

    PathWeight distance(int destination) const {
        if (!is_reachable(destination)) assert(false);
        return shortest_path_wt[destination];
    }

    std::vector<int> list_vertices_on_path(int destination) const {
        if (!is_reachable(destination)) assert(false);

        std::vector<int> path;
        while (parent[destination] != destination) {
            path.push_back(destination);
            destination = parent[destination];
        }
        path.push_back(destination);

        std::reverse(path.begin(), path.end());
        return path;
    }
};

// tarjan {{{
#include <vector>

struct scc {
    int components;
    std::vector<int> label;
};

// Labels strongly connected components in reverse topological order.
// That means for any edge u-->v label[u] >= label[v].
scc strongly_connected_components(const std::vector<std::vector<int>>& graph) {
    const int N = int(graph.size());

    int C = 0, V = 0, top = 0;
    std::vector<int> comp(N, -1), inx(N, -1), stack(N + 1, -1);

    auto tarjan = [&](auto&& self, int loc) -> int {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int nbr : graph[loc]) {
            if (inx[nbr] == -1) low = std::min(low, self(self, nbr));
            else if (comp[nbr] == -1) low = std::min(low, inx[nbr]);
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



void solve() {
    int N, M; re(N, M);
    vs g(N); re(g);

    if (M & 1) {
        ps("YES");

        F0R (i, M + 1) {
            if (i) pr(" ");
            pr(i&1 ? 2 : 1);
        }

        ps();
        return;
    }

    vvi a(N), b(N);

    F0R (i, N) {
        F0R (j, N) {
            if (i == j)
                continue;

            if (g[i][j] == 'a')
                a[i].pb(j);
            else
                b[i].pb(j);
        }
    }

    auto find_cycle = [&](vvi &adj_lists) {
        WeightedDirectedGraph<int> gr(N);
        F0R (i, N)
            trav (j, adj_lists[i])
                gr.add_directed_edge(i, j, 1);

        F0R (root, N) {
            ShortestPathTree spt(gr, adj_lists[root], 0, plus<int>(), [](int x, int y) { return x < y; });
            if (spt.parent[root] != -1) {
                vi cyc = spt.list_vertices_on_path(root);
                return cyc;
            }
        }

        assert(false);
    };

    vi cyc;

    auto a_scc = strongly_connected_components(a);
    if (a_scc.components < N) { // a-cycle exists
        cyc = find_cycle(a);
    }

    auto b_scc = strongly_connected_components(b);
    if (b_scc.components < N) { // b-cycle exists
        cyc = find_cycle(b);
    }

    if (!cyc.empty()) {
        ps("YES");
        F0R (i, M + 1) {
            if (i) pr(" ");
            pr(cyc[i % sz(cyc)] + 1);
        }
        ps();

        return;
    }

    if (N == 2) {
        ps("NO");
        return;
    }

    vi topo(N);
    iota(all(topo), 0);
    sort_by(topo, a_scc.label[a] > a_scc.label[b]);

    vi path = { topo[1] };

    F0R (i, M/2) {
        path.pb(path.back() ^ topo[1] ^ topo[0]);
    }

    reverse(all(path));

    F0R (i, M/2) {
        path.pb(path.back() ^ topo[1] ^ topo[2]);
    }

    trav (e, path) ++e;

    ps("YES");
    pc(path);
}

int main() {
    setIO();

    int T; re(T); F0R (t, T) {
        //pr("Case #", t+1, ": ");
        solve();
    }

    return 0;
}