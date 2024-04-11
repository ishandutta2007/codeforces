#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

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
  template <class Node> vector<Node> dp(int r = 0) {
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
    return res;
  }
};

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (auto&& [u, v] : edges) {
    cin >> u >> v;
    --u, --v;
  }
  dsu d(n + 1);
  vector<int> idx;
  tree<int> g(n + 1);
  for (int i = 0; i < m; ++i) {
    auto [u, v] = edges[i];
    if (d.same(u, v)) {
      idx.push_back(i);
    } else {
      d.unite(u, v);
      g.add(u, v);
    }
  }
  for (int v = 0; v < n; ++v) {
    if (not d.same(v, n)) {
      d.unite(v, n);
      g.add(v, n);
    }
  }
  g.build_hld(n);
  vector<int> a, b;
  for (int i : idx) {
    int v = edges[i].first;
    int mn = n, mx = -1;
    while (true) {
      mn = min(mn, v);
      mx = max(mx, v);
      if (v == edges[i].second) {
        break;
      }
      v = g.next(v, edges[i].second);
    }
    a.push_back(mn);
    b.push_back(mx);
  }
  vector<int> mn(n + 1, n);
  for (int j = 0; j < (int)size(a); ++j) {
    chmin(mn[a[j]], b[j]);
  }
  for (int i = n; i--; ) {
    chmin(mn[i], mn[i + 1]);
  }
  vector<long long> cum(n + 1);
  for (int i = n; i--; ) {
    cum[i] = (mn[i] - i) + cum[i + 1];
  }
  DEBUG(a);
  DEBUG(b);
  DEBUG(mn);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    int i = lower_bound(begin(mn) + l, begin(mn) + r, r) - begin(mn);
    auto res = cum[l] - cum[i];
    long long k = r - i;
    res += k * (k + 1) / 2;
    cout << res << '\n';
  }
}