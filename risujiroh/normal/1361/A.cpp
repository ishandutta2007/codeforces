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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> t(n);
  for (auto&& e : t) cin >> e;
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int u, int v) {
    return t[u] < t[v];
  });
  vector<int> s(n);
  for (int v : ord) {
    set<int> se;
    for (int u : g[v]) {
      if (s[u]) {
        se.insert(s[u]);
      }
    }
    for (int x = 1; ; ++x) {
      if (not se.count(x)) {
        s[v] = x;
        break;
      }
    }
  }
  if (s == t) {
    for (int i = 0; i < n; ++i) {
      cout << ord[i] + 1 << " \n"[i == n - 1];
    }
  } else {
    cout << "-1\n";
  }
}