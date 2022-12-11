#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int64_t ll;

struct Edge {
    ll v, f, c;

    Edge(ll v, ll f, ll c)
        : v(v), f(f), c(c) {}

    ll get_capacity() {
        return c - f;
    }
};

const ll INF = (ll)(1e9) + 666;
const ll N = 10000;
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

bool bfs() {
    fill(dist, dist + N, INF);
    dist[S] = 0;
    queue<ll> q;
    q.push(S);
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll id : g[v]) {
            if (edges[id].get_capacity() < 1) {
                continue;
            }
            if (dist[edges[id].v] > dist[v] + 1) {
                dist[edges[id].v] = dist[v] + 1;
                q.push(edges[id].v);
            }
        }
    }
    return dist[T] != INF;
}

ll dfs(ll v, ll min_c) {
    if (v == T) {
        return min_c;
    }
    while (ptr[v] < g[v].size()) {
        ll id = g[v][ptr[v]];
        ++ptr[v];
        if (edges[id].get_capacity() < 1) {
            continue;
        }
        if (dist[edges[id].v] != dist[v] + 1) {
            continue;
        }
        ll x = dfs(edges[id].v, min(min_c, edges[id].get_capacity()));
        if (x) {
            --ptr[v];
            edges[id].f += x;
            edges[id ^ 1].f -= x;
            return x;
        }
    }
    return 0;
}

int main() {
    ll n, h, m;
    cin >> n >> h >> m;
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < h; ++j) {
            sum += 2 * (j + 1) - 1;
            add_edge(S, i * h + j, 2 * (j + 1) - 1);
        }
    }
    for (ll q = 0; q < m; ++q) {
        ll left, right, x, c;
        cin >> left >> right >> x >> c;
        add_edge(q + N / 2, T, c);
        for (ll i = left - 1; i < right; ++i) {
            for (ll j = x; j < h; ++j) {
                add_edge(i * h + j, q + N / 2, INF);
            }
        }
    }
    while (bfs()) {
        fill(ptr, ptr + N, 0);
        while (dfs(S, INF)) {
        }
    }
    for (ll id : g[S]) {
        sum -= edges[id].f;
    }
    cout << sum << endl;
    return 0;
}