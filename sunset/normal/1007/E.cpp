#include <bits/stdc++.h>

using namespace std;

const int N = 234;
const long long inf = 1ll << 60;

long long a[N], b[N], c[N], sa[N], sb[N], d[N][N][N], g[N][N][N];
int n, t, k;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d %d", &n, &t, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
  }
  ++n;
  a[n] = c[n] = inf;
  for (int i = 1; i <= n; ++i) {
    sa[i] = sa[i - 1] + a[i];
    sb[i] = sb[i - 1] + b[i];
  }
  for (int p = 1; p <= n; ++p) {
    for (int s = 0; s <= t; ++s) {
      for (int z = 0; z < 2; ++z) {
        d[p][s][z] = g[p][s][z] = inf;
        if (s * b[p] + z * a[p] <= c[p] && d[p - 1][s][z] < inf) {
          d[p][s][z] = d[p - 1][s][z];
          long long value = (z * sa[p - 1] + s * sb[p - 1] + k - 1) / k;
          if (value * k <= z * sa[p] + s * sb[p]) {
            g[p][s][z] = value;
          }
        }
        for (int r = 0; r < s; ++r) {
          if (g[p][r][z] < inf) {
            long long m = z * sa[p] + r * sb[p] - k * g[p][r][z];
            long long x = (max(m + (s - r) * b[p] - c[p], 0ll) + k - 1) / k;
            if (x * k <= m && d[p - 1][s - r][0] < inf) {
              d[p][s][z] = min(d[p][s][z], g[p][r][z] + x + d[p - 1][s - r][0]);
              long long value = ((s - r) * sb[p - 1] + k - 1) / k;
              if (value * k <= (s - r) * sb[p] + m - x * k) {
                g[p][s][z] = min(g[p][s][z], g[p][r][z] + x + value);
              }
            }
          }
        }
      }
    }
  }
  printf("%lld\n", d[n][t][1]);
  return 0;
}