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
};

pair<int, int> query(const vector<int>& vs) {
  assert(not empty(vs));
  cout << "? " << size(vs);
  for (int v : vs) {
    cout << ' ' << v + 1;
  }
  cout << endl;
  int x, d;
  cin >> x >> d;
  --x;
  return {x, d};
}

void solve() {
  int n;
  cin >> n;
  tree<int> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  g.build();
  int r, d;
  {
    vector<int> vs(n);
    iota(begin(vs), end(vs), 0);
    tie(r, d) = query(vs);
  }
  g.build(r);
  int x, y, okx = -1;
  auto chk = [&](int m) {
    vector<int> vs;
    for (int v = 0; v < n; ++v) {
      if (g.dep[v] < m) continue;
      vs.push_back(v);
    }
    tie(x, y) = query(vs);
    if (y == d) {
      okx = x;
    }
    return y == d;
  };
  int ok = (d + 1) / 2, ng = min(d, *max_element(begin(g.dep), end(g.dep))) + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  if (ok != (d + 1) / 2) {
    x = okx;
  } else {
    chk(ok);
  }
  g.build(x);
  vector<int> vs;
  for (int v = 0; v < n; ++v) {
    if (g.dep[v] != d) continue;
    vs.push_back(v);
  }
  int z = query(vs).first;
  cout << "! " << x + 1 << ' ' << z + 1 << endl;
  // if (size(g.g[r]) == 1) {
  //   vector<int> vs;
  //   for (int v = 0; v < n; ++v) {
  //     if (g.dep[v] == d) {
  //       vs.push_back(vs);
  //     }
  //   }
  //   cout << "! " << r + 1 << ' ' << query(vs).first + 1 << endl;
  //   return;
  // }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
    string s;
    cin >> s;
  }
}