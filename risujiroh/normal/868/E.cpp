#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int _ = n - 1; _--;) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  vector dist(n, vector<int>(n));
  for (int s = 0; s < n; ++s) {
    auto dfs = [&](auto self, int v, int p) -> void {
      for (auto&& [u, w] : g[v]) {
        if (u == p) continue;
        dist[s][u] = dist[s][v] + w;
        self(self, u, v);
      }
    };
    dfs(dfs, s, -1);
  }
  vector<array<int, 51>> f(n);
  for (int x = 1; x <= 50; ++x)
    for (int r = 0; r < n; ++r) {
      if (size(g[r]) > 1) continue;
      auto check = [&](int m) -> bool {
        int sum = 0;
        for (int v = 0; v < n; ++v) {
          if (size(g[v]) > 1) continue;
          int a = 0;
          while (a < x && dist[r][v] + f[v][x - a - 1] >= m) ++a;
          sum += a;
        }
        return sum >= x;
      };
      int ok = 0, ng = 1e6;
      while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
      }
      f[r][x] = ok;
    }
  int s, m;
  cin >> s >> m;
  --s;
  if (size(g[s]) == 1) {
    cout << f[s][m] << '\n';
    exit(0);
  }
  auto get_i = [&](int x) -> int {
    for (int i = 0; i < int(size(g[s])); ++i)
      if (int v = g[s][i].first; dist[s][v] + dist[v][x] == dist[s][x]) return i;
    assert(false);
  };
  vector<int> cnt(size(g[s]));
  for (int _ = m; _--;) {
    int x;
    cin >> x;
    --x;
    ++cnt[get_i(x)];
  }
  auto check = [&](int mid) -> bool {
    vector<int> sum(size(g[s]));
    for (int v = 0; v < n; ++v) {
      if (size(g[v]) > 1) continue;
      int a = 0;
      while (a < m && dist[s][v] + f[v][m - a - 1] >= mid) ++a;
      sum[get_i(v)] += a;
    }
    for (int i = 0; i < int(size(g[s])); ++i)
      if (sum[i] < cnt[i]) return false;
    return true;
  };
  int ok = 0, ng = 1e6;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}