#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  struct Edge { int to, id; };
  VV<Edge> g(n);
  V<> d(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].emplace_back(Edge{v, i});
    g[v].emplace_back(Edge{u, i});
    ++d[u], ++d[v];
  }
  V<> vs(n);
  iota(begin(vs), end(vs), 0);
  sort(begin(vs), end(vs), [&](int u, int v) { return d[u] > d[v]; });
  int r = d[vs[k]];
  V<> res(n - 1);
  auto dfs = [&](const auto& dfs, int v, int p, int x) -> void {
    for (const auto& e : g[v]) if (e.to != p) {
      x = (x + 1) % r;
      res[e.id] = x;
      dfs(dfs, e.to, v, x);
    }
  };
  dfs(dfs, 0, -1, -1);
  cout << r << '\n';
  for (int i = 0; i < n - 1; ++i) {
    cout << res[i] + 1 << " \n"[i == n - 2];
  }
}