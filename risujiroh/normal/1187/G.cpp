#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class T> struct PrimalDual {
  struct Edge { int to, rev; T cap, cost; };
  const T inf = numeric_limits<T>::max();
  const int n;
  VV<Edge> g;
  V<T> pot, dist;
  V<> pv, pe;
  PrimalDual(int n) : n(n), g(n), pot(n), dist(n), pv(n), pe(n) {}
  void add_edge(int from, int to, T cap, T cost) {
    assert(from != to);
    assert(cap >= 0);
    if (!cap) return;
    assert(cost >= 0);
    g[from].emplace_back(Edge{to, (int) g[to].size(), cap, cost});
    g[to].emplace_back(Edge{from, (int) g[from].size() - 1, 0, -cost});
  }
  void dijkstra(int s) {
    using P = pair<T, int>;
    priority_queue< P, V<P>, greater<P> > pque;
    fill(begin(dist), end(dist), inf);
    pque.emplace(dist[s] = 0, s);
    while (!pque.empty()) {
      T d; int v;
      tie(d, v) = pque.top(); pque.pop();
      if (d > dist[v]) continue;
      for (int i = 0; i < (int) g[v].size(); ++i) {
        const Edge& e = g[v][i];
        if (!e.cap or dist[e.to] <= dist[v] + e.cost - (pot[e.to] - pot[v])) continue;
        pv[e.to] = v, pe[e.to] = i;
        pque.emplace(dist[e.to] = dist[v] + e.cost - (pot[e.to] - pot[v]), e.to);
      }
    }
  }
  T min_cost_flow(int s, int t, T f) {
    assert(s != t);
    assert(f >= 0);
    T res = 0;
    fill(begin(pot), end(pot), 0);
    while (f > 0) {
      dijkstra(s);
      if (dist[t] == inf) return -1;
      for (int v = 0; v < n; ++v) pot[v] += dist[v];
      T d = f;
      for (int v = t; v != s; v = pv[v]) {
        d = min(d, g[pv[v]][pe[v]].cap);
      }
      f -= d;
      res += d * pot[t];
      for (int v = t; v != s; v = pv[v]) {
        Edge& e = g[pv[v]][pe[v]];
        e.cap -= d;
        g[v][e.rev].cap += d;
      }
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, k, c, d; cin >> n >> m >> k >> c >> d;
  V<> a(k); for (auto&& e : a) cin >> e, --e;
  auto _ = [&](int t, int v) -> int { return t * n + v; };
  int S = 100 * n, T = S + 1;
  PrimalDual<int> g(T + 1);
  for (int t = 0; t + 1 < 100; ++t) for (int v = 0; v < n; ++v) {
    g.add_edge(_(t, v), _(t + 1, v), g.inf, 0);
  }
  while (m--) {
    int u, v; cin >> u >> v, --u, --v;
    for (int t = 0; t + 1 < 100; ++t) {
      for (int x = 0; x < k; ++x) {
        g.add_edge(_(t, u), _(t + 1, v), 1, d * (2 * x + 1));
        g.add_edge(_(t, v), _(t + 1, u), 1, d * (2 * x + 1));
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    g.add_edge(S, _(0, a[i]), 1, 0);
  }
  for (int t = 0; t < 100; ++t) {
    g.add_edge(_(t, 0), T, g.inf, c * t);
  }
  cout << g.min_cost_flow(S, T, k) << '\n';
}