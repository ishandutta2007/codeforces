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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    --v; --u;
    g[v].emplace_back(u, w);
    g[u].emplace_back(v, w);
  }
  pair<double, int> ans(1e30, -1);
  vector<double> der(n);
  vector<bool> vis(n);
  vector<int> sz(n);
  vector<int> mx(n);
  auto find_root = [&](int r) {
    vector<int> ord;
    function<void(int, int)> dfs = [&](int v, int p) {
      ord.push_back(v);
      sz[v] = 1;
      mx[v] = 0;
      for (auto e : g[v]) {
        int u = e.first;
        if (!vis[u] && u != p) {
          dfs(u, v);
          sz[v] += sz[u];
          mx[v] = max(mx[v], sz[u]);
        }
      }
    };
    dfs(r, -1);
    int res = -1;
    for (int v : ord) {
      mx[v] = max(mx[v], sz[r] - sz[v]);
      if (res == -1 || mx[res] > mx[v]) {
        res = v;
      }
    }
    return res;
  };
  function<void(int)> centroid_decomposition = [&](int v) {
    vis[v = find_root(v)] = true;
    double res = 0;
    function<void(int, int, int, int)> dfs = [&](int v, int p, int d, int r) {
      res += sqrt(d) * d * a[v];
      der[r] += sqrt(d) * a[v];
      for (auto e : g[v]) {
        int u = e.first, w = e.second;
        if (u != p) {
          dfs(u, v, d + w, r);
        }
      }
    };
    double sum = 0;
    for (auto e : g[v]) {
      int u = e.first, w = e.second;
      der[u] = 0;
      dfs(u, v, w, u);
      sum += der[u];
    }
    ans = min(ans, make_pair(res, v));
    for (auto e : g[v]) {
      int u = e.first;
      if (!vis[u] && der[u] * 2 > sum) {
        centroid_decomposition(u);
      }
    }
  };
  centroid_decomposition(0);
  cout << ans.second + 1 << " " << fixed << setprecision(9) << ans.first << "\n";
  return 0;
}