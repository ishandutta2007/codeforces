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

const int N = 1048580;
const int M = 20;
const int G = 3;
const int mod = 998244353;

int D, L, W[M], R[N], fac[N], fnv[N], inv[N];

inline int Qow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod) {
    if (y & 1) {
      r = 1LL * r * x % mod;
    }
  }
  return r;
}

inline void DFT(int *x) {
  for (int i = 0; i < D; ++i) {
    if (i < R[i]) {
      swap(x[i], x[R[i]]);
    }
  }
  for (int i = 1, l = L - 1; i < D; i <<= 1, --l) {
    for (int j = 0; j < D; j += i << 1) {
      for (int k = 0, w = 1, u, v; k < i; ++k, w = 1LL * w * W[l] % mod) {
        u = x[j + k], v = 1LL * w * x[j + k + i] % mod;
        x[j + k] = (u + v) % mod, x[j + k + i] = (u - v + mod) % mod;
      }
    }
  }
}

inline vector <int> Mul(vector <int> a, vector <int> b) {
  static int x[N], y[N];
  int n = a.size(), m = b.size();
  if (n + m - 1 < 64) {
    vector <int> c(n + m - 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        c[i + j] = (1LL * a[i] * b[j] + c[i + j]) % mod;
      }
    }
    return c;
  }
  for (D = 1, L = 0; D < n + m - 1; D <<= 1, ++L);
  for (int i = 1; i < D; ++i) {
    R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
  }
  W[0] = Qow(G, mod - 1 >> L);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  for (int i = 0; i < D; ++i) {
    x[i] = i < n ? a[i] : 0, y[i] = i < m ? b[i] : 0;
  }
  DFT(x), DFT(y);
  for (int i = 0; i < D; ++i) {
    x[i] = 1LL * x[i] * y[i] % mod;
  }
  W[0] = Qow(W[0], mod - 2);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  DFT(x);
  for (int i = 0, v = Qow(D, mod - 2); i < D; ++i) {
    x[i] = 1LL * x[i] * v % mod;
  }
  return vector <int> (x, x + n + m - 1);
}

inline vector <int> Inv(vector <int> a) {
  static int x[N], y[N];
  int n = a.size(), m = n + 1 >> 1;
  if (n << 1 < 64) {
    vector <int> b(n, 0), c(n, 0);
    c[0] = 1;
    for (int i = 0, v = Qow(a[0], mod - 2); i < n; ++i) {
      b[i] = 1LL * c[i] * v % mod;
      for (int j = 0; i + j < n; ++j) {
        c[i + j] = (c[i + j] - 1LL * a[j] * b[i] % mod + mod) % mod;
      }
    }
    return b;
  }
  vector <int> b = Inv(vector <int> (a.begin(), a.begin() + m));
  for (D = 1, L = 0; D < n << 1; D <<= 1, ++L);
  for (int i = 1; i < D; ++i) {
    R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
  }
  W[0] = Qow(G, mod - 1 >> L);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  for (int i = 0; i < D; ++i) {
    x[i] = i < n ? a[i] : 0, y[i] = i < m ? b[i] : 0;
  }
  DFT(x), DFT(y);
  for (int i = 0; i < D; ++i) {
    x[i] = (2 - 1LL * x[i] * y[i] % mod + mod) * y[i] % mod;
  }
  W[0] = Qow(W[0], mod - 2);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  DFT(x);
  for (int i = 0, v = Qow(D, mod - 2); i < D; ++i) {
    x[i] = 1LL * x[i] * v % mod;
  }
  return vector <int> (x, x + n);
}

inline vector <int> Der(vector <int> a) {
  vector <int> b(a.size() - 1, 0);
  for (int i = 0; i < b.size(); ++i) {
    b[i] = 1LL * a[i + 1] * (i + 1) % mod;
  }
  return b;
}

inline vector <int> Int(vector <int> a) {
  vector <int> b(a.size() + 1, 0);
  for (int i = 1; i < b.size(); ++i) {
    b[i] = 1LL * a[i - 1] * inv[i] % mod;
  }
  return b;
}

inline vector <int> Log(vector <int> a) {
  vector <int> b = Int(Mul(Der(a), Inv(a)));
  return vector <int> (b.begin(), b.begin() + a.size());
}

inline vector <int> Exp(vector <int> a) {
  static int x[N], y[N];
  int n = a.size();
  if (n == 1) {
    return vector <int> {1};
  }
  int m = n + 1 >> 1;
  vector <int> b = Exp(vector <int> (a.begin(), a.begin() + m));
  for (; b.size() < n; b.pb(0));
  vector <int> c = Log(b);
  for (int i = 0; i < n; ++i) {
    c[i] = (a[i] + (!i) - c[i] + mod) % mod;
  }
  for (D = 1, L = 0; D < n; D <<= 1, ++L);
  for (int i = 1; i < D; ++i) {
    R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
  }
  W[0] = Qow(G, mod - 1 >> L);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  for (int i = 0; i < D; ++i) {
    x[i] = i < n ? b[i] : 0, y[i] = i < n ? c[i] : 0;
  }
  DFT(x), DFT(y);
  for (int i = 0; i < D; ++i) {
    x[i] = 1LL * x[i] * y[i] % mod;
  }
  W[0] = Qow(W[0], mod - 2);
  for (int i = 1; i < L; ++i) {
    W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
  }
  DFT(x);
  for (int i = m, v = Qow(D, mod - 2); i < n; ++i) {
    b[i] = 1LL * x[i] * v % mod;
  }
  return vector <int> (b.begin(), b.begin() + n);
}

inline vector <int> Qow(vector <int> a, int t) {
  if (t < 0) {
    return Inv(Qow(a, -t));
  }
  int n = a.size(), p = -1;
  vector <int> b(n, 0);
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      p = i;
      break;
    }
  }
  if (!~p) {
    if (!t) {
      b[0] = 1;
    }
    return b;
  }
  if (1LL * t * p >= n) {
    return b;
  }
  int val = Qow(a[p], t), inv = Qow(a[p], mod - 2);
  vector <int> c(n - t * p, 0);
  for (int i = 0; i < n - t * p; ++i) {
    c[i] = 1LL * a[i + p] * inv % mod;
  }
  c = Log(c);
  for (int i = 0; i < n - t * p; ++i) {
    c[i] = 1LL * c[i] * t % mod;
  }
  c = Exp(c);
  for (int i = 0; i < n - t * p; ++i) {
    b[i + t * p] = 1LL * c[i] * val % mod;
  }
  return b;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  fac[0] = fac[1] = inv[0] = inv[1] = fnv[0] = fnv[1] = 1;
  for (int i = 2; i < N; ++i) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
    inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    fnv[i] = 1LL * fnv[i - 1] * inv[i] % mod;
  }
  int n, k;
  Read(k), Read(n);
  vector <int> a, b;
  for (int i = 0; i <= n; ++i) {
    if (!i || i == 2) {
      a.pb(1);
    } else if (i == 1) {
      a.pb(6);
    } else {
      a.pb(0);
    }
  }
  a = Qow(a, mod + 1 >> 1), b = Inv(a);
  for (int i = 0; i <= n; ++i) {
    a[i] = 1LL * (a[i] + (i <= 1)) * (mod + 1 >> 1) % mod;
  }
  a = Mul(Qow(a, k + 1), b);
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", i <= k ? a[i] : 0, i == n ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}