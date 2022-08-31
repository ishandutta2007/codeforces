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
  vector<vector<double>> p(n, vector<double>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      p[i][j] = x / 100.0;
    }
  }
  vector<double> goes(n, 1), stay(n, 1), dist(n, 1e9);
  vector<bool> vis(n);
  dist[n - 1] = 0;
  for (int i = 0; i < n; ++i) {
    int v = -1;
    for (int u = 0; u < n; ++u) {
      if (!vis[u] && (v == -1 || dist[u] < dist[v])) {
        v = u;
      }
    }
    vis[v] = true;
    for (int u = 0; u < n; ++u) {
      if (!vis[u] && p[u][v]) {
        goes[u] += p[u][v] * stay[u] * dist[v];
        stay[u] *= 1 - p[u][v];
        dist[u] = goes[u] / (1 - stay[u]);
      }
    }
  }
  cout << fixed << setprecision(9) << dist[0] << "\n";
  return 0;
}