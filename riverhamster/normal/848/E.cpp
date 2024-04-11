#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

const int N = 1 << 18, M = 998244353;
using ll = long long;

int fac[N], ifac[N];

inline int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = 1LL * x * x % M) if (y & 1) p = 1LL * p * x % M;
  return p;
}
inline int inv(int x) { return power(x, M - 2); }

int A[N], B[N];
int w[N], iw[N], rev[N], last = 0, _w[N];

void polyinit() {
  auto calc = [](int *w, int *iw, int N) {
    w[0] = 1; iw[0] = 1;
    w[1] = power(3, (M - 1) / N); iw[1] = power(w[1], M - 2);
    for (int i = 2; i < N / 2; ++i) w[i] = 1LL * w[i - 1] * w[1] % M;
    for (int i = 2; i < N / 2; ++i) iw[i] = 1LL * iw[i - 1] * iw[1] % M;
  };
  int *_w = w, *_iw = iw;
  for (int n = N; n > 1; n >>= 1) calc(_w, _iw, n), _w += n / 2, _iw += n / 2;
}
void binrev(int n) {
  if (last == n) return;
  last = n;
  int l = __builtin_ctz(n) - 1;
  for (int i = 1; i < n; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l);
}

inline int add(int x, int y) { return x + y >= M ? x + y - M : x + y; }
inline int sub(int x, int y) { return x - y < 0 ? x - y + M : x - y; }
inline void inc(int &x, int y) { x += y; if (x >= M) x -= M; }

void dft(int *a, int n, int *w = ::w) {
  binrev(n);
  for (int i = 1; i < n; ++i)
    if (rev[i] > i) swap(a[i], a[rev[i]]);
  for (int l = 2, k = 1; k < n; l <<= 1, k <<= 1) {
    int *W = w + N - l;
    for (int *i = a, *t = a + n; i != t; i += l)
      for (int *p = i, *q = i + k, *omega = W, *t = W + k; omega != t; ++p, ++q, ++omega) {
        int x = *p, y = (ll)*q * *omega % M;
        *p = add(x, y); *q = sub(x, y);
      }
  }
}
void dot(int *a, int *b, int n) {
  for (int *p = a, *q = b, *t = a + n; p != t; ++p, ++q) *p = (ll)*p * *q % M;
}
int length(int n) {
  int l = __lg(n);
  return (1 << l) == n ? n : (1 << (l + 1));
}

int g[N], sqg[N], sq1g[N], sq2g[N];
int f0[N], f1[N], f2[N];

void conv(int *f, int *ft, int *g, int *gt, int *h, int len) {
  len = length(len);
  copy(f, ft, A); copy(g, gt, B);
  fill(A + (ft - f), A + len, 0); fill(B + (gt - g), B + len, 0);
  dft(A, len); dft(B, len); dot(A, B, len); dft(A, len, iw);
  int invlen = inv(len);
  for (int i = 0; i < len; ++i) h[i] = (ll)A[i] * invlen % M;
}

int tp[N];

void solve(int l, int r) {
  if (r - l <= 64) {
    for (int i = l; i <= r; ++i) {
      inc(f0[i], sqg[i]);
      inc(f1[i], sq1g[i]);
      inc(f2[i], sq2g[i]);
      for (int j = l; j < i; ++j) {
        f0[i] = (f0[i] + (ll)f0[j] * sqg[i - j - 1]) % M;
        f1[i] = (f1[i] + (ll)f0[j] * sq1g[i - j - 1]) % M;
        f2[i] = (f2[i] + (ll)f1[j] * sq1g[i - j - 1]) % M;
      }
      for (int j = l; j < i - 2; ++j) {
        f0[i] = (f0[i] + (ll)f1[j] * sq1g[i - j - 3]) % M;
        f1[i] = (f1[i] + (ll)f1[j] * sq2g[i - j - 3]) % M;
        f2[i] = (f2[i] + (ll)f2[j] * sq2g[i - j - 3]) % M;
      }
    }
    return;
  }
  int mid = (l + r) >> 1;
  solve(l, mid);

  conv(f0 + l, f0 + mid + 1, sqg, sqg + r - l, tp, r - l + 1);
  for (int i = mid + 1; i <= r; ++i) inc(f0[i], tp[i - l - 1]);
  conv(f1 + l, f1 + mid + 1, sq1g, sq1g + r - l - 2, tp, r - l + 1);
  for (int i = mid + 1; i <= r; ++i) inc(f0[i], tp[i - l - 3]);

  conv(f0 + l, f0 + mid + 1, sq1g, sq1g + r - l, tp, r - l + 1);
  for (int i = mid + 1; i <= r; ++i) inc(f1[i], tp[i - l - 1]);
  conv(f1 + l, f1 + mid + 1, sq2g, sq2g + r - l - 2, tp, r - l + 1);
  for (int i = mid + 1; i <= r; ++i) inc(f1[i], tp[i - l - 3]);

  conv(f1 + l, f1 + mid + 1, sq1g, sq1g + r - l, tp, r - l + 1);
  for (int i = mid + 1; i <= r; ++i) inc(f2[i], tp[i - l - 1]);
  conv(f2 + l, f2 + mid + 1, sq2g, sq2g + r - l - 2, tp, r - l + 1);
  for (int i = mid + 1; i <= r; ++i) inc(f2[i], tp[i - l - 3]);

  solve(mid + 1, r);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  polyinit();
  int n;
  scanf("%d", &n);
  g[0] = g[2] = 1;
  for (int i = 4; i <= n; i += 2) g[i] = add(g[i - 2], g[i - 4]);
  for (int i = 2; i <= n; i += 2) sqg[i] = (ll)g[i] * i % M * i % M;
  for (int i = 0; i <= n; i += 2) sq1g[i] = (ll)g[i] * (i + 1) % M * (i + 1) % M;
  for (int i = 0; i <= n; i += 2) sq2g[i] = (ll)g[i] * (i + 2) % M * (i + 2) % M;
  solve(0, n);
  int res = (ll)(g[n - 1] + g[n - 3]) * (n - 1) % M * (n - 1) % M * n % M;
  for (int j = 1; j < n; ++j) {
    res = (res + (ll)sqg[j - 1] * f0[n - j - 1] % M * j) % M;
    if (j >= 2 && n - j >= 2) res = (res + 2LL * sq1g[j - 2] * f1[n - j - 2] % M * j) % M;
    if (j >= 3 && n - j >= 3) res = (res + (ll)sq2g[j - 3] * f2[n - j - 3] % M * j) % M;
  }
  printf("%d\n", res);
  return 0;
}