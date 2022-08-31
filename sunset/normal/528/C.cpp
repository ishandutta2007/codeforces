#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    g[v].emplace_back(u, i * 2);
    g[u].emplace_back(v, i * 2 + 1);
  }
  for (int i = 0, j = -1; i < n; ++i) {
    if ((int) g[i].size() % 2 == 1) {
      if (j == -1) {
        j = i;
      } else {
        g[i].emplace_back(j, m * 2);
        g[j].emplace_back(i, m * 2 + 1);
        j = -1;
        ++m;
      }
    }
  }
  if (m % 2 == 1) {
    g[0].emplace_back(0, m * 2);
    g[0].emplace_back(0, m * 2 + 1);
    ++m;
  }
  cout << m << "\n";
  vector<int> ptr(n);
  vector<bool> vis(m);
  bool type = false;
  function<void(int)> dfs = [&](int v) {
    for (int& i = ptr[v]; i < (int) g[v].size(); ++i) {
      int u = g[v][i].first, e = g[v][i].second, w = e / 2;
      if (!vis[w]) {
        vis[w] = true;
        dfs(u);
        if (type) {
          cout << v + 1 << " " << u + 1 << "\n";
        } else {
          cout << u + 1 << " " << v + 1 << "\n";
        }
        type = !type;
      }
    }
  };
  dfs(0);
  return 0;
}