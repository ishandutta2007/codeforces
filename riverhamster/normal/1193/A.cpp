#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 18, M = 998244353;

inline int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = 1LL * x * x % M)
    if (y & 1) p = 1LL * p * x % M;
  return p;
}
int inv(int x) { return power(x, M - 2); }

int g[N + 1][(1 << N) + 5], f[N + 1][(1 << N) + 5];
int adj[N], uadj[(1 << N) + 5];

void FWT(int *a, int n) {
  for (int w = 2, k = 1; k < (1 << n); w <<= 1, k <<= 1)
    for (int i = 0; i < (1 << n); i += w)
      for (int j = i, li = i + k; j < li; ++j)
        (a[j | k] += a[j]) %= M;
}
void IFWT(int *a, int n) {
  for (int w = 2, k = 1; k < (1 << n); w <<= 1, k <<= 1)
    for (int i = 0; i < (1 << n); i += w)
      for (int j = i, li = i + k; j < li; ++j)
        (a[j | k] -= a[j] - M) %= M;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v); --u; --v;
    adj[u] |= (1 << v); adj[v] |= (1 << u);
  }
  g[0][0] = 1;
  for (int i = 1; i < (1 << n); ++i) {
    int l = __builtin_ctz(i);
    uadj[i] = uadj[i ^ (1 << l)] | adj[l];
    if ((i & uadj[i]) == 0) {
      int pop = __builtin_popcount(i);
      g[pop][i] = pop & 1 ? M - 1 : 1;
    }
  }
  fill(g[0], g[0] + (1 << n), 1);
  fill(f[0], f[0] + (1 << n), 1);
  for (int i = 1; i <= n; ++i) FWT(g[i], n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j)
      for (int k = 0; k < (1 << n); ++k)
        f[i][k] = (f[i][k] - 1LL * f[j][k] * g[i - j][k] % M + M) % M;
    for (int k = 0; k < (1 << n); ++k)
      f[i][k] = 1LL * f[i][k] * f[0][k] % M;
  }
  IFWT(f[n], n);
  printf("%lld\n", 1LL * f[n][(1 << n) - 1] * m % M * ((M + 1) / 2) % M);
  return 0;
}