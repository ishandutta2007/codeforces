#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector g(n, vector(n, 0));
  while (m--) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    g[i][j] = g[j][i] = 1;
  }
  if (g[0][n - 1]) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) g[i][j] ^= 1;
  }
  assert(g[0][n - 1] == 0);

  constexpr int inf = 0x3f3f3f3f;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (g[i][j]) continue;
      g[i][j] = inf;
    }

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

  int ans = g[0][n - 1];
  if (ans == inf) ans = -1;
  cout << ans << '\n';
}