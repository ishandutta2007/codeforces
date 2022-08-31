#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s; --t;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    --v; --u;
    g[v].emplace_back(u, w);
    g[u].emplace_back(v, w);
  }
  auto dijkstra = [&](int src) {
    priority_queue<pair<long long, int>> q;
    vector<long long> dist(n, 1ll << 60);
    vector<bool> used(n);
    dist[src] = 0;
    q.emplace(-dist[src], src);
    while (!q.empty()) {
      int v = q.top().second;
      q.pop();
      if (used[v]) {
        continue;
      }
      for (auto e : g[v]) {
        int u = e.first, w = e.second;
        if (dist[u] > dist[v] + w) {
          dist[u] = dist[v] + w;
          q.emplace(-dist[u], u);
        }
      }
    }
    vector<long long> d = dist;
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      res[i] = lower_bound(d.begin(), d.end(), dist[i]) - d.begin();
    }
    return res;
  };
  vector<int> ds = dijkstra(s), dt = dijkstra(t);
  vector<vector<long long>> sum(n + 1, vector<long long>(n + 1));
  vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    sum[ds[i]][dt[i]] += w[i];
    cnt[ds[i]][dt[i]] += 1;
  }
  for (int i = n - 1; ~i; --i) {
    for (int j = n - 1; ~j; --j) {
      sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
      cnt[i][j] += cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
    }
  }
  vector<vector<long long>> foo(n + 1, vector<long long>(n + 1));
  vector<vector<long long>> bar(n + 1, vector<long long>(n + 1));
  for (int i = n - 1; ~i; --i) {
    for (int j = n - 1; ~j; --j) {
      if (cnt[i][j] != cnt[i + 1][j]) {
        foo[i][j] = sum[i][j] - sum[i + 1][j] + max(foo[i + 1][j], -bar[i + 1][j]);
      } else {
        foo[i][j] = foo[i + 1][j];
      }
      if (cnt[i][j] != cnt[i][j + 1]) {
        bar[i][j] = sum[i][j] - sum[i][j + 1] + max(-foo[i][j + 1], bar[i][j + 1]);
      } else {
        bar[i][j] = bar[i][j + 1];
      }
    }
  }
  cout << (foo[0][0] > 0 ? "Break a heart" : foo[0][0] < 0 ? "Cry" : "Flowers") << "\n";
  return 0;
}