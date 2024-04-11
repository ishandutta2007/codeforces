#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int M = 998244353;
int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = 1LL * x * x % M)
    if (y & 1) p = 1LL * p * x % M;
  return p;
}
const int N = 1000005;
int fac[N], ifac[N];
int C(int n, int m) {
  return 1LL * fac[n] * ifac[m] % M * ifac[n - m] % M;
}

int main() {
  int n;
  scanf("%d", &n);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[n] = power(fac[n], M - 2);
  for (int i = n - 1; i >= 0; --i) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % M;
  ll now = 0;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int t = 1LL * C(n, i) * power(3, M - 1 - (1LL * n * i) % (M - 1)) % M * (power(M + 1 - power(3, M - 1 + i - n), n) - 1) % M;
    if (i & 1) now += t;
    else now -= t;
  }
  res = 1LL * now % M * power(3, (1LL * n * n + 1) % (M - 1)) % M;
  (res -= 2LL * power(3, 1LL * n * n % (M - 1)) % M * (power(M + 1 - power(3, M - n), n) - 1) % M) %= M;
  printf("%d\n", (res + M) % M);
  return 0;
}