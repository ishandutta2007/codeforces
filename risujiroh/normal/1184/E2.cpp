#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

namespace LCA {
  using T = int;
  struct Edge { int to; T w; };
  T op(const T& x, const T& y) { return max(x, y); }
  constexpr T e = -1;

  V<> dep;
  VV<> par;
  VV<T> val;
  void init(const VV<Edge>& g, int r) {
    int n = g.size();
    dep.resize(n);
    par.assign(__lg(2 * n - 1), V<>(n, -1));
    val.assign(__lg(2 * n - 1), V<>(n, e));
    auto dfs = [&](const auto& dfs, int v, int p) -> void {
      for (const auto& e : g[v]) if (e.to != p) {
        dep[e.to] = dep[v] + 1;
        par[0][e.to] = v;
        val[0][e.to] = e.w;
        dfs(dfs, e.to, v);
      }
    };
    dep[r] = 0;
    dfs(dfs, r, -1);
    for (int k = 1; k < (int) par.size(); ++k) {
      for (int v = 0; v < n; ++v) {
        if (par[k - 1][v] == -1) continue;
        par[k][v] = par[k - 1][par[k - 1][v]];
        val[k][v] = op(val[k - 1][v], val[k - 1][par[k - 1][v]]);
      }
    }
  }
  int get_par(int v, int h) {
    for (int k = 0; h > 0; h >>= 1, ++k) {
      if (v == -1) break;
      if (h & 1) v = par[k][v];
    }
    return v;
  }
  int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    v = get_par(v, dep[v] - dep[u]);
    if (u == v) return u;
    for (int k = par.size() - 1; k >= 0; --k) {
      if (par[k][u] != par[k][v]) {
        u = par[k][u];
        v = par[k][v];
      }
    }
    return par[0][u];
  }
  T get_val(int v, int h) {
    T res = e;
    for (int k = 0; h > 0; h >>= 1, ++k) {
      if (v == -1) break;
      if (h & 1) {
        res = op(res, val[k][v]);
        v = par[k][v];
      }
    }
    return res;
  }
  T acc(int u, int v) {
    int a = lca(u, v);
    return op(get_val(v, dep[v] - dep[a]), get_val(u, dep[u] - dep[a]));
  }
}

struct UnionFind {
  const int n;
  V<> t; // root ? -sz : par
  UnionFind(int n) : n(n), t(n, -1) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  struct Edge { int u, v, c; };
  V<Edge> es(m);
  for (int i = 0; i < m; ++i) {
    int u, v, c; cin >> u >> v >> c, --u, --v;
    es[i] = {u, v, c};
  }
  UnionFind uf(n);
  VV<LCA::Edge> g(n);
  V<> idx(m);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return es[i].c < es[j].c; });
  V<> rest;
  for (int i : idx) {
    Edge e = es[i];
    if (uf.same(e.u, e.v)) {
      rest.push_back(i);
      continue;
    }
    uf.unite(e.u, e.v);
    g[e.u].emplace_back(LCA::Edge{e.v, e.c});
    g[e.v].emplace_back(LCA::Edge{e.u, e.c});
  }
  LCA::init(g, 0);
  sort(begin(rest), end(rest));
  for (int i : rest) {
    cout << LCA::acc(es[i].u, es[i].v) << '\n';
  }
}