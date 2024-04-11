#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T = int> struct tree {
  struct edge {
    int from, to;
    T w;
    int operator-(int v) const { return from ^ to ^ v; }
  };
  int n;
  vector<edge> es;
  vector<vector<int>> g;
  vector<int> pv, pe, sz, dep, vs, in, out, head;
  vector<T> dist;
  tree(int _n = 0) : n(_n), g(n) {}
  void add(int u, int v, T w = 1) {
    g[u].push_back(size(es)), g[v].push_back(size(es));
    es.push_back({u, v, w});
  }
  void dfs(int v) {
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = es[id] - v;
      assert(pv[to] == -1);
      pv[to] = v, pe[to] = id;
      dep[to] = dep[v] + 1, dist[to] = dist[v] + es[id].w;
      dfs(to);
      sz[v] += sz[to];
    }
    sort(begin(g[v]), end(g[v]), [&](int a, int b) {
      return sz[es[a] - v] * (a != pe[v]) > sz[es[b] - v] * (b != pe[v]);
    });
  }
  void build(int r = 0) {
    assert((int)size(es) == n - 1);
    pv.assign(n, -1), pe.resize(n), sz.resize(n), dep.resize(n), dist.resize(n);
    pe[r] = -1, dep[r] = 0, dist[r] = 0;
    dfs(r);
  }
  void dfs_hld(int v) {
    in[v] = size(vs), vs.push_back(v);
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = es[id] - v;
      head[to] = to == es[g[v][0]] - v ? head[v] : to;
      dfs_hld(to);
    }
    out[v] = size(vs);
  }
  void build_hld(int r = 0) {
    build(r);
    vs.clear(), in.resize(n), out.resize(n), head.resize(n);
    head[r] = r;
    dfs_hld(r);
  }
  bool anc(int u, int v) const { return in[u] <= in[v] and out[v] <= out[u]; }
  int lca(int u, int v) const {
    while (true) {
      if (in[u] > in[v]) swap(u, v);
      if (head[u] == head[v]) return u;
      v = pv[head[v]];
    }
  }
  int len(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
  T d(int u, int v) const { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }
  int la(int v, int d) const {
    assert(0 <= d and d <= dep[v]);
    while (dep[head[v]] > d) v = pv[head[v]];
    return vs[in[head[v]] + (d - dep[head[v]])];
  }
  int next(int from, int to) const {
    if (not anc(from, to)) return pv[from];
    return la(to, dep[from] + 1);
  }
  int next(int from, int to, int m) const {
    int v = lca(from, to);
    if (m <= dep[from] - dep[v]) return la(from, dep[from] - m);
    return la(to, m - dep[from] + 2 * dep[v]);
  }
  vector<pair<int, int>> ascend(int from, int to) const {
    vector<pair<int, int>> res;
    while (head[from] != head[to]) {
      res.emplace_back(in[from], in[head[from]]);
      from = pv[head[from]];
    }
    if (from != to) res.emplace_back(in[from], in[to] + 1);
    return res;
  }
  vector<pair<int, int>> descend(int from, int to) const {
    if (from == to) return {};
    if (head[from] == head[to]) return {{in[from] + 1, in[to]}};
    auto res = descend(from, pv[head[to]]);
    res.emplace_back(in[head[to]], in[to]);
    return res;
  }
  template <class F> void run(int from, int to, F f, bool vertex = true) const {
    int v = lca(from, to);
    for (auto e : ascend(from, v)) f(e.first + 1, e.second);
    if (vertex) f(in[v], in[v] + 1);
    for (auto e : descend(v, to)) f(e.first, e.second + 1);
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  tree g(n);
  for (int v = 1; v < n; ++v) {
    int p;
    cin >> p;
    --p;
    g.add(v, p);
  }
  g.build_hld();
  vector<double> cum(n + 1);
  for (int v = 0; v < n; ++v) {
    double sum = 0;
    for (int id : g.g[v]) {
      if (id == g.pe[v]) continue;
      int to = g.es[id] - v;
      sum += g.sz[to];
    }
    for (int id : g.g[v]) {
      if (id == g.pe[v]) continue;
      int to = g.es[id] - v;
      double cur = (sum - g.sz[to]) / 2 + 1;
      cum[g.in[to]] += cur;
      cum[g.out[to]] -= cur;
    }
  }
  for (int i = 0; i < n; ++i) {
    cum[i + 1] += cum[i];
  }
  for (int v = 0; v < n; ++v) {
    cout << cum[g.in[v]] + 1 << " \n"[v == n - 1];
  }
}