#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    VV<> g(n);
    for (int _ = 0; _ < n - 1; ++_) {
      int u, v; cin >> u >> v, --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int r = -1;
    for (int v = 0; v < n; ++v) if (g[v].size() == 1) {
      r = v;
      break;
    }
    V<> dp(n), par(n);
    auto dfs = [&](auto F, int v, int p) -> void {
      par[v] = p;
      dp[v] = 1;
      int mx = -1;
      for (int u : g[v]) if (u != p) {
        ++dp[v];
        F(F, u, v);
        mx = max(mx, dp[u]);
      }
      if (mx != -1) {
        dp[v] += mx - 1;
      }
    };
    dfs(dfs, r, -1);
    int res = dp[r];
    for (int v = 0; v < n; ++v) if (g[v].size() >= 2) {
      V<> a;
      for (int u : g[v]) if (u != par[v]) {
        a.push_back(dp[u]);
      }
      if (a.size() < 2) continue;
      sort(rbegin(a), rend(a));
      res = max(res, 1 + (int)g[v].size() + (a[0] - 1) + (a[1] - 1));
    }
    cout << res << '\n';
  }
}