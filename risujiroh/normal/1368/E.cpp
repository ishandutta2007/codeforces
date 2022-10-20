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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
    }
    vector<int> d(n), res;
    for (int v = 0; v < n; ++v) {
      if (d[v] == 2) {
        res.push_back(v);
        continue;
      }
      for (int to : g[v]) {
        d[to] = max(d[to], d[v] + 1);
      }
    }
    int k = size(res);
    cout << k << '\n';
    for (int i = 0; i < k; ++i) {
      cout << res[i] + 1 << " \n"[i == k - 1];
    }
  }
}