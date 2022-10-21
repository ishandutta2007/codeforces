#include <bits/stdc++.h>
using namespace std;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  int n; cin >> n;
  struct Edge { int to, c; };
  VV<Edge> g(n);
  for (int _ = 0; _ < n - 1; ++_) {
    int u, v, c; cin >> u >> v >> c, --u, --v;
    g[u].emplace_back(Edge{v, c});
    g[v].emplace_back(Edge{u, c});
  }
  if (any_of(begin(g), end(g), [](const auto& es) { return es.size() == 2; })) {
    cout << "NO\n";
    return 0;
  }
  auto get_leaves = [&](int v, int p) -> V<> {
    if (g[v].size() == 1) return {v};
    auto dfs = [&](const auto& dfs, int v, int p) -> int {
      if (g[v].size() == 1) return v;
      for (const auto& e : g[v]) if (e.to != p) {
        return dfs(dfs, e.to, v);
      }
    };
    V<> res;
    for (const auto& e : g[v]) if (e.to != p) {
      res.push_back(dfs(dfs, e.to, v));
    }
    while (res.size() > 2) res.pop_back();
    return res;
  };
  VV<> res;
  for (int v = 0; v < n; ++v) for (const auto& e : g[v]) if (v < e.to) {
    V<> a = get_leaves(v, e.to);
    V<> b = get_leaves(e.to, v);
    if (a.size() < b.size()) swap(a, b);
    if (b.size() == 2) {
      res.emplace_back(V<>{a[0], b[1], e.c / 2});
      res.emplace_back(V<>{a[1], b[0], e.c / 2});
      res.emplace_back(V<>{a[0], a[1], -e.c / 2});
      res.emplace_back(V<>{b[0], b[1], -e.c / 2});
    } else if (a.size() == 2) {
      res.emplace_back(V<>{a[0], b[0], e.c / 2});
      res.emplace_back(V<>{a[1], b[0], e.c / 2});
      res.emplace_back(V<>{a[0], a[1], -e.c / 2});
    } else {
      res.emplace_back(V<>{a[0], b[0], e.c});
    }
  }
  cout << "YES\n";
  cout << res.size() << '\n';
  for (const auto& e : res) cout << e[0] + 1 << ' ' << e[1] + 1 << ' ' << e[2] << '\n';
}