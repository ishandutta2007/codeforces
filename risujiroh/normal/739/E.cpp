#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T = int> struct graph {
  struct edge {
    int from, to;
    T w;
    int operator-(int v) const { return from ^ to ^ v; }
  };
  int n, m;
  vector<edge> es;
  vector<vector<int>> g;
  graph(int _n = 0) : n(_n), m(0), g(n) {}
  int add(int from, int to, bool undirected = true, T w = 1) {
    g[from].push_back(m);
    if (undirected) g[to].push_back(m);
    return es.push_back({from, to, w}), m++;
  }
};

struct dsu {
  int cc;
  vector<int> p, sz;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1) {}
  int root(int v) const {
    while (p[v] != -1) v = p[v];
    return v;
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
  bool same(int u, int v) const { return root(u) == root(v); }
  int size(int v) const { return sz[root(v)]; }
};

template <class T, class Digraph>
vector<int> find_negative_cycle(const Digraph& g) {
  vector<T> dist(g.n);
  vector<int> que(g.n), pe(g.n, -1);
  iota(begin(que), end(que), 0);
  vector in(g.n, true);
  for (int bg = 0, cnt = 0; bg < (int)size(que); ) {
    int v = que[bg++];
    in[v] = false;
    for (int id : g.g[v]) {
      auto&& e = g.es[id];
      if (dist[v] + e.w < dist[e.to]) {
        dist[e.to] = dist[v] + e.w, pe[e.to] = id, ++cnt;
        if (not in[e.to]) in[e.to] = true, que.push_back(e.to);
      }
    }
    if (cnt >= g.n or bg == (int)size(que)) {
      dsu d(g.n);
      for (v = 0; v < g.n; ++v) {
        if (pe[v] == -1 or d.unite(v, g.es[pe[v]].from)) continue;
        vector<int> res;
        for (int id = pe[v]; ; id = pe[g.es[id].from]) {
          res.push_back(id);
          if (g.es[id].from == v) break;
        }
        return {rbegin(res), rend(res)};
      }
    }
  }
  return {};
}

template <class T, size_t K>
T solve(const vector<array<T, K>>& cost, array<int, K> cap) {
  int n = size(cost);
  assert(accumulate(begin(cap), end(cap), 0) == n);
  T res = 0;
  vector<int> to(n);
  array<array<priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>>, K>, K> pq;
  for (int i = 0, u = 0; i < n; ++i) {
    while (cap[u] == 0) {
      ++u;
    }
    --cap[u];
    res += cost[i][u];
    to[i] = u;
    for (int v = 0; v < (int)K; ++v) {
      if (u == v) continue;
      pq[u][v].emplace(cost[i][v] - cost[i][u], i);
    }
  }
  while (true) {
    graph<T> g(K);
    for (int u = 0; u < (int)K; ++u) {
      for (int v = 0; v < (int)K; ++v) {
        while (not empty(pq[u][v]) and to[pq[u][v].top().second] != u) {
          pq[u][v].pop();
        }
        if (empty(pq[u][v])) continue;
        g.add(u, v, false, pq[u][v].top().first);
      }
    }
    auto ids = find_negative_cycle<T>(g);
    if (empty(ids)) break;
    for (int id : ids) {
      auto&& e = g.es[id];
      auto [c, i] = pq[e.from][e.to].top();
      pq[e.from][e.to].pop();
      res += c;
      to[i] = e.to;
      for (int v = 0; v < (int)K; ++v) {
        if (v == to[i]) continue;
        pq[to[i]][v].emplace(cost[i][v] - cost[i][to[i]], i);
      }
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> p(n), u(n);
  for (auto&& e : p) {
    double x;
    cin >> x;
    e = round(x * 1000);
  }
  for (auto&& e : u) {
    double x;
    cin >> x;
    e = round(x * 1000);
  }
  auto f = [&](int c) {
    vector<array<int, 4>> cost(n);
    for (int i = 0; i < n; ++i) {
      cost[i] = {0, 1000 * p[i], 1000 * u[i], 1000 * (p[i] + u[i]) - p[i] * u[i]};
      for (auto&& e : cost[i]) {
        e = -e;
      }
    }
    return -solve(cost, {n - a - b + c, a - c, b - c, c});
  };
  int l = max(a + b - n, 0) - 1, r = min(a, b) + 1;
  while (r - l > 2) {
    int m = (l + r) / 2;
    if (f(m) > f(m + 1)) {
      r = m + 1;
    } else {
      l = m;
    }
  }
  cout << 1e-6 * f(l + 1) << '\n';
}