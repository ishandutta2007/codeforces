#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> sz(n);
  V<lint> dp(n);
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    sz[v] = 1;
    for (int w : g[v]) if (w != p) {
      dfs(dfs, w, v);
      sz[v] += sz[w];
      dp[v] += dp[w];
    }
    dp[v] += sz[v];
  };
  dfs(dfs, 0, -1);
  V<lint> ndp(n, n);
  auto ndfs = [&](const auto& ndfs, int v, int p) -> void {
    for (int w : g[v]) if (w != p) {
      ndp[v] += dp[w];
    }
    if (p != -1) ndp[v] += ndp[p] - dp[v] - sz[v];
    for (int w : g[v]) if (w != p) ndfs(ndfs, w, v);
  };
  ndfs(ndfs, 0, -1);
  cout << *max_element(begin(ndp), end(ndp)) << '\n';
}