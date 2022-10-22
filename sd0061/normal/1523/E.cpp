#include <bits/stdc++.h>
const int N = 100005;
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

void work() {
  int n, K, res = 1, delta = 1;
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; ++i) {
    delta = 1LL * delta * inv[n - i + 1] % Q * i % Q;
    if (i + (i - 1) * (K - 1) <= n) {
      res += 1LL * delta * Combination(n - (K - 1) * (i - 1), i) % Q;
      res %= Q;
    } else {
      break;
    }
  }
  printf("%d\n", res);
}

int main() {
  InitCombination(N - 1);
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}