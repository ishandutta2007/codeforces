#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200005, M = 998244353;
char s[N];
int fac[N], ifac[N];

inline int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = 1LL * x * x % M)
    if (y & 1) p = 1LL * p * x % M;
  return p;
}
void make_factorial(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[n] = power(fac[n], M - 2);
  for (int i = n - 1; i >= 0; --i) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % M;
}
int C(int n, int m) { return 1LL * fac[n] * ifac[m] % M * ifac[n - m] % M; }

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  int F = 0;
  for (int i = 0; i < n; ++i)
    F += s[i] == '?';
  make_factorial(F);
  int Init = n / 2;
  for (int i = 0; i < n; ++i)
    Init -= int(((i & 1) && (s[i] == 'w')) || ((~i & 1) && s[i] == 'b'));
  int res = 0;
  for (int i = Init & 1; i <= F; i += 2)
    res = (res + 1LL * C(F, i) * abs(Init - i)) % M;
  printf("%lld\n", 1LL * res * power(2, M - 1 - F) % M);
  return 0;
}