#include <cstdio>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

const int N = 4005, K = 39, M = 998244353;

inline int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = 1LL * x * x % M) if (y & 1) p = 1LL * p * x % M;
  return p;
}

int n1, n2, k;
int fac[K * 2 + 5], ifac[K * 2 + 5];

using poly = array<int, K>;
poly polyinv(poly a) {
  poly c;
  c[0] = power(a[0], M - 2);
  for (int i = 1; i <= k; ++i) {
    int s = 0;
    for (int j = 0; j < i; ++j)
      s = (s + 1LL * c[j] * a[i - j]) % M;
    c[i] = 1LL * (M - s) * c[0] % M;
  }
  return c;
}
struct solver {
  poly res;
  vector<int> G[N];
  poly f[N], g[N];
  void dfs1(int x, int fa) {
    g[x][0] = 1;
    for (int v : G[x]) {
      if (v == fa) continue;
      dfs1(v, x);
      for (int i = 0; i < k; ++i)
        g[x][i + 1] = (g[x][i + 1] - f[v][i] + M) % M;
    }
    f[x] = polyinv(g[x]);
  }
  void dfs2(int x, int fa) {
    poly tp;
    for (int v : G[x]) {
      if (v == fa) continue;
      tp = g[x];
      for (int i = 0; i < k; ++i)
        tp[i + 1] = (tp[i + 1] + f[v][i]) % M;
      tp = polyinv(tp);
      for (int i = k; i >= 1; --i) tp[i] = (g[v][i] + M - tp[i - 1]) % M;
      tp[0] = f[v][0];
      g[v] = tp; f[v] = polyinv(tp);
      dfs2(v, x);
    }
  }
  void solve(int n) {
    for (int i = 1; i < n; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      G[u].push_back(v); G[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= k; ++j)
        (res[j] += f[i][j]) %= M;
  }
} t1, t2;

int main() {
  scanf("%d%d%d", &n1, &n2, &k);
  if (k & 1) return puts("0"), 0;
  k /= 2;
  t1.solve(n1); t2.solve(n2);
  fac[0] = 1;
  for (int i = 1; i <= k * 2; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[k * 2] = power(fac[k * 2], M - 2);
  for (int i = k * 2 - 1; i >= 0; --i) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % M;
  int res = 0;
  for (int i = 0; i <= k; ++i)
    res = (res + 1LL * t1.res[i] * t2.res[k - i] % M * fac[k * 2] % M * ifac[i * 2] % M * ifac[k * 2 - i * 2]) % M;
  printf("%d\n", res);
  return 0;
}