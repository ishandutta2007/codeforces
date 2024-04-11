#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;
using ull = unsigned long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 1 << 18;
const int M = 998244353;

int power(int x, int y, int p = 1) {
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}
int inv(int x) { return power(x, M - 2); }

using poly = vector<int>;

int A[N], B[N];
int w[N], rev[N << 1], last = 0, Inv[N + 1];
int fac[N], ifac[N];

void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = (ll)fac[i - 1] * i % M;
  ifac[n] = inv(fac[n]);
  for (int i = n; i; --i)
    ifac[i - 1] = (ll)ifac[i] * i % M;
}
int binom(int n, int m) { return (ll)fac[n] * ifac[m] % M * ifac[n - m ] % M; }

void polyinit() {
  auto calc = [](int *w, int N) {
    w[0] = 1;
    w[1] = power(3, (M - 1) / N);
    for (int i = 2; i < N / 2; ++i) w[i] = 1LL * w[i - 1] * w[1] % M;
  };
  auto make_rev = [](int *rev, int N) {
    int l = __builtin_ctz(N) - 1;
    for (int i = 1; i < N; ++i)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l);
  };
  for (int n = N; n > 1; n >>= 1) {
    calc(w + N - n, n);
    make_rev(rev + 2 * (N - n), n);
  }
  Inv[1] = 1;
  for (int i = 2; i <= N; ++i) Inv[i] = M - ll(M / i) * Inv[M % i] % M;
}

void DFT(int *a, int lenA, int *des, int n) {
  static ull f[N];
  int *Rev = rev + 2 * (N - n);
  for (int i = 0; i < lenA; ++i) f[Rev[i]] = a[i];
  for (int i = lenA; i < n; ++i) f[Rev[i]] = 0;
  ull *i, *t, *p, *q;
  int *omega, *tw;
  for (int l = 2, k = 1; k < n; l <<= 1, k <<= 1) {
    int *W = w + N - l;
    for (i = f, t = f + n; i != t; i += l)
      for (p = i, q = i + k, omega = W, tw = W + k; omega != tw; ++p, ++q, ++omega) {
        ull x = *p, y = *q * *omega % M;
        *p = x + y; *q = x - y + M;
      }
  }
  for (int i = 0; i < n; ++i) des[i] = f[i] % M;
}
void DFT(int *a, int n) { DFT(a, n, a, n); }
void IDFT(int *a, int n) {
  DFT(a, n);
  reverse(a + 1, a + n);
  int invN = inv(n);
  for (int *p = a, *t = a + n; p != t; ++p) *p = (ll)*p * invN % M;
}
void dot(int *a, int *b, int n) {
  for (int *p = a, *q = b, *t = a + n; p != t; ++p, ++q)
    *p = (ll)*p * *q % M;
}
int length(int n) {
  int l = 1;
  while (l < n) l <<= 1;
  return l;
}

poly operator*(const poly &f, const poly &g) {
  int L = length(f.size() + g.size() - 1);
  fill(A + f.size(), A + L, 0); fill(B + g.size(), B + L, 0);
  copy(f.begin(), f.end(), A); copy(g.begin(), g.end(), B);
  DFT(A, L); DFT(B, L); dot(A, B, L); IDFT(A, L);
  return poly(A, A + f.size() - 1 + g.size());
}

int deg[N], cnt[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  polyinit();
  int n;
  read(n);
  prefac(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    ++deg[u]; ++deg[v];
  }
  for (int i = 1; i <= n; ++i)
    ++cnt[deg[i] - (i != 1)];
  poly p = {1};
  for (int i = n; i >= 0; --i) {
    if (!cnt[i]) continue;
    poly q(cnt[i] + 1);
    q[0] = 1;
    for (int j = 1; j <= cnt[i]; ++j)
      q[j] = (ll)q[j - 1] * i % M;
    for (int j = 1; j < cnt[i]; ++j)
      q[j] = (ll)q[j] * binom(cnt[i], j) % M;
    p = p * q;
  }
  int ans = 0;
  for (int i = 0; i < (int)p.size(); ++i)
    ans = (ans + (ll)p[i] * fac[n - i] * (i & 1 ? -1 : 1)) % M;
  ans = (ans + M) % M;
  printf("%d\n", ans);
  return 0;
}