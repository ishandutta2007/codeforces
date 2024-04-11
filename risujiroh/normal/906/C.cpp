#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u] |= 1 << v;
    g[v] |= 1 << u;
  }
  int bt = 0;
  int mn = n + 1, mbt = -1;
  auto dfs = [&](auto&& self, int i) -> void {
    if (i == n) {
      for (int j = 0; j < n; ++j) {
        if (__builtin_popcount(g[j]) < n - 1) {
          return;
        }
      }
      if (chmin(mn, __builtin_popcount(bt))) {
        mbt = bt;
      }
      return;
    }
    self(self, i + 1);
    bt |= 1 << i;
    auto _g = g;
    for (int j = 0; j < n; ++j) {
      if (g[i] >> j & 1) {
        g[j] |= g[i];
      }
    }
    self(self, i + 1);
    g = _g;
    bt &= ~(1 << i);
  };
  dfs(dfs, 0);
  cout << mn << '\n';
  int p = 0;
  for (int i = 0; i < n; ++i) {
    if (mbt >> i & 1) {
      cout << i + 1 << " \n"[p == mn - 1];
      ++p;
    }
  }
}