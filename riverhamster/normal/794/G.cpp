#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

const int M = 1000000007;
inline int add(int x, int y) {return x+y>=M ? x+y-M : x+y;}
template<class ...Args> inline int add(int x, int y, Args... args) {return add(add(x, y), args...);}
inline int sub(int x, int y) {return x-y<0 ? x-y+M : x-y;}
inline int mul(int x, int y) {return 1LL * x * y % M;}
template<class ...Args> inline int mul(int x, int y, Args... args) {return mul(mul(x, y), args...);}
inline void inc(int &x, int y=1) {x += y; if(x >= M) x -= M;}
inline void dec(int &x, int y=1) {x -= y; if(x < 0) x += M;}
inline int power(int x, int y){
  int res = 1;
  for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x){return power(x, M - 2);}

const int N = 1000005;
char c[N], d[N];
int n;
int lc, ld, ca = 0, cb = 0, cq = 0, da = 0, db = 0, dq = 0;
int p2[N];

int gcd(int x, int y) {
  int t;
  while (y) t = x, x = y, y = t % y;
  return x;
}

int fac[N * 2], ifac[N * 2];
void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}
int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return mul(fac[n], ifac[m], ifac[n - m]);
}

bool np[N];
int p[N], mu[N], pc = 0;
void sieve_mu(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!np[i]) p[++pc] = i, mu[i] = M - 1;
    for (int j = 1; j <= pc && i * p[j] <= n; ++j) {
      np[i * p[j]] = true;
      if (i % p[j] == 0) {
        mu[i * p[j]] = 0;
        break;
      }
      mu[i * p[j]] = sub(0, mu[i]);
    }
  }
}

int main() {
  scanf("%s%s%d", c, d, &n);
  lc = strlen(c), ld = strlen(d);
  p2[0] = 1;
  for (int i = 1, li = max({n + 1, lc, ld}); i <= li; ++i)
    p2[i] = add(p2[i - 1], p2[i - 1]);
  prefac(lc + ld + 1);
  for (int i = 0; i < lc; ++i)
    if (c[i] == 'A') ++ca;
    else if (c[i] == 'B') ++cb;
    else ++cq;
  for (int i = 0; i < ld; ++i)
    if (d[i] == 'A') ++da;
    else if (d[i] == 'B') ++db;
    else ++dq;
  int res = 0;
  for (int p = -1000000; p <= 1000000; ++p) { // ca - da
    int x = p + ld - lc, y = p;
    if (x < 0) x = -x, y = -y;
    if (x <= 0 || y <= 0) continue;
    int g = gcd(x, y);
    x /= g; y /= g;
    int P = n / max(x, y);
    inc(res, mul(sub(p2[P + 1], 2), C(cq + dq, dq + da + p - ca)));
  }
  if (lc == ld) {
    int ways = 0;
    sieve_mu(n);
    for (int d = 1; d <= n; ++d) {
      int now = 0;
      for (int g = 1, li = n / d; g <= li; ++g)
        inc(now, mul(p2[g], n / (d * g), n / (d * g)));
      inc(ways, mul(now, mu[d]));
    }
    inc(res, mul(ways, C(cq + dq, dq + da - ca)));
    int eq = 0;
    for (int i = 0; i < lc; ++i)
      if (c[i] != '?' && d[i] != '?' && c[i] != d[i]) {
        eq = -1;
        break;
      }
      else
        eq += int(c[i] == '?' && d[i] == '?');
    if (eq != -1) {
      eq = p2[eq];
      dec(res, mul(ways, eq));
      inc(res, mul(eq, power(sub(p2[n + 1], 2), 2)));
    }
  }
  printf("%d\n", res);
  return 0;
}