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

const int N = 131075;
const int M = 20;
const int G = 3;
const int mod = 998244353;

int n, a, b, D, L, W[M], f[N], R[N], fac[N], inv[N];

inline int Qow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod) {
    if (y & 1) {
      r = 1LL * r * x % mod;
    }
  }
  return r;
}

inline void DFT(int *a) {
  for (int i = 0; i < D; ++i) {
    if (i < R[i]) {
      swap(a[i], a[R[i]]);
    }
  }
  for (int i = 1, l = L - 1; i < D; i <<= 1, --l) {
    for (int j = 0; j < D; j += i << 1) {
      for (int k = 0, w = 1, u, v; k < i; ++k, w = 1LL * w * W[l] % mod) {
        u = a[j + k], v = 1LL * w * a[j + k + i] % mod;
        a[j + k] = (u + v) % mod, a[j + k + i] = (u - v + mod) % mod;
      }
    }
  }
}

inline void Mul(int *a, int n, int *b, int m, int *c) {
  static int f[N], g[N];
  for (D = 1, L = 0; D < n + m - 1; D <<= 1, ++L);
  for (int i = 1; i < D; ++i) {
    R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
  }
  W[0] = Qow(G, mod - 1 >> L);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  for (int i = 0; i < D; ++i) {
    f[i] = i < n ? a[i] : 0;
    g[i] = i < m ? b[i] : 0;
  }
  DFT(f), DFT(g);
  for (int i = 0; i < D; ++i) {
    f[i] = 1LL * f[i] * g[i] % mod;
  }
  W[0] = Qow(W[0], mod - 2);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  DFT(f);
  for (int i = 0, v = Qow(D, mod - 2); i < n + m - 1; ++i) {
    c[i] = 1LL * f[i] * v % mod;
  }
}

inline void Solve(int n) {
  static int a[N], b[N], c[N];
  if (n == 1) {
    f[0] = 0, f[1] = 1;
  } else if (n & 1) {
    Solve(n - 1);
    for (int i = n; i; --i) {
      f[i] = (1LL * f[i] * (n - 1) + f[i - 1]) % mod;
    }
  } else {
    int m = n >> 1;
    Solve(m), b[0] = 1;
    for (int i = 1; i <= m; ++i) {
      b[i] = 1LL * b[i - 1] * m % mod;
    }
    for (int i = 0; i <= m; ++i) {
      a[i] = 1LL * fac[m - i] * f[m - i] % mod, b[i] = 1LL * b[i] * inv[i] % mod;
    }
    Mul(a, m + 1, b, m + 1, c);
    for (int i = 0; i <= m; ++i) {
      a[i] = 1LL * inv[i] * c[m - i] % mod;
    }
    Mul(f, m + 1, a, m + 1, f);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(a), Read(b);
  if (!a || !b || a + b > n + 1) {
    puts("0");
    return 0;
  }
  if (n == 1) {
    puts("1");
    return 0;
  }
  fac[0] = fac[1] = inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
    inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
  }
  for (int i = 2; i <= n; ++i) {
    inv[i] = 1LL * inv[i - 1] * inv[i] % mod;
  }
  Solve(n - 1);
  printf("%d\n", 1LL * f[a + b - 2] * fac[a + b - 2] % mod * inv[a - 1] % mod * inv[b - 1] % mod);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}