#include <bits/stdc++.h>

const int N = 2222, M = N << 1, RX = 998244353;

int n, m, ans, f[N][N], C[M][M], s[N][N];

int comb(int n, int m) {return !n ? !m : C[n + m - 1][m];}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i <= n + m; i++) C[i][0] = 1;
  for (int i = 1; i <= n + m; i++)
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % RX;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f[i][j] = 1ll * comb(i, j) * comb(n - i + 1, j - 1) % RX;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      s[i][j] = (s[i - 1][j] + f[i][j]) % RX;
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      ans = (2ll * f[i][j] * s[n - i][m - j] + ans) % RX;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f[i][j] = 1ll * comb(j, i) * comb(m - j + 1, i - 1) % RX;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      s[i][j] = (s[i][j - 1] + f[i][j]) % RX;
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      ans = (2ll * f[i][j] * s[n - i][m - j - 1] + ans) % RX;
  return std::cout << ans << std::endl, 0;
}