#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct UnionFind {
  const int n;

  UnionFind(int n) : n(n), dat(n, -1) {}

  bool same(int u, int v) {
    assert(0 <= u and u < n);
    assert(0 <= v and v < n);
    return find(u) == find(v);
  }

  int size(int v) {
    assert(0 <= v and v < n);
    return -dat[find(v)];
  }

  void unite(int u, int v) {
    assert(0 <= u and u < n);
    assert(0 <= v and v < n);
    if ((u = find(u)) == (v = find(v))) return;
    if (-dat[u] < -dat[v]) {
      dat[v] += dat[u];
      dat[u] = v;
    } else {
      dat[u] += dat[v];
      dat[v] = u;
    }
  }

private:
  V<> dat; // dat[v] := v ? -size : parent

  int find(int v) {
    return dat[v] < 0 ? v : dat[v] = find(dat[v]);
  }
};

namespace LCA {
  using T = int;
  struct Edge {
    int to;
    T w;
  };
  T op(const T& lhs, const T& rhs) {
    return max(lhs, rhs);
  }
  constexpr T e = 0;

  V<> dep;
  VV<> par;
  VV<T> val;

  void init(const VV<Edge>& g, int r) {
    int n = g.size();
    dep.resize(n);
    assign(par, __lg(2 * n - 1), n, -1);
    assign(val, __lg(2 * n - 1), n, e);
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
    for (int k = 1; k < par.size(); ++k) {
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

struct Edge2 {
  int u, v, w;
  bool operator<(const Edge2& rhs) {
    return w < rhs.w;
  }
};

using namespace LCA;

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<Edge2> es(m);
  for (int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w, --u, --v;
    es[i] = {u, v, w};
  }

  sort(begin(es), end(es));
  UnionFind uf(n);
  VV<Edge> g(n);
  V<Edge2> rest;
  for (const auto& e : es) {
    if (uf.same(e.u, e.v)) {
      rest.push_back(e);
    } else {
      uf.unite(e.u, e.v);
      g[e.u].emplace_back((Edge) {e.v, e.w});
      g[e.v].emplace_back((Edge) {e.u, e.w});
    }
  }

  init(g, 0);
  int res = 0;
  for (const auto& e : rest) {
    res += acc(e.u, e.v) == e.w;
  }
  cout << res << '\n';
}