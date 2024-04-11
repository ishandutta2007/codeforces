#include "bits/stdc++.h"

const int N = 505;
using int64 = long long;

int n, m, K, r[N][N], d[N][N];
int f[N][N][11];

int go(int x, int y, int k) {
  if (x < 0 || x >= n || y < 0 || y >= m || k < 0) {
    return 1 << 30;
  }
  if (k == 0) {
    return 0;
  }
  int& res = f[x][y][k];
  if (res != -1) {
    return res;
  }
  res = 1 << 30;
  if (x > 0) {
    res = std::min(res, go(x - 1, y, k - 1) + d[x - 1][y]);
  }
  if (x + 1 < n) {
    res = std::min(res, go(x + 1, y, k - 1) + d[x][y]);
  }
  if (y > 0) {
    res = std::min(res, go(x, y - 1, k - 1) + r[x][y - 1]);
  }
  if (y + 1 < m) {
    res = std::min(res, go(x, y + 1, k - 1) + r[x][y]);
  }
  return res;
}

int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      scanf("%d", &r[i][j]);
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &d[i][j]);
    }
  }
  memset(f, -1, sizeof(f));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int res = 1 << 30;
      if (K & 1) {
        res = -1;
      } else {
        for (int k = 1; k <= K; ++k) {
          if (K % (k + k) == 0) {
            res = std::min(res, go(i, j, k) * (K / k));
          }
        }
      }
      printf("%d%c", res, " \n"[j + 1 == m]);
    }
  }
}