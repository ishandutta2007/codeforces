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
  vector<vector<int>> g(n);
  vector<int> from(m), to(m), directed(m);
  for (int i = 0; i < m; ++i) {
    cin >> from[i] >> to[i] >> directed[i];
    --from[i]; --to[i];
    g[from[i]].push_back(to[i]);
    g[to[i]].push_back(from[i]);
  }
  vector<int> color(n, -1);
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1) {
      function<void(int)> dfs = [&](int v) {
        for (int u : g[v]) {
          if (color[u] == -1) {
            color[u] = !color[v];
            dfs(u);
          } else if (color[u] == color[v]) {
            cout << "NO" << "\n";
            exit(0);
          }
        }
      };
      color[i] = 0;
      dfs(i);
    }
  }
  vector<vector<pair<int, int>>> g2(n);
  for (int i = 0; i < m; ++i) {
    g2[from[i]].emplace_back(to[i], 1);
    g2[to[i]].emplace_back(from[i], directed[i] ? -1 : 1);
  }
  vector<int> res;
  int ans = -1;
  for (int s = 0; s < n; ++s) {
    vector<int> dist(n, 0x3f3f3f3f);
    vector<int> cnt(n);
    vector<bool> in(n);
    queue<int> que;
    dist[s] = 0;
    in[s] = true;
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      in[v] = false;
      for (auto e : g2[v]) {
        int u = e.first, w = e.second;
        if (dist[u] > dist[v] + w) {
          dist[u] = dist[v] + w;
          if (++cnt[u] > n) {
            cout << "NO" << "\n";
            return 0;
          }
          if (!in[u]) {
            in[u] = true;
            que.push(u);
          }
        }
      }
    }
    if (ans < *max_element(dist.begin(), dist.end()) - *min_element(dist.begin(), dist.end())) {
      ans = *max_element(dist.begin(), dist.end()) - *min_element(dist.begin(), dist.end());
      res = dist;
    }
  }
  cout << "YES" << "\n";
  cout << ans << "\n";
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << res[i] + n;
  }
  cout << "\n";
  return 0;
}