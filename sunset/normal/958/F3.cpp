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

#define double LD

const int N = 524290;
const int mod = 1009;
const double pi = acosl(-1);

struct E {
  double x, y;

  E(double x = 0, double y = 0):x(x), y(y) {}

  E operator + (const E &b) const {
    return E(x + b.x, y + b.y);
  }

  E operator - (const E &b) const {
    return E(x - b.x, y - b.y);
  }

  E operator * (const E &b) const {
    return E(x * b.x - y * b.y, x * b.y + y * b.x);
  }
} w[N], x[N], y[N], z[N];

int D, L, R[N];

inline void DFT(E *x, E *w) {
  for (int i = 0; i < D; ++i) {
    if (i < R[i]) {
      swap(x[i], x[R[i]]);
    }
  }
  for (int i = 1, l = L - 1; i < D; i <<= 1, --l) {
    for (int j = 0; j < D; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        E u = x[j + k], v = x[j + k + i] * w[k * (1 << l)];
        x[j + k] = u + v, x[j + k + i] = u - v;
      }
    }
  }
}

inline vector <int> Mul(vector <int> a, vector <int> b) {
  int n = a.size(), m = b.size();
  vector <int> c(n + m - 1, 0);
  if (n + m - 1 < 64) {
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
  for (int i = 0; i < D; ++i) {
    z[i] = w[i] = E(cosl(2 * pi * i / D), sinl(2 * pi * i / D)), w[i].y = -w[i].y;
    x[i] = i < n ? E(a[i], 0) : E(0, 0), y[i] = i < m ? E(b[i], 0) : E(0, 0);
  }
  DFT(x, z), DFT(y, z);
  for (int i = 0; i < D; ++i) {
    x[i] = x[i] * y[i];
  }
  DFT(x, w);
  for (int i = 0; i < n + m - 1; ++i) {
    c[i] = (LL)(x[i].x / D + 0.5) % mod;
  }
  return c;
}

int n, m, k, cnt[N];

inline vector <int> Solve(int l, int r) {
  if (l == r) {
    return vector <int> (cnt[l] + 1, 1);
  }
  int mid = l + r >> 1;
  return Mul(Solve(l, mid), Solve(mid + 1, r));
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), Read(k);
  for (int i = 1, x; i <= n; ++i) {
    Read(x), ++cnt[x];
  }
  vector <int> ans = Solve(1, m);
  if (ans.size() <= k) {
    puts("0");
  } else {
    printf("%d\n", ans[k]);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}