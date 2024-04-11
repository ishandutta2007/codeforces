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

const int N = 205;

uint ans, mod, c[N][N], f[N][N], s[N][N];
int n, m;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), Read(mod);
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  f[1][0] = 1;
  for (int i = 0; i <= m; ++i) {
    s[1][i] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      for (int k = 0; k < m; ++k) {
        f[i][k + 1] = (1LL * s[j][m - 1] * c[i - 2][j - 1] % mod * f[i - j][k] + f[i][k + 1]) % mod;
      }
    }
    for (int j = 1; j <= m; ++j) {
      s[i][j] = (s[i][j - 1] + f[i][j]) % mod;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; j + k <= m; ++k) {
        if (k != 1) {
          ans = (1LL * f[i + 1][j] * f[n - i][k] + ans) % mod;
        }
      }
    }
  }
  ans = 2LL * n * (n - 1) * ans % mod;
  printf("%u\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}