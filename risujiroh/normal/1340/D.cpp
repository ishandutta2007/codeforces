#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int m = -1;
  for (int v = 0; v < n; ++v) {
    m = max(m, (int)size(g[v]));
  }
  vector<pair<int, int>> res;
  auto dfs = [&](auto&& self, int v, int p, int s) -> void {
    res.emplace_back(v, s);
    int nxt = s + 1;
    for (int u : g[v]) {
      if (u != p) {
        if (nxt <= m) {
          self(self, u, v, nxt);
          res.emplace_back(v, nxt);
        } else {
          nxt -= size(g[v]);
          res.emplace_back(v, nxt - 1);
          self(self, u, v, nxt);
          res.emplace_back(v, nxt);
        }
        ++nxt;
      }
    }
    res.emplace_back(v, s - 1);
  };
  res.emplace_back(0, 0);
  for (int i = 0; i < (int)size(g[0]); ++i) {
    dfs(dfs, g[0][i], 0, i + 1);
    res.emplace_back(0, i + 1);
  }
  res.erase(unique(begin(res), end(res)), end(res));
  cout << size(res) << '\n';
  for (auto [v, t] : res) {
    cout << v + 1 << ' ' << t << '\n';
  }
}