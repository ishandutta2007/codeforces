#include <bits/stdc++.h>
using namespace std;

auto chmin = [](auto&& l, auto r) { return r < l ? l = r, 1 : 0; };

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto&& v : a) {
    for (auto&& e : v) {
      cin >> e;
      --e;
    }
  }
  auto $ = [&](int i, int j = -1) {
    if (j == -1) {
      return n * m + i;
    }
    return i * m + j;
  };
  struct edge {
    int to;
    char w;
  };
  vector<vector<edge>> g(n * m + k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i + 1 < n) {
        g[$(i, j)].emplace_back(edge{$(i + 1, j), 1});
        g[$(i + 1, j)].emplace_back(edge{$(i, j), 1});
      }
      if (j + 1 < m) {
        g[$(i, j)].emplace_back(edge{$(i, j + 1), 1});
        g[$(i, j + 1)].emplace_back(edge{$(i, j), 1});
      }
      g[$(i, j)].emplace_back(edge{$(a[i][j]), 1});
      g[$(a[i][j])].emplace_back(edge{$(i, j), 0});
    }
  }
  auto bfs = [&] {
    vector<vector<int16_t>> res(k, vector<int16_t>(g.size(), 0x3f3f));
    for (int c = 0; c < k; ++c) {
      auto& dist = res[c];
      dist[$(c)] = 0;
      queue<pair<int, int>> que;
      que.emplace(0, $(c));
      while (not que.empty()) {
        int d, v;
        tie(d, v) = que.front();
        que.pop();
        if (d > dist[v]) {
          continue;
        }
        for (auto e : g[v]) {
          if (chmin(dist[e.to], dist[v] + e.w)) {
            que.emplace(dist[e.to], e.to);
          }
        }
      }
    }
    return res;
  };
  auto back = bfs();
  int q;
  cin >> q;
  while (q--) {
    int si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;
    --si, --sj, --ti, --tj;
    int res = abs(ti - si) + abs(tj - sj);
    for (int c = 0; c < k; ++c) {
      chmin(res, back[c][$(si, sj)] + back[c][$(ti, tj)] + 1);
    }
    cout << res << '\n';
  }
}