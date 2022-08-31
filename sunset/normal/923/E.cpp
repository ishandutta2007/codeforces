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

const int N = 262145;
const int M = 20;
const int G = 3;
const int mod = 998244353;

namespace Polynomial {
  int D, L, W[M], R[N];

  inline int Qow(int x, int y) {
    int r = 1;
    for (; y; y >>= 1, x = 1LL * x * x % mod) {
      if (y & 1) {
        r = 1LL * r * x % mod;
      }
    }
    return r;
  }

  inline int Inv(int x) {
    return Qow(x, mod - 2);
  }

  inline void Ini(int l) {
    for (D = 1, L = 0; D < l; D <<= 1, ++L);
    for (int i = 1; i < D; ++i) {
      R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
    }
    W[0] = Qow(G, mod - 1 >> L);
    for (int i = 1; i < L; ++i) {
      W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
    }
  }

  inline void IniInv() {
    W[0] = Inv(W[0]);
    for (int i = 1; i < L; ++i) {
      W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
    }
  }

  inline void DFT(int *x) {
    for (int i = 0; i < D; ++i) {
      if (i < R[i]) {
        swap(x[i], x[R[i]]);
      }
    }
    for (int i = 1, l = L - 1; i < D; i <<= 1, --l) {
      for (int j = 0; j < D; j += i << 1) {
        for (int k = 0, w = 1, u, v; k < i; ++k, w = 1uLL * w * W[l] % mod) {
          u = x[j + k], v = 1LL * w * x[j + k + i] % mod;
          x[j + k] = (u + v) % mod, x[j + k + i] = (u - v + mod) % mod;
        }
      }
    }
  }

  inline void Cpy(int *x, int n, int *y, int m) {
    for (int i = 0; i < m; ++i) {
      y[i] = i < n ? x[i] : 0;
    }
  }

  inline void Mul(int *a, int n, int *b, int m, int *r) {
    static int x[N], y[N];
    Ini(n + m - 1);
    Cpy(a, n, x, D), Cpy(b, m, y, D);
    DFT(x), DFT(y);
    for (int i = 0; i < D; ++i) {
      x[i] = 1LL * x[i] * y[i] % mod;
    }
    IniInv(), DFT(x);
    for (int i = 0, v = Inv(D); i < n + m - 1; ++i) {
      r[i] = 1LL * v * x[i] % mod;
    }
  }
}

int n, a[N], b[N], fac[N], fnv[N], inv[N];
LL m;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), ++n, m %= (mod - 1), fac[0] = fac[1] = inv[0] = inv[1] = fnv[0] = fnv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
    inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    fnv[i] = 1LL * fnv[i - 1] * inv[i] % mod;
  }
  for (int i = 0; i < n; ++i) {
    Read(a[i]), a[i] = 1LL * a[i] * fac[i] % mod;
  }
  reverse(a, a + n);
  Polynomial::Mul(a, n, fnv, n, a);
  reverse(a, a + n);
  for (int i = 0; i < n; ++i) {
    a[i] = 1LL * a[i] * Polynomial::Qow(inv[i + 1], m) % mod;
    if (i & 1) {
      a[i] = (mod - a[i]) % mod;
    }
  }
  reverse(a, a + n);
  Polynomial::Mul(a, n, fnv, n, a);
  reverse(a, a + n);
  for (int i = 0; i < n; ++i) {
    a[i] = 1LL * a[i] * fnv[i] % mod;
    if (i & 1) {
      a[i] = (mod - a[i]) % mod;
    }
    printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}