#include <bits/stdc++.h>
using int64 = long long;
const int N = 6005;

int n, X[N], Y[N];
char g[N][N];

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &X[i], &Y[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int dx = std::abs(X[i] - X[j]);
      int dy = std::abs(Y[i] - Y[j]);
      g[i][j] = g[j][i] = std::__gcd(dx, dy) & 3;
    }
  }
  for (int i = 0; i < n; ++i) {
    X[i] &= 3;
    Y[i] &= 3;
  }
  int64 res[2] = {};
  for (int k = 0; k < n; ++k) {
    int cnt[4][16] = {};
    for (int i = 0; i < n; ++i) {
      if (i != k) {
        int dx = (X[i] - X[k] + 4) & 3;
        int dy = (Y[i] - Y[k] + 4) & 3;
        ++cnt[g[i][k]][dx << 2 | dy];
      }
    }
    for (int b0 = 0; b0 < 4; ++b0) {
      for (int b1 = 0; b1 < 4; ++b1) {
        if ((b1 ^ b0) & 1) {
          continue;
        }
        for (int m0 = 0; m0 < 16; ++m0) {
          for (int m1 = 0; m1 < 16; ++m1) {
            if (!cnt[b0][m0] || !cnt[b1][m1]) {
              continue;
            }
            int dx = ((m0 >> 2) - (m1 >> 2) + 4) & 3;
            int dy = ((m0 & 3) - (m1 & 3) + 4) & 3;
            int b2 = std::__gcd(dx, dy) & 3;
            if (b2 & 1) {
              continue;
            }
            int area =
                std::abs((m0 >> 2) * (m1 & 3) - (m1 >> 2) * (m0 & 3)) & 3;
            if (area == (b0 + b1 + b2) % 4) {
              if (m0 == m1 && b0 == b1) {
                res[b0 & 1] += cnt[b0][m0] * (cnt[b0][m0] - 1);
              } else {
                res[b0 & 1] += cnt[b0][m0] * cnt[b1][m1];
              }
            }
          }
        }
      }
    }
  }
  printf("%lld\n", res[0] / 6 + res[1] / 2);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}