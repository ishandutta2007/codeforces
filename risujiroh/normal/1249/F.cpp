#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> a(n); for (auto&& e : a) cin >> e;
  VV<> g(n);
  for (int _ = 0; _ < n - 1; ++_) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  VV<> dp(n, V<>(k + 2));
  auto dfs = [&](auto& F, int v, int p) -> void {
    dp[v][0] = a[v];
    for (int u : g[v]) if (u != p) {
      F(F, u, v);
      V<> ndp = dp[v];
      for (int i = 0; i <= k + 1; ++i) for (int j = i; j <= k + 1; ++j) {
        ndp[i] = max(ndp[i], dp[v][j] + dp[u][max({k - j, i - 1, 0})]);
      }
      dp[v] = ndp;
      for (int i = k + 1; i; --i) {
        dp[v][i - 1] = max(dp[v][i - 1], dp[v][i]);
      }
    }
  };
  dfs(dfs, 0, -1);
  cout << *max_element(begin(dp[0]), end(dp[0])) << '\n';
}