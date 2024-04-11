#include <bits/stdc++.h>
using namespace std;
#define M 1000010

const int mod = 1e9 + 7;

int p[M], fac[M], q[M], rev[M], n, m;

int modpow(int x, int n) {
  int rt = 1;
  while (n) {
    if (n & 1) rt = 1LL * rt * x % mod;
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return rt;
}

int C(int x, int y) {
  return (1LL * fac[x] * rev[y] % mod * rev[x - y] % mod);
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  p[0] = q[0] = fac[0] = rev[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = 1LL * m * p[i - 1] % mod;
    q[i] = 1LL * (m - 1) * q[i - 1] % mod;
    fac[i] = 1LL * i * fac[i - 1] % mod;
  }
  rev[n] = modpow(fac[n], mod - 2);
  for (int i = n - 1; i; i--) rev[i] = 1LL * rev[i + 1] * (i + 1) % mod;
  int ans = 0, cur = p[n];
  for (int i = 0; i <= n; i++) {
    ans = (ans + 1LL * cur * p[i]) % mod;
    int tp = 1LL * C(n, i) * q[n - i] % mod;
    cur = (cur - tp + mod) % mod;
  }
  cout << ans << endl;
}