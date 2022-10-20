#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

namespace LCA {
  using T = lint;
  struct Edge { int to; T w; };
  T op(const T& x, const T& y) { return x + y; }
  constexpr T e = 0;

  V<> dep;
  VV<> par;
  VV<T> val;
  void init(const VV<Edge>& g, int r) {
    int n = g.size();
    dep.resize(n);
    par.assign(__lg(2 * n - 1), V<>(n, -1));
    val.assign(__lg(2 * n - 1), V<T>(n, e));
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

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> w(n); for (auto&& e : w) cin >> e;
  VV<> g(n);
  while (m--) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s; cin >> s, --s;

  V<> deg(n);
  queue<int> que;
  for (int v = 0; v < n; ++v) {
    deg[v] = g[v].size();
    if (deg[v] == 1) {
      que.push(v);
    }
  }
  V<bool> be(n);
  V<> par(n, n);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    be[v] = true;
    for (int u : g[v]) {
      if (be[u]) {
        par[u] = v;
      }
      if (--deg[u] == 1) {
        que.push(u);
      }
    }
  }

  lint res = 0;
  for (int v = 0; v < n; ++v) if (!be[v]) {
    res += w[v];
  }
  if (!be[s]) {
    s = n;
  }

  VV<LCA::Edge> h(n + 1);
  w.push_back(0);
  for (int v = 0; v < n; ++v) if (be[v]) {
    h[v].emplace_back(LCA::Edge{par[v], w[par[v]]});
    h[par[v]].emplace_back(LCA::Edge{v, w[par[v]]});
  }
  LCA::init(h, n);

  V<lint> d(n + 1);
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    for (const auto& e : h[v]) if (e.to != p) {
      d[e.to] = d[v] + w[e.to];
      dfs(dfs, e.to, v);
    }
  };
  d[s] = w[s];
  dfs(dfs, s, -1);
  lint mx = 0;
  for (int v = 0; v <= n; ++v) if (v == n or be[v]) {
    int a = LCA::lca(s, v);
    mx = max(mx, d[v] + LCA::acc(a, n));
  }
  res += mx;
  cout << res << '\n';
}