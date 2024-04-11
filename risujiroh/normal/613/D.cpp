#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

template <class T = int>
struct tree {
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
  template <class F>
  void run(int from, int to, F f, bool vertex = true) const {
    int v = lca(from, to);
    for (auto e : ascend(from, v)) f(e.first + 1, e.second);
    if (vertex) f(in[v], in[v] + 1);
    for (auto e : descend(v, to)) f(e.first, e.second + 1);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  tree g(n);
  for (int _ = n - 1; _--;) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  g.build_hld();
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (auto&& e : a) cin >> e, --e;
    auto comp = [&](int u, int v) { return g.in[u] < g.in[v]; };
    sort(begin(a), end(a), comp);
    bool any = false;
    for (int v : a)
      if (g.pv[v] != -1 and binary_search(begin(a), end(a), g.pv[v], comp)) {
        any = true;
        break;
      }
    if (any) {
      cout << "-1\n";
      continue;
    }
    auto vs = a;
    for (int i = 1; i < k; ++i) {
      int v = g.lca(a[i - 1], a[i]);
      vs.push_back(v);
    }
    sort(begin(vs), end(vs), comp);
    vs.erase(unique(begin(vs), end(vs)), end(vs));
    auto rnk = [&](int v) {
      return lower_bound(begin(vs), end(vs), v, comp) - begin(vs);
    };
    tree h(size(vs));
    vector<int> stk;
    for (int v : vs) {
      if (empty(stk)) {
        stk.push_back(v);
        continue;
      }
      while (not g.anc(stk.back(), v)) {
        stk.pop_back();
      }
      h.add(rnk(stk.back()), rnk(v));
      stk.push_back(v);
    }
    h.build_hld();
    auto mrg = [](auto x, auto y) {
      array<int, 4> z;
      z.fill(0x3f3f3f3f);
      z[0] = min(z[0], x[0] + y[0] + 1);
      z[0] = min(z[0], x[0] + y[1] + 1);
      z[0] = min(z[0], x[0] + y[2]);
      z[0] = min(z[0], x[0] + y[3]);
      z[3] = min(z[3], x[1] + y[0] + 1);
      z[3] = min(z[3], x[1] + y[1] + 1);
      z[1] = min(z[1], x[1] + y[2]);
      z[3] = min(z[3], x[1] + y[2] + 1);
      z[1] = min(z[1], x[1] + y[3]);
      z[3] = min(z[3], x[1] + y[3] + 1);
      z[1] = min(z[1], x[2] + y[0]);
      z[3] = min(z[3], x[2] + y[0] + 1);
      z[1] = min(z[1], x[2] + y[1]);
      z[3] = min(z[3], x[2] + y[1] + 1);
      z[2] = min(z[2], x[2] + y[2]);
      z[3] = min(z[3], x[2] + y[2] + 1);
      z[2] = min(z[2], x[2] + y[3]);
      z[3] = min(z[3], x[2] + y[3] + 1);
      z[3] = min(z[3], x[3] + y[0]);
      z[3] = min(z[3], x[3] + y[1]);
      z[3] = min(z[3], x[3] + y[2]);
      z[3] = min(z[3], x[3] + y[3]);
      return z;
    };
    vector<array<int, 4>> dp(h.n);
    vector<bool> b(h.n);
    for (int v = 0; v < h.n; ++v)
      b[v] = binary_search(begin(a), end(a), vs[v], comp);
    for_each(rbegin(h.vs), rend(h.vs), [&](int v) {
      dp[v].fill(0x3f3f3f3f);
      if (b[v])
        dp[v][0] = 0;
      else
        dp[v][2] = 0, dp[v][3] = 1;
      for (int id : h.g[v]) {
        if (id == h.pe[v]) continue;
        int u = h.es[id] - v;
        dp[v] = mrg(dp[v], dp[u]);
      }
    });
    cout << *min_element(begin(dp[0]), end(dp[0])) << '\n';
  }
}