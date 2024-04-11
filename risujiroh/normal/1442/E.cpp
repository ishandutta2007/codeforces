#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    vector<vector<int>> g(n);
    for (int _ = n - 1; _--;) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<int> d(n);
    auto dfs = [&](auto self, int v, int p, int x) -> void {
      assert(x == 1 or x == 2);
      for (int u : g[v]) {
        if (u == p) continue;
        if (a[u] == 0) {
          d[u] = d[v];
          self(self, u, v, x);
        } else {
          d[u] = d[v] + (a[u] != x);
          self(self, u, v, a[u]);
        }
      }
    };

    int s = find(begin(a), end(a), 1) - begin(a);
    if (s == n) {
      cout << "1\n";
      continue;
    }
    dfs(dfs, s, -1, a[s]);

    int mx = -1, f = -1;
    for (int v = 0; v < n; ++v)
      if (a[v] and d[v] > mx) {
        mx = d[v];
        f = v;
      }
    assert(mx == *max_element(begin(d), end(d)));

    d[f] = 0;
    dfs(dfs, f, -1, a[f]);

    cout << (*max_element(begin(d), end(d)) + 3) / 2 << '\n';
  }
}