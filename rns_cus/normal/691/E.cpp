#include <bits/stdc++.h>
using namespace std;
#define M 110
const int mod = 1e9 + 7;
typedef long long LL;

int a[M][M], b[M][M], c[M][M], n;
LL p[M], m;

bool can(int i, int j) {
  LL x = p[i] ^ p[j];
  return (__builtin_popcountll(x) % 3 == 0);
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %I64d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%I64d", p + i);
  if (m == 1) return printf("%d\n", n), 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (can(i, j)) a[i][j] = 1;
    }
  }
  m--;

  for (int i = 1; i <= n; i++) b[i][i] = 1;

  while (m) {
    if (m & 1) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          c[i][j] = 0;
          for (int k = 1; k <= n; k++) {
            c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
          }
        }
      }
      for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) b[i][j] = c[i][j];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        c[i][j] = 0;
        for (int k = 1; k <= n; k++) {
          c[i][j] = (c[i][j] + 1LL * a[i][k] * a[k][j]) % mod;
        }
      }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = c[i][j];
    m >>= 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
    ans += b[i][j]; if (ans >= mod) ans -= mod;
  }
  cout << ans << endl;
}