#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;

const int N = 1 << 18, M = 998244353;
using ll = long long;

int fac[N], ifac[N];

class poly : public vector<int> { using vector<int>::vector; };

inline int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = 1LL * x * x % M) if (y & 1) p = 1LL * p * x % M;
  return p;
}
inline int inv(int x) { return power(x, M - 2); }
void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[n] = power(fac[n], M - 2);
  for (int i = n - 1; i >= 0; --i) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % M;
}
int C(int n, int m) { return 1LL * fac[n] * ifac[m] % M * ifac[n - m] % M; }

int A[N], B[N];
int w[N], iw[N], rev[N], last = 0, _w[N], Inv[N + 1];

void polyinit() {
  auto calc = [](int *w, int *iw, int N) {
    w[0] = 1; iw[0] = 1;
    w[1] = power(3, (M - 1) / N); iw[1] = power(w[1], M - 2);
    for (int i = 2; i < N / 2; ++i) w[i] = 1LL * w[i - 1] * w[1] % M;
    for (int i = 2; i < N / 2; ++i) iw[i] = 1LL * iw[i - 1] * iw[1] % M;
  };
  int *_w = w, *_iw = iw;
  for (int n = N; n > 1; n >>= 1) calc(_w, _iw, n), _w += n / 2, _iw += n / 2;
  Inv[1] = 1;
  for (int i = 2; i <= N; ++i) Inv[i] = M - ll(M / i) * Inv[M % i] % M;
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
  for (int i = 0; i < n; ++i) a[i] = (ll)a[i] * b[i] % M;
}
int length(int n) {
  int l = 1;
  while (l < n) l <<= 1;
  return l;
}

poly operator*(const poly &f, const poly &g) {
  poly h(f.size() + g.size() - 1);
  int l = length(h.size());
  fill(A + f.size(), A + l, 0); fill(B + g.size(), B + l, 0);
  copy(f.begin(), f.end(), A); copy(g.begin(), g.end(), B);
  dft(A, l); dft(B, l);
  for (int i = 0; i < l; ++i) A[i] = 1LL * A[i] * B[i] % M;
  dft(A, l, iw);
  int in = power(l, M - 2);
  for (size_t i = 0; i < h.size(); ++i)
    h[i] = 1LL * A[i] * in % M;
  return h;
}

poly inverse(const poly &f, int n, int SIZE = -1) {
  poly g = {inv(f[0])};
  if (SIZE == -1) g.resize(n);
  else g.resize(SIZE);
  for (int len = 1; len < n; len <<= 1) {
    int cu = min(len * 2, (int)f.size());
    copy_n(f.begin(), cu, A); fill(A + cu, A + len * 4, 0);
    copy_n(g.begin(), len, B); fill(B + len, B + len * 4, 0);
    dft(A, len * 4); dft(B, len * 4);
    for (int j = 0, li = len * 4; j < li; ++j)
      A[j] = (2 * B[j] - (ll)B[j] * B[j] % M * A[j]) % M, A[j] += M & (A[j] >> 31);
    dft(A, len * 4, iw);
    int invN = inv(len * 4);
    for (int j = len, li = min(len * 2, n); j < li; ++j) g[j] = (ll)A[j] * invN % M;
  }
  return g;
}

poly ln(const poly &f, int n, int SIZE = -1) {
  int len = length(n + min(n, (int)f.size() - 1) - 1);
  poly g = inverse(f, n, max(len, SIZE));
  int li = min((int)f.size() - 1, n);
  for (int i = 0; i < li; ++i) A[i] = (ll)f[i + 1] * (i + 1) % M;
  fill(A + li, A + len, 0);
  dft(A, len); dft(g.data(), len); dot(A, g.data(), len);
  dft(A, len, iw);
  g[0] = 0;
  int invN = inv(len);
  for (int i = 1; i < n; ++i) g[i] = (ll)A[i - 1] * Inv[i] % M * invN % M;
  if (SIZE == -1) g.resize(n);
  else g.resize(SIZE);
  return g;
}

poly exp(const poly &f, int n) {
  poly g = {1}; g.resize(n);
  for (int len = 1; len < n; len <<= 1) {
    int up = min(len * 2, n);
    poly l = ln(g, up);
    int li = min((int)f.size(), up);
    for (int j = 0; j < li; ++j) A[j] = sub(f[j], l[j]);
    for (int j = li; j < up; ++j) A[j] = sub(0, l[j]);
    A[0] = A[0] + 1 == M ? 0 : A[0] + 1;
    fill(A + up, A + len * 4, 0);
    copy_n(g.begin(), len, B);
    fill(B + len, B + len * 4, 0);
    dft(A, len * 4); dft(B, len * 4); dot(A, B, len * 4); dft(A, len * 4, iw);
    int invN = inv(len * 4);
    for (int i = len, li = min(len * 2, n); i < li; ++i) g[i] = (ll)A[i] * invN % M;
  }
  return g;
}

poly power(const poly &f, int k, int n) {
  assert(f[0] == 1);
  poly l = ln(f, n);
  for (int &x : l) x = (ll)x * k % M;
  return exp(l, n);
}

int main() {
  polyinit();
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  prefac(k);
  poly f(k + 1);
  int invm = inv(m);
  f[0] = 1;
  for (int i = 1; i <= k; ++i)
    f[i] = (ll)invm * ifac[i] % M;
  printf("%lld\n", (ll)fac[k] * power(f, n, k + 1)[k] % M);
  return 0;
}