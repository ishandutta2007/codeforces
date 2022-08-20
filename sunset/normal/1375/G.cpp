#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    cin >> v >> u;
    v--; u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  int c = 0;
  function<void(int, int, int)> dfs = [&](int v, int p, int w) {
    if (w) {
      c++;
    }
    for (int u : g[v]) {
      if (u != p) {
        dfs(u, v, !w);
      }
    }
  };
  dfs(0, -1, 0);
  cout << min(c, n - c) - 1 << "\n";
  return 0;
}