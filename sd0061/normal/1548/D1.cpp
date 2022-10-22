#include <bits/stdc++.h>
using int64 = long long;
const int N = 6005;

int n, a[N], b[N];
int g[16][16];
int cnt[16];
void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    ++cnt[(a[i] % 4) * 4 + (b[i] % 4)];
  }
  for (int i = 0; i < 16; ++i) {
    for (int j = 0; j <= i; ++j) {
      int ai = i / 4;
      int aj = j / 4;
      int bi = i % 4;
      int bj = j % 4;
      int dx = std::abs(ai - aj);
      int dy = std::abs(bi - bj);
      g[i][j] = g[j][i] = std::gcd(dx, dy) % 4;
    }
  }
  // for (int i = 0; i < 16; ++i) {
  //   printf("%d %d\n", i, cnt[i]);
  // }
  int64 res = 0;
  for (int i = 0; i < 16; ++i) {
    if ((g[i][i] * 3) % 4 == 0) {
      res += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
    }
  }
  for (int i = 0; i < 16; ++i) {
    int delta = cnt[i] * (cnt[i] - 1) / 2;
    for (int j = 0; j < 16; ++j) {
      if (i == j || (g[i][i] + 2 * g[i][j]) % 4 != 0) {
        continue;
      }
      // printf("%d %d %d %d\n", i, j, delta, cnt[j]);
      res += 1LL * cnt[j] * delta;
    }
  }
  for (int i = 0; i < 16; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k < j; ++k) {
        if ((g[i][j] + g[j][k] + g[k][i]) % 4 == 0) {
          res += 1LL * cnt[i] * cnt[j] * cnt[k];
        }
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}