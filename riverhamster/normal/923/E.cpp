#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 998244353;
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

const int N = 262144;
int w[N + 3], iw[N + 3], rev[N + 3], Inv[N + 3], last = 0;

void init() {
  w[0] = 1; w[1] = power(3, (M - 1) / N);
  iw[0] = 1; iw[1] = inv(w[1]);
  for (int i = 2; i < N / 2; ++i) w[i] = mul(w[i - 1], w[1]);
  for (int i = 2; i < N / 2; ++i) iw[i] = mul(iw[i - 1], iw[1]);
  Inv[1] = 1;
  for (int i = 2; i <= N; ++i)
    Inv[i] = M - mul(M / i, Inv[M % i]);
}
void make_rev(int n) {
  if (last == n) return;
  last = n;
  int d = __builtin_ctz(n) - 1;
  for (int i = 1; i < n; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << d);
}
void dft(int *a, int n, int *w = ::w) {
  make_rev(n);
  for (int i = 1; i < n; ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int l = 2, k = 1; k < n; k <<= 1, l <<= 1) {
    int step = N / l;
    for (int i = 0; i < n; i += l)
      for (int j = 0, p = 0; j < k; ++j, p += step) {
        int x = a[i | j], y = mul(a[i | j | k], w[p]);
        a[i | j] = add(x, y); a[i | j | k] = sub(x, y);
      }
  }
}
void idft(int *a, int n) {
  dft(a, n, iw);
  int in = inv(n);
  for (int i = 0; i < n; ++i) a[i] = mul(a[i], in);
}
void idft(int *a, int n, int pres) {
  dft(a, n, iw);
  int in = inv(n);
  for (int i = 0; i < pres; ++i) a[i] = mul(a[i], in);
  fill(a + pres, a + n, 0);
}
void dot(int *a, int *b, int n) {
  for (int i = 0; i < n; ++i)
    a[i] = mul(a[i], b[i]);
}
int length(int x) {
  int l = 1;
  while (l < x) l <<= 1;
  return l;
}

int fac[N], ifac[N];
int f[N], g[N], p[N];

int main() {
  init();
  int n;
  long long m;
  scanf("%d%lld", &n, &m); m %= (M - 1);
  for (int i = 0; i <= n; ++i)
    scanf("%d", p + i);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
  for (int i = 0; i <= n; ++i) f[i] = mul(fac[i], p[i]);
  reverse_copy(ifac, ifac + n + 1, g);
  int len = length(2 * (n + 2));
  dft(f, len); dft(g, len); dot(f, g, len); idft(f, len);
  for (int i = 0; i <= n; ++i) g[i] = mul(f[i + n], power(i + 1, M - 1 - m));
  fill(g + n + 1, g + len, 0);
  for (int i = 0; i <= n; ++i)
    f[n - i] = ((i & 1) ? sub(0, ifac[i]) : ifac[i]);
  fill(f + n + 1, f + len, 0);
  dft(f, len); dft(g, len); dot(f, g, len); idft(f, len);
  for (int i = 0; i <= n; ++i)
    printf("%d ", mul(f[i + n], ifac[i]));
  putchar('\n');
  return 0;
}