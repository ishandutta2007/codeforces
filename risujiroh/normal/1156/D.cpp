#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  struct Edge { int to, c; };
  VV<Edge> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, c; cin >> u >> v >> c, --u, --v;
    g[u].emplace_back(Edge{v, c});
    g[v].emplace_back(Edge{u, c});
  }
  V<lint> dp0(n), dp1(n), dp01(n), dp10(n);
  V<> par(n);
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    par[v] = p;
    for (const auto& e : g[v]) if (e.to != p) {
      dfs(dfs, e.to, v);
      if (e.c) {
        dp1[v] += 1 + dp1[e.to];
        dp10[v] += dp0[e.to] + dp10[e.to];
      } else {
        dp0[v] += 1 + dp0[e.to];
        dp01[v] += dp1[e.to] + dp01[e.to];
      }
    }
  };
  dfs(dfs, 0, -1);
  lint res = 0;
  for (int i = 0; i < n; ++i) {
    res += 2 * (dp0[i] + dp1[i]) + dp01[i] + dp10[i];
    for (const auto& e : g[i]) if (e.to != par[i]) {
      if (e.c) {
        res += (1 + dp0[e.to] + dp1[e.to] + dp10[e.to]) * (dp1[i] - dp1[e.to] - 1);
      } else {
        res += (1 + dp0[e.to]) * (dp0[i] + dp1[i] + dp01[i] - (dp0[e.to] + dp1[e.to] + dp01[e.to]) - 1);
      }
    }
  }
  cout << res << '\n';
}