#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m--) {
    int u, v, t;
    cin >> u >> v >> t;
    --u, --v;
    g[v].emplace_back(u, t);
  }

  constexpr int inf = 0x3f3f3f3f;
  vector seg(2 * n, pair{inf, -1});
  auto update = [&](int i, int val) -> void {
    seg[i += n] = {val, i};
    while (i >>= 1) seg[i] = min(seg[2 * i], seg[2 * i + 1]);
  };

  array<vector<int>, 2> mn;
  mn.fill(vector(n, inf));
  auto get = [&](int v) -> int { return max(mn[0][v], mn[1][v]); };

  mn[0][n - 1] = mn[1][n - 1] = 0;
  update(n - 1, get(n - 1));
  vector<bool> vis(n);
  while (true) {
    auto [dv, v] = seg[1];
    if (dv == inf) break;
    vis[v] = true;
    update(v, inf);
    for (auto [u, t] : g[v]) {
      if (vis[u]) continue;
      mn[t][u] = min(mn[t][u], get(v) + 1);
      if (get(u) < seg[n + u].first) {
        update(u, get(u));
      }
    }
  }

  int dist = get(0);
  if (dist == inf) dist = -1;
  cout << dist << '\n';
  for (int v = 0; v < n; ++v) cout << (mn[0][v] < mn[1][v]);
  cout << '\n';
}