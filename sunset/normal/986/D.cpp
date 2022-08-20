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

const int N = 2097155;
const int base = 10000;
const double pi = acos(-1);

struct E {
  double x, y;
  
  E(double x = 0, double y = 0):x(x), y(y) {
  }

  E operator + (const E &b) const {
    return E(x + b.x, y + b.y);
  }

  E operator - (const E &b) const {
    return E(x - b.x, y - b.y);
  }

  E operator * (const E &b) const {
    return E(x * b.x - y * b.y, x * b.y + y * b.x);
  }
} I[N], W[N], X[N];

int D, L, R[N], f[N];
char s[N];

inline void DFT(E *W) {
  for (int i = 0; i < D; ++i) {
    if (i < R[i]) {
      swap(X[i], X[R[i]]);
    }
  }
  for (int i = 1, l = L - 1; i < D; i <<= 1, --l) {
    for (int j = 0; j < D; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        E u = X[j + k], v = X[j + k + i] * W[k << l];
        X[j + k] = u + v, X[j + k + i] = u - v;
      }
    }
  }
}

struct BigInt {
  vector <LL> a;

  BigInt() {
  }

  BigInt(int x) {
    a.pb(x);
  }

  inline void Make() {
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] >= base) {
        if (i == a.size() - 1) {
          a.pb(0);
        }
        a[i + 1] += a[i] / base;
        a[i] %= base;
      }
    }
    while (a.size() > 1 && !a.back()) {
      a.pop_back();
    }
  }

  inline int Read() {
    scanf("%s", s);
    int n = strlen(s);
    if (n == 1 && s[0] == '1') {
      puts("1");
      exit(0);
    }
    for (int i = 0; i < n; ++i) {
      s[i] -= '0';
    }
    LD r = 0, b = 1;
    for (int i = 0; i < n; ++i) {
      r += s[i] * b, b *= 0.1;
    }
    r = logl(r) / logl(3) + (n - 1) * logl(10) / logl(3);
    for (reverse(s, s + n); n & 3; ++n);
    for (int i = 0; i < n; i += 4) {
      a.pb(s[i + 3] * 1000 + s[i + 2] * 100 + s[i + 1] * 10 + s[i]);
    }
    return max((int)r - 2, 0);
  }

  bool operator < (const BigInt &b) const {
    if (a.size() != b.a.size()) {
      return a.size() < b.a.size();
    }
    for (int i = a.size() - 1; ~i; --i) {
      if (a[i] != b.a[i]) {
        return a[i] < b.a[i];
      }
    }
    return false;
  }

  BigInt operator * (const int &b) const {
    BigInt c;
    for (int i = 0; i < a.size(); ++i) {
      c.a.pb(a[i] * b);
    }
    c.Make();
    return c;
  }

  inline BigInt Sqr() {
    for (D = 1, L = 0; D < a.size() * 2; D <<= 1, ++L);
    for (int i = 1; i < D; ++i) {
      R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
    }
    for (int i = 0; i < D; ++i) {
      W[i] = I[i] = E(cos(2 * pi * i / D), sin(2 * pi * i / D)), I[i].y = -I[i].y;
      X[i] = i < a.size() ? E(a[i], 0) : E(0, 0);
    }
    DFT(W);
    for (int i = 0; i < D; ++i) {
      X[i] = X[i] * X[i];
    }
    DFT(I);
    BigInt b;
    b.a.resize(D);
    for (int i = 0; i < b.a.size(); ++i) {
      b.a[i] = X[i].x / D + 0.5;
    }
    b.Make();
    return b;
  }
} n;

inline BigInt Qow(int x) {
  if (!x) {
    return BigInt(1);
  }
  BigInt r = Qow(x >> 1).Sqr();
  if (x & 1) {
    r = r * 3;
  }
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  int e = n.Read(), ans = e * 3, t = 1;
  BigInt p = Qow(e);
  while (p * t < n) {
    ++t;
  }
  for (int i = 2; i <= t; ++i) {
    f[i] = min(f[i + 1 >> 1] + 2, f[(i + 2) / 3] + 3);
  }
  printf("%d\n", ans + f[t]);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}