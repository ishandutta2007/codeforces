#include <bits/stdc++.h>
using int64 = long long;
const int N = 14;
const int Q = 1e9 + 7;

int n, a[N];
int p[N][N];       // i -> j;
int g[N][1 << N];  // i -> subset

int inverse(int x) {
  return x == 1 ? 1 : 1LL * (Q - Q / x) * inverse(Q % x) % Q;
}

int f[1 << N];

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        p[i][j] = 1LL * a[j] * inverse(a[i] + a[j]) % Q;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 1 << n; ++j) {
      g[i][j] = 1;
      for (int k = 0; k < n; ++k) {
        if (j >> k & 1) {
          g[i][j] = 1LL * g[i][j] * p[k][i] % Q;
        }
      }
    }
  }

  int res = 0;
  int mask = (1 << n) - 1;
  for (int i = 1; i < 1 << n; ++i) {
    int popcount = __builtin_popcount(i);
    f[i] = 1;
    int between = 1;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        between = 1LL * between * g[j][mask ^ i] % Q;
      }
    }
    if (popcount > 1) {
      for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
        int x = 1;
        for (int k = 0; k < n; ++k) {
          if (j >> k & 1) {
            x = 1LL * x * g[k][i ^ j] % Q;
          }
        }
        f[i] = (f[i] + Q - 1LL * f[j] * x % Q) % Q;
      }
    }
    res += 1LL * f[i] * between % Q * popcount % Q;
    res %= Q;
  }
  printf("%d\n", res);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}