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
    for (int v = 1; v < n; ++v) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(v);
    }
    vector<int> l(n), r(n);
    for (int v = 0; v < n; ++v) {
      cin >> l[v] >> r[v];
    }

    int ans = 0;
    vector<int> a(n);

    auto dfs = [&](auto self, int v) -> void {
      using i64 = long long;
      i64 s = 0;
      for (int u : g[v]) {
        self(self, u);
        s += a[u];
      }
      if (l[v] <= s) {
        a[v] = min(i64(r[v]), s);
      } else {
        ++ans;
        a[v] = r[v];
      }
    };
    dfs(dfs, 0);

    cout << ans << '\n';
  }
}