#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, b;
  cin >> n >> b;
  vector<int> c(n), d(n);
  vector<vector<int>> ch(n);
  for (int v = 0; v < n; ++v) {
    cin >> c[v] >> d[v];
    if (v) {
      int p;
      cin >> p;
      --p;
      ch[p].push_back(v);
    }
  }
  auto merge = [&](const auto& x, const auto& y) {
    int nx = size(x[0]) - 1, ny = size(y[0]) - 1;
    int nz = nx + ny;
    vector z(2, vector(nz + 1, inf<long long>));
    for (int f : {0, 1}) {
      for (int i = 0; i <= nx; ++i) {
        for (int g : {0, 1}) {
          if (not f and g) continue;
          for (int j = 0; j <= ny; ++j) {
            chmin(z[f or g][i + j], x[f][i] + y[g][j]);
          }
        }
      }
    }
    return z;
  };
  vector<vector<vector<long long>>> dp(n);
  auto dfs = [&](auto&& self, int v) -> void {
    dp[v] = {{0, c[v]}, {inf<long long>, c[v] - d[v]}};
    for (int u : ch[v]) {
      self(self, u);
      dp[v] = merge(dp[v], dp[u]);
    }
  };
  dfs(dfs, 0);
  for (int i = n; i >= 0; --i) {
    if (min(dp[0][0][i], dp[0][1][i]) <= b) {
      cout << i << '\n';
      exit(0);
    }
  }
}