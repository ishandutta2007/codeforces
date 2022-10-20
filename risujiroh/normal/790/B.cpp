#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct tree {
  struct edge {
    int u, v;
    T w;
  };
  const int n;
  vector<edge> es;
  vector<vector<int>> g;
  vector<int> pv, pe, sz, dep, vs, in, out, head;
  vector<T> dist;
  tree(int _n = 0) : n(_n), g(n) {}
  void add(int u, int v, T w = 1) {
    g[u].push_back(es.size()), g[v].push_back(es.size());
    es.push_back({u, v, w});
  }
  int other(int id, int v) const { return es[id].u ^ es[id].v ^ v; }
  void dfs(int v) {
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = other(id, v);
      assert(pv[to] == -1);
      pv[to] = v, pe[to] = id;
      dep[to] = dep[v] + 1, dist[to] = dist[v] + es[id].w;
      dfs(to);
      sz[v] += sz[to];
    }
    sort(begin(g[v]), end(g[v]), [&](int a, int b) {
      return sz[other(a, v)] * (a != pe[v]) > sz[other(b, v)] * (b != pe[v]);
    });
  }
  void build(int r = 0) {
    assert((int)es.size() == n - 1);
    pv.assign(n, -1), pe.resize(n), sz.resize(n), dep.resize(n), dist.resize(n);
    pe[r] = -1, dep[r] = 0, dist[r] = 0;
    dfs(r);
  }
  void dfs_hld(int v) {
    in[v] = vs.size(), vs.push_back(v);
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = other(id, v);
      head[to] = to == other(g[v][0], v) ? head[v] : to;
      dfs_hld(to);
    }
    out[v] = vs.size();
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
  int d(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
  T len(int u, int v) const { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }
  int la(int v, int d) const {
    assert(0 <= d and d <= dep[v]);
    while (dep[head[v]] > d) v = pv[head[v]];
    return vs[in[head[v]] + (d - dep[head[v]])];
  }
  int next(int from, int to) const {
    assert(from != to);
    if (not anc(from, to)) return pv[from];
    return la(to, dep[from] + 1);
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
  template <class Node> auto dp(int r = 0) {
    build_hld(r);
    vector<Node> lower(n - 1), upper(n - 1), res(n);
    vector<vector<Node>> cum(n);
    for (int t = n; t--; ) {
      int v = vs[t], m = g[v].size() - (v != r);
      cum[v].resize(m + 1);
      for (int i = m; i--; ) cum[v][i] = lower[g[v][i]] + cum[v][i + 1];
      if (v != r) lower[pe[v]] = cum[v][0].add(v, pe[v]);
    }
    for (int v : vs) {
      Node cur = v != r ? upper[pe[v]] : Node();
      for (int i = 0, m = cum[v].size() - 1; i < m; ++i) {
        upper[g[v][i]] = (cur + cum[v][i + 1]).add(v, g[v][i]);
        cur = cur + lower[g[v][i]];
      }
      res[v] = cur.add(v);
    }
    return make_pair(lower, upper);
  }
};

int k;
struct node {
  array<int, 5> c = {};
  node operator+(const node& b) const {
    auto a = *this;
    for (int i = 0; i < k; ++i) {
      a.c[i] += b.c[i];
    }
    return a;
  }
  node add(int v, int id = -1) const {
    node a;
    a.c[0] = c[k - 1] + 1;
    for (int i = 1; i < k; ++i) {
      a.c[i] = c[i - 1];
    }
    return a;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n >> k;
  tree<int> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  auto [lower, upper] = g.dp<node>();
  auto res = 0LL;
  for (int v = 1; v < n; ++v) {
    int id = g.pe[v];
    res += lower[id].c[0] * accumulate(begin(upper[id].c), end(upper[id].c), 0LL);
    res += upper[id].c[0] * accumulate(begin(lower[id].c), end(lower[id].c), 0LL);
  }
  res /= 2;
  cout << res << '\n';
}