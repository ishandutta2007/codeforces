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

template <class Node, class T, class F>
auto tree_dp(tree<T>& g, F add_root, int r = 0) {
  g.build_hld(r);
  vector<Node> lower(g.n - 1), upper(g.n - 1), all(g.n);
  vector<vector<Node>> cum(g.n);
  for_each(rbegin(g.vs), rend(g.vs), [&](int v) {
    int m = size(g.g[v]) - (v != r);
    cum[v].resize(m + 1);
    for (int i = m; i--; ) cum[v][i] = lower[g.g[v][i]] + cum[v][i + 1];
    if (v != r) lower[g.pe[v]] = add_root(cum[v][0], v, g.pe[v]);
  });
  for (int v : g.vs) {
    Node cur = v != r ? upper[g.pe[v]] : Node();
    for (int i = 0; i < (int)size(cum[v]) - 1; ++i) {
      upper[g.g[v][i]] = add_root(cur + cum[v][i + 1], v, g.g[v][i]);
      cur = cur + lower[g.g[v][i]];
    }
    all[v] = add_root(cur, v, -1);
  }
  return make_tuple(lower, upper, all);
}
struct node {
  int mx, v = -1;
  node operator+(const node& b) const {
    return mx < b.mx ? b : *this;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    --a, --b;
    tree g(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g.add(u, v);
    }
    auto add_root = [&](node e, int v, int id) {
      if (id != -1) {
        e.mx += g.es[id].w;
      }
      if (e.v == -1) {
        e.v = v;
      }
      return e;
    };
    auto [lower, upper, all] = tree_dp<node>(g, add_root);
    vector<int> cum(n + 1);
    auto add = [&](int l, int r) {
      ++cum[l];
      --cum[r];
    };
    g.run(a, b, [&](int l, int r) {
      tie(l, r) = minmax({l, r});
      add(l, r);
    });
    int best = -1, k = g.len(a, b);
    while (true) {
      int nb = a;
      if (g.anc(a, b)) {
        add(0, g.in[a]);
        add(g.out[a], n);
        nb = upper[g.pe[g.next(a, b)]].v;
      } else {
        add(g.in[a], g.out[a]);
        nb = lower[g.pe[a]].v;
      }
      int cur = g.len(a, nb);
      if (cur <= best) break;
      if (cur >= k) {
        add(0, n);
        break;
      }
      best = cur;
      a = g.next(b, a, cur);
      b = nb;
    }
    for (int i = 0; i < n; ++i) {
      cum[i + 1] += cum[i];
    }
    for (auto&& e : g.es) {
      e.w = cum[g.in[e.from]] and cum[g.in[e.to]];
    }
    tie(lower, upper, ignore) = tree_dp<node>(g, add_root);
    bool any = false;
    for (int v = 0; v < n; ++v) {
      array<int, 3> d{};
      for (int id : g.g[v]) {
        int x = (id == g.pe[v] ? upper : lower)[id].mx;
        for (int i = 0; i < 3; ++i) {
          if (x <= d[i]) continue;
          for (int j = 3; j-- > i; ) {
            d[j] = j > i ? d[j - 1] : x;
          }
          break;
        }
      }
      if (d[2] >= k) {
        any = true;
        break;
      }
    }
    cout << (any ? "YES\n" : "NO\n");
  }
}