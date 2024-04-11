#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 2005;
const int mod = 998244353;

int n, a, b, f[N], g[N], p[N], q[N], h[N][N];

inline int Qow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod) {
    if (y & 1) {
      r = 1LL * r * x % mod;
    }
  }
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(a), Read(b), a = 1LL * a * Qow(b, mod - 2) % mod, b = (mod + 1 - a) % mod, p[0] = q[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p[i] = 1LL * p[i - 1] * a % mod;
    q[i] = 1LL * q[i - 1] * b % mod;
  }
  for (int i = 0; i <= n; ++i) {
    h[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      h[i][j] = (1LL * h[i - 1][j] * q[j] + 1LL * h[i - 1][j - 1] * p[i - j]) % mod;
    }
  }
  for (int i = 1; i <= n; ++i) {
    g[i] = 1;
    for (int j = 1; j < i; ++j) {
      g[i] = (g[i] - 1LL * g[j] * h[i][j] % mod + mod) % mod;
    }
  }
  for (int i = 2; i <= n; ++i) {
    int sum = 0, tmp = 0;
    for (int j = 1; j < i; ++j) {
      sum = (1LL * g[j] * h[i][j] % mod * (j * (i - j) + (j * (j - 1) >> 1) + f[j] + f[i - j]) + sum) % mod;
    }
    sum = (1LL * g[i] * (i * (i - 1) >> 1) + sum) % mod;
    f[i] = 1LL * sum * Qow(mod + 1 - g[i], mod - 2) % mod;
  }
  printf("%d\n", f[n]);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}