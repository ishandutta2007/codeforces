#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> vis(n);
  vector<int> dep(n), prv(n, -1);
  auto dfs = [&](auto&& self, int v) -> void {
    assert(not vis[v]);
    vis[v] = true;
    for (int to : g[v]) {
      if (vis[to]) {
        if (2 <= dep[v] - dep[to] and dep[v] - dep[to] < k) {
          cout << "2\n";
          cout << dep[v] - dep[to] + 1 << '\n';
          cout << v + 1;
          while (true) {
            v = prv[v];
            cout << ' ' << v + 1;
            if (v == to) break;
          }
          cout << '\n';
          exit(0);
        }
      } else {
        dep[to] = dep[v] + 1;
        prv[to] = v;
        self(self, to);
      }
    }
  };
  dfs(dfs, 0);
  DEBUG(dep);
  DEBUG(prv);
  cout << "1\n";
  int v = max_element(begin(dep), end(dep)) - begin(dep);
  if (dep[v] >= k - 1) {
    cout << v + 1;
    for (int _ = (k + 1) / 2 - 1; _--; ) {
      v = prv[prv[v]];
      cout << ' ' << v + 1;
    }
    cout << '\n';
  } else {
    vector<int> cnt(2);
    for (int v = 0; v < n; ++v) {
      ++cnt[dep[v] & 1];
    }
    int p = max_element(begin(cnt), end(cnt)) - begin(cnt);
    int rest = (k + 1) / 2;
    bool first = true;
    for (int v = 0; v < n; ++v) {
      if ((dep[v] & 1) == p) {
        if (not exchange(first, false)) {
          cout << ' ';
        }
        cout << v + 1;
        if (--rest == 0) break;
      }
    }
    cout << '\n';
  }
}