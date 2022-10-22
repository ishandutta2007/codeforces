#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

int n;
int64 a[N], b[N], f[18][N];

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    b[i] = a[i + 1] - a[i];
    f[0][i] = b[i];
  }
  int res = 1;
  --n;
  int rk = 0;
  for (int k = 1; 1 << k <= n; ++k) {
    for (int i = 0; i + (1 << k) - 1 < n; ++i) {
      f[k][i] = std::gcd(f[k - 1][i], f[k - 1][i + (1 << k - 1)]);
    }
    rk = k;
  }
  for (int i = 0; i < n; ++i) {
    int64 g = 0;
    int j = i;
    for (int k = rk; k >= 0; --k) {
      if (j + (1 << k) - 1 < n && std::gcd(g, f[k][j]) > 1) {
        g = std::gcd(g, f[k][j]);
        j += 1 << k;
      }
    }
    res = std::max(res, j - i + 1);
  }
  printf("%d\n", res);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}