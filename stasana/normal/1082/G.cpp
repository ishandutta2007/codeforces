#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;

inline void start() {
#ifdef BOKU_NO_PICO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#endif
}

struct Edge {
    ll v, f, c;

    Edge(ll v, ll f, ll c)
        : v(v), f(f), c(c) {}
};

const ll INF = (ll)(1e17) + 666;
const ll N = 6'666;
const ll S = N - 2;
const ll T = N - 1;
vector<Edge> edges;
vector<ll> g[N];
ll dist[N];
ll ptr[N];

void add_edge(ll v, ll u, ll c) {
    g[v].emplace_back(edges.size());
    edges.emplace_back(u, 0, c);
    g[u].emplace_back(edges.size());
    edges.emplace_back(v, 0, 0);
}

bool bfs(ll kek) {
    fill(dist, dist + N, INF);
    dist[S] = 0;
    queue<ll> q;
    q.push(S);
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : g[v]) {
            if (edges[u].c - edges[u].f < kek) {
                continue;
            }
            if (dist[edges[u].v] > dist[v] + 1) {
                dist[edges[u].v] = dist[v] + 1;
                q.push(edges[u].v);
            }
        }
    }
    return dist[T] != INF;
}

ll dfs(ll v, ll min_c, ll kek) {
    if (v == T) {
        return min_c;
    }
    for (ll i = ptr[v]; i < g[v].size(); ++i) {
        ll u = g[v][i];
        ++ptr[v];
        if (edges[u].c - edges[u].f < kek) {
            continue;
        }
        if (dist[edges[u].v] != dist[v] + 1) {
            continue;
        }
        ll x = dfs(edges[u].v, min(min_c, edges[u].c - edges[u].f), kek);
        if (x) {
            --ptr[v];
            edges[u].f += x;
            edges[u ^ 1].f -= x;
            return x;
        }
    }
    return 0;
}

inline void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        add_edge(i, T, x);
    }
    ll result = 0;
    for (ll i = 1; i <= m; ++i) {
        ll v, u, x;
        cin >> v >> u >> x;
        result += x;
        add_edge(S, i + N / 2, x);
        add_edge(i + N / 2, v, INF);
        add_edge(i + N / 2, u, INF);
    }

    for (ll i = 30; i >= 0; --i) {
        while (bfs(1 << i)) {
            fill(ptr, ptr + N, 0);
            while (dfs(S, INF, 1 << i));
        }
    }

    for (ll u : g[S]) {
        result -= edges[u].f;
    }
    cout << result << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}