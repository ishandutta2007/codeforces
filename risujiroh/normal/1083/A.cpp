#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> w(n); for (int i = 0; i < n; ++i) cin >> w[i];
  struct Edge { int to, c; };
  VV<Edge> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, c; cin >> u >> v >> c, --u, --v;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  V<lint> dp(n);
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    dp[v] = w[v];
    for (const Edge& e : g[v]) if (e.to != p) {
      dfs(dfs, e.to, v);
      dp[v] = max(dp[v], dp[e.to] - e.c + w[v]);
    }
  };
  dfs(dfs, 0, -1);
  lint res = 0;
  auto dfs2 = [&](const auto& dfs2, int v, int p) -> void {
    res = max(res, dp[v]);
    V<lint> a;
    for (const Edge& e : g[v]) if (e.to != p) {
      dfs2(dfs2, e.to, v);
      a.push_back(dp[e.to] - e.c);
    }
    if (a.size() >= 2) {
      sort(rbegin(a), rend(a));
      res = max(res, a[0] + w[v] + a[1]);
    }
  };
  dfs2(dfs2, 0, -1);
  cout << res << '\n';
}