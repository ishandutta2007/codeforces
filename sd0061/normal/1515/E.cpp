#include <bits/stdc++.h>
const int N = 405;
int n, Q;
int P[N], I[N], f[N][N], pow2[N];
inline void add(int &A, int B) {
  A += B;
  if (A >= Q) {
    A -= Q;
  }
}

int main() {
  scanf("%d%d", &n, &Q);
  I[0] = 1;
  for (int i = 1; i <= n; ++i) {
    I[i] = i == 1 ? 1 : 1LL * (Q - Q / i) * I[Q % i] % Q;
  }
  P[0] = P[1] = 1;
  pow2[0] = 1, pow2[1] = 2;
  for (int i = 2; i <= n; ++i) {
    P[i] = 1LL * P[i - 1] * i % Q;
    I[i] = 1LL * I[i - 1] * I[i] % Q;
    pow2[i] = pow2[i - 1] * 2 % Q;
    // printf("%d %d %d\n", P[i], I[i], pow2[i]);
  }
  f[0][0] = 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (f[i][j] == 0) {
        continue;
      }
      int pos = i ? i + 2 : 1;
      for (int k = 1; pos + k <= n + 1; ++k) {
        add(f[k + pos - 1][j + k], 1LL * f[i][j] * pow2[k - 1] % Q * I[k] % Q);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    add(ans, 1LL * f[n][i] * P[i] % Q);
  }
  printf("%d\n", ans);
}