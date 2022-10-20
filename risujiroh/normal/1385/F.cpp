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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
      ++deg[u];
      ++deg[v];
    }
    if (k == 1) {
      cout << n - 1 << '\n';
      continue;
    }
    vector<set<int>> se(n);
    for (int v = 0; v < n; ++v) {
      if (deg[v] != 1) continue;
      for (int u : g[v]) {
        se[u].insert(v);
      }
    }
    // DEBUG(se);
    priority_queue<pair<int, int>> pq;
    for (int v = 0; v < n; ++v) {
      pq.emplace(size(se[v]), v);
    }
    int res = 0;
    while (not empty(pq)) {
      auto [sz, v] = pq.top();
      pq.pop();
      if (sz != (int)size(se[v])) continue;
      if (sz < k) break;
      ++res;
      for (int _ = k; _--; ) {
        int u = *begin(se[v]);
        --deg[v];
        --deg[u];
        se[v].erase(u);
      }
      pq.emplace(size(se[v]), v);
      if (deg[v] == 1) {
        for (int u : g[v]) {
          se[u].insert(v);
          pq.emplace(size(se[u]), u);
        }
      }
    }
    cout << res << '\n';
  }
}