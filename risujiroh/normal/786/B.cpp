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
  template <bool Directed = false> void add(int from, int to, T w = 1) {
    g[from].push_back(m);
    if (not Directed) g[to].push_back(m);
    es.push_back({from, to, w}), ++m;
  }
};

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

template <class T, class G>
pair<vector<T>, vector<int>> dijkstra(const G& g, int s) {
  vector d(g.n, inf<T>), prv(g.n, -1);
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
  pq.emplace(d[s] = 0, s);
  while (not empty(pq)) {
    auto [dv, v] = pq.top();
    pq.pop();
    if (dv != d[v]) continue;
    for (int id : g.g[v]) {
      int to = g.es[id] - v;
      if (chmin(d[to], dv + g.es[id].w)) pq.emplace(d[to], to), prv[to] = v;
    }
  }
  return {d, prv};
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q, s;
  cin >> n >> q >> s;
  --s;
  graph g(4 * n);
  for (int i = n; i-- > 1; ) {
    g.add<true>(i, 2 * i, 0);
    g.add<true>(i, 2 * i + 1, 0);
    g.add<true>(2 * n + 2 * i, 2 * n + i, 0);
    g.add<true>(2 * n + 2 * i + 1, 2 * n + i, 0);
  }
  for (int i = 0; i < n; ++i) {
    g.add(n + i, 3 * n + i, 0);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      g.add<true>(n + u, n + v, w);
    } else if (t == 2) {
      int v, l, r, w;
      cin >> v >> l >> r >> w;
      --v, --l;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) g.add<true>(n + v, l++, w);
        if (r & 1) g.add<true>(n + v, --r, w);
      }
    } else {
      int v, l, r, w;
      cin >> v >> l >> r >> w;
      --v, --l;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) g.add<true>(2 * n + l++, n + v, w);
        if (r & 1) g.add<true>(2 * n + --r, n + v, w);
      }
    }
  }
  auto d = dijkstra<long long>(g, n + s).first;
  for (int v = 0; v < n; ++v) {
    if (d[n + v] > 1e18) {
      d[n + v] = -1;
    }
    cout << d[n + v] << " \n"[v == n - 1];
  }
}