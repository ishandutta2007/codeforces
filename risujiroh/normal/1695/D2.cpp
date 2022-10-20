#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int e = 0; e < n - 1; ++e) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    bool is_path = true;
    for (int v = 0; v < n; ++v) {
      is_path &= size(g[v]) <= 2;
    }
    if (is_path) {
      cout << (1 < n) << '\n';
      continue;
    }

    vector<int> f(n);
    for (int v = 0; v < n; ++v) {
      if (size(g[v]) == 1) {
        int prv = v;
        int cur = g[v][0];
        while (size(g[cur]) == 2) {
          int nxt = g[cur][0] ^ g[cur][1] ^ prv;
          prv = cur;
          cur = nxt;
        }
        ++f[cur];
      }
    }

    int ans = 0;
    for (int e : f) {
      ans += max(e - 1, 0);
    }
    cout << ans << '\n';
  }
}