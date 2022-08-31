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

const int N = 935;
const int K = 1000000;
const int mod = 998244353;

int n, m, b[N], c[N], s[N], p[N], len[N], sum[N];
vector <int> a[N];

inline int Qow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod) {
    if (y & 1) {
      r = 1LL * r * x % mod;
    }
  }
  return r;
}

inline vector <int> Solve(const vector <int> &a) {
  vector <int> r(1, 0);
  for (int i = 0; i < a.size(); ++i) {
    r.pb(1LL * a[i] * Qow(i + 1, mod - 2) % mod);
  }
  return r;
}

inline int F(const vector <int> &a, int x) {
  int r = 0;
  for (int i = a.size() - 1; ~i; --i) {
    r = (1LL * r * x + a[i]) % mod;
  }
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 0; i < n; ++i) {
    double x;
    scanf("%lf", &x);
    s[i] = x * K + 0.5;
    b[i] = s[i] % K;
  }
  b[n] = 0;
  sort(b, b + n + 1), m = unique(b, b + n + 1) - b;
  for (int i = 0; i <= n * m; ++i) {
    p[i] = i / m * K + b[i % m];
  }
  for (int i = 0; i < n; ++i) {
    c[i] = lower_bound(p, p + n * m + 1, s[i]) - p;
  }
  for (int i = 0; i < n * m; ++i) {
    len[i] = 1LL * (p[i + 1] - p[i]) * Qow(K, mod - 2) % mod;
    if (i < min(c[0], m)) {
      a[i] = {0, 1}, sum[i] = len[i];
    } else {
      a[i] = {0}, sum[i] = 0;
    }
  }
  for (int x = 1; x < n; ++x) {
    for (int i = n * m - 1; ~i; --i) {
      if (i >= c[x]) {
        a[i] = {0}, sum[i] = 0;
      } else {
        for (int j = i - 1; j >= i - m && ~j; --j) {
          a[i][0] = (a[i][0] + sum[j]) % mod;
        }
        if (i - m >= 0) {
          while (a[i].size() < a[i - m].size()) {
            a[i].pb(0);
          }
          for (int j = 0; j < a[i - m].size(); ++j) {
            a[i][j] = (a[i][j] - a[i - m][j] + mod) % mod;
          }
        }
        a[i] = Solve(a[i]);
        sum[i] = F(a[i], len[i]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n * m; ++i) {
    ans = (ans + sum[i]) % mod;
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}