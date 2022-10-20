#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <complex>
#include <tuple>
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

using cp = complex<double>;
const double pi = acos(-1);

cp root[N];

cp MUL(const cp &a, const cp &b) {
  double x = a.real(), y = a.imag(), u = b.real(), v = b.imag();
  return cp(x * u - y * v, x * v + y * u);
}

void init_roots() {
  for (int i = N / 2; i; i >>= 1) {
    double theta = pi / i;
    for (int j = 0; j < i; ++j)
      root[i + j] = polar(1.0, j * theta);
  }
}
void DIF(cp *a, int n) {
  for (int l = n, k = l / 2; k; l >>= 1, k >>= 1) {
    cp *w = root + k;
    for (cp *i = a, *t = a + n; i != t; i += l)
      for (int j = 0; j < k; ++j) {
        cp t = i[j];
        i[j] += i[j + k];
        i[j + k] = MUL((t - i[j + k]), w[j]);
      }
  }
}
void DIT(cp *a, int n) {
  for (int l = 2, k = 1; k < n; l <<= 1, k <<= 1) {
    cp *w = root + k;
    for (cp *i = a, *t = a + n; i != t; i += l)
      for (int j = 0; j < k; ++j) {
        cp t = MUL(i[j + k], w[j]);
        i[j + k] = i[j] - t;
        i[j] += t;
      }
  }
  double iv = 1.0 / n;
  reverse(a + 1, a + n);
  for (int i = 0; i < n; ++i)
    a[i] *= iv;
}

int a[N], b[N];
int mxa[N], mxb[N];
int mna[N], mnb[N];

cp f[N], g[N], h[N];
ll smx[N], smn[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  init_roots();
  int n, m, qc;
  read(n, m, qc);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  for (int i = 1; i <= m; ++i)
    read(b[i]);
  for (int i = 1; i < n; ++i)
    tie(mna[i], mxa[i]) = minmax(a[i], a[i + 1]);
  for (int i = 1; i < m; ++i)
    tie(mnb[i], mxb[i]) = minmax(b[i], b[i + 1]);

  ll sum = 0;

  // max (white)
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= n; ++i)
    f[a[i]] += 1;
  for (int i = 1; i < n; ++i)
    f[mxa[i]] -= 1;
  for (int i = 1; i <= m; ++i)
    g[b[i]] += 1;
  for (int i = 1; i < m; ++i)
    g[mxb[i]] -= 1;
  DIF(f, N); DIF(g, N);
  for (int i = 0; i < N; ++i)
    f[i] *= g[i];
  DIT(f, N);
  sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += llround(f[i].real());
    smx[i] = sum;
  }

  // min (black)
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= n; ++i)
    f[a[i]] += 1;
  for (int i = 1; i < n; ++i)
    f[mna[i]] -= 1;
  for (int i = 1; i <= m; ++i)
    g[b[i]] += 1;
  for (int i = 1; i < m; ++i)
    g[mnb[i]] -= 1;
  DIF(f, N); DIF(g, N);
  for (int i = 0; i < N; ++i)
    f[i] *= g[i];
  DIT(f, N);
  sum = 0;
  for (int i = N - 1; i >= 0; --i) {
    sum += llround(f[i].real());
    smn[i] = sum;
  }

  while (qc--) {
    int x;
    read(x);
    printf("%lld\n", smn[x] - smx[x - 1]);
  }
  return 0;
}