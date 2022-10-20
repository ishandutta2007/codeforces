#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 5005, M = 998244353;
int A[N][N], C[N][N], fact[N];
long long res[N];

int main() {
  int n;
  scanf("%d", &n);
  A[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    A[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      A[i][j] = (1LL * A[i - 1][j] * (j + 1) + 1LL * A[i - 1][j - 1] * (i - j)) % M;
  }
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
  }
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i - 1] * i % M;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      res[j] += 1LL * C[n][i] * A[i][j - 1] % M * fact[n - i] % M;
  for (int i = 1; i <= n; ++i)
    printf("%lld ", res[i] % M);
  return 0;
}