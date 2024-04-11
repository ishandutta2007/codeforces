#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5005;
const int MOD = 998244353;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

ll fac[N], inv[N];
int t, n, a[N], f[N][N], tot[N];

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = i * fac[i - 1] % MOD;
  inv[N - 1] = bigMod(fac[N - 1], -1);
  for (int i = N - 1; i; --i) inv[i - 1] = i * inv[i] % MOD;
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = n; i >= 1; --i) {
      tot[i] = 1;
      if (i < n and a[i] == a[i + 1]) tot[i] += tot[i + 1];
    }
    for (int taken = n / 2; taken >= 1; --taken) {
      int keep = 0;
      for (int i = n; i >= 1; --i) {
        if (taken == n / 2) {
          f[i][taken] = i == n;
        } else if (i == n) {
          f[i][taken] = 0;
        } else {
          f[i][taken] = (long long) max(0, i - 2 * taken) * keep % MOD;
        }
        if (i == 1 or a[i] != a[i - 1]) keep = (keep + (long long) tot[i] * f[i][taken + 1]) % MOD;
      }
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
      if (a[i] != a[i - 1]) {
        ans = (ans + (long long) (i - 1) * f[i][1] % MOD * tot[i]) % MOD;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i == 1 or a[i] != a[i - 1]) ans = (long long) ans * inv[tot[i]] % MOD;
    }
    printf("%d\n", ans);
  }
  return 0;
}