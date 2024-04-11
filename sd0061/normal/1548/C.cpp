#include <bits/stdc++.h>
using int64 = long long;
const int N = 30000005;
const int Q = 1e9 + 7;

int I[N], P[N], inv[N];
void InitCombination(int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = 1LL * (Q - Q / i) * inv[Q % i] % Q;
  }
  P[0] = I[0] = 1;
  for (int i = 1; i <= n; ++i) {
    P[i] = 1LL * P[i - 1] * i % Q;
    I[i] = 1LL * I[i - 1] * inv[i] % Q;
  }
}
int Combination(int a, int b) {
  if (a < 0 || b < 0 || b > a) {
    return 0;
  }
  return 1LL * P[a] * I[b] % Q * I[a - b] % Q;
}

int n, m;
int f[N];
void work() {
  scanf("%d%d", &n, &m);
  InitCombination(3 * (n + 1));

  f[0] = n;
  for (int i = 1; i <= n; ++i) {
    f[1] += 3 * i;
    f[1] %= Q;
  }
  for (int i = 2; i <= 3 * n; ++i) {
    f[i] = (0LL + Combination(3 * (n + 1), i + 1) - 3LL * f[i - 1] - f[i - 2] -
            (i == 2)) %
           Q;
    // printf("%d : %d\n", i, f[i]);
    f[i] = (1LL * f[i] % Q + Q) % Q * inv[3] % Q;
    // printf("%d : %d\n", i, f[i]);
  }
  for (int i = 0, x; i < m; ++i) {
    scanf("%d", &x);
    printf("%d\n", f[x]);
  }
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}