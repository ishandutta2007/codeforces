#include <bits/stdc++.h>
using namespace std;
#define M 1000010

const int mod = 1e9 + 7;
typedef pair <int, int> PII;

PII p[M];
int n, nx, k, f[M], rev[M], fac[M];
int l[M], r[M], c[M], px[M];

int modpow(int x, int n) {
  int rt = 1;
  while (n) {
    if (n & 1) rt = 1LL * rt * x % mod;
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return rt;
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &k);

  fac[0] = 1; rev[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
    rev[i] = modpow(fac[i], mod - 2);
  }
  for (int i = k; i <= n; i++) {
    f[i] = 1LL * fac[i] * rev[k] % mod * rev[i - k] % mod;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    r[i]++; px[nx++] = l[i], px[nx++] = r[i];
  }
  sort(px, px + nx); nx = unique(px, px + nx) - px;
  for (int i = 0; i < n; i++) {
    c[lower_bound(px, px + nx, l[i]) - px]++;
    c[lower_bound(px, px + nx, r[i]) - px]--;
  }
  int cur = 0, ans = 0;
  for (int i = 0; i < nx - 1; i ++) {
    cur += c[i];
    ans += (1LL * f[cur] * (px[i + 1] - px[i]) % mod);
    ans %= mod;
  }
  printf("%d\n", ans);
}