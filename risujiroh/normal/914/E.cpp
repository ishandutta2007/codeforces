#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int _ = n - 1; _--;) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    a[i] = 1 << (c - 'a');
  }
  vector<bool> alive(n, true);
  vector<int> sub(n), nxt(n);
  auto dfs_aux = [&](auto self, int v, int p) -> void {
    sub[v] = 1;
    nxt[v] = -1;
    for (int u : g[v])
      if (alive[u] and u != p) {
        self(self, u, v);
        sub[v] += sub[u];
        if (nxt[v] == -1 or sub[u] > sub[nxt[v]]) nxt[v] = u;
      }
  };
  auto find_centroid = [&](int v) -> int {
    dfs_aux(dfs_aux, v, -1);
    int half = sub[v] / 2;
    while (nxt[v] != -1 and sub[nxt[v]] > half) v = nxt[v];
    return v;
  };
  vector<int64_t> ans(n, 1), cur(n);
  vector<int> freq(1 << 20);
  vector<pair<int, int>> vx;
  vector<int> pv(n);
  auto dfs = [&](auto self, int v, int p, int x) -> void {
    vx.emplace_back(v, x);
    pv[v] = p;
    for (int u : g[v])
      if (alive[u] and u != p) self(self, u, v, x ^ a[u]);
  };
  auto solve = [&](auto self, int c) -> void {
    vector<int> start;
    vx.clear();
    for (int v : g[c])
      if (alive[v]) {
        start.push_back(size(vx));
        dfs(dfs, v, c, a[v]);
      }
    start.push_back(size(vx));
    for (auto&& [v, x] : vx) ++freq[x ^ a[c]];
    for (int z = 0; z < int(size(start)) - 1; ++z) {
      for (int i = start[z]; i < start[z + 1]; ++i) --freq[vx[i].second ^ a[c]];
      for (int i = start[z]; i < start[z + 1]; ++i) {
        auto [v, x] = vx[i];
        cur[v] += freq[x];
        for (int y = 1; y < 1 << 20; y *= 2) cur[v] += freq[x ^ y];
        if (int t = x ^ a[c]; (t & (t - 1)) == 0) ++cur[v], ++cur[c];
      }
      for (int i = start[z]; i < start[z + 1]; ++i) ++freq[vx[i].second ^ a[c]];
    }
    for_each(rbegin(vx), rend(vx), [&](auto&& e) {
      auto [v, x] = e;
      cur[pv[v]] += cur[v];
      ans[v] += cur[v];
      cur[v] = 0;
    });
    ans[c] += cur[c] / 2;
    cur[c] = 0;
    for (auto&& [v, x] : vx) --freq[x ^ a[c]];
    alive[c] = false;
    for (int v : g[c])
      if (alive[v]) self(self, find_centroid(v));
  };
  solve(solve, find_centroid(0));
  for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}