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
const int mod = 1e9 + 7;
const int inv = 5e8 + 4;

int n, m = 17, a[N], b[N], e[N], f[N], c[M][N], d[M][N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), f[0] = 0, f[1] = 1;
  for (int i = 2; i < 1 << m; ++i) {
    f[i] = (f[i - 1] + f[i - 2]) % mod;
  }
  for (int i = 0, x; i < n; ++i) {
    Read(x);
    ++a[x], ++b[x], ++c[__builtin_popcount(x)][x];
  }
  for (int x = 0; x <= m; ++x) {
    for (int i = 1; i < 1 << m; i <<= 1) {
      for (int j = 0; j < 1 << m; j += i << 1) {
        for (int k = 0; k < i; ++k) {
          c[x][j + k + i] += c[x][j + k];
        }
      }
    }
  }
  for (int x = 0; x <= m; ++x) {
    for (int y = 0; x + y <= m; ++y) {
      for (int i = 0; i < 1 << m; ++i) {
        d[x + y][i] = (1LL * c[x][i] * c[y][i] + d[x + y][i]) % mod;
      }
    }
  }
  for (int x = 0; x <= m; ++x) {
    for (int i = 1; i < 1 << m; i <<= 1) {
      for (int j = 0; j < 1 << m; j += i << 1) {
        for (int k = 0; k < i; ++k) {
          d[x][j + k + i] = (d[x][j + k + i] - d[x][j + k] + mod) % mod;
        }
      }
    }
  }
  for (int i = 1; i < 1 << m; i <<= 1) {
    for (int j = 0; j < 1 << m; j += i << 1) {
      for (int k = 0, u, v; k < i; ++k) {
        u = b[j + k], v = b[j + k + i], b[j + k] = (u + v) % mod, b[j + k + i] = (u - v + mod) % mod;
      }
    }
  }
  for (int i = 0; i < 1 << m; ++i) {
    b[i] = 1LL * b[i] * b[i] % mod;
  }
  for (int i = 1; i < 1 << m; i <<= 1) {
    for (int j = 0; j < 1 << m; j += i << 1) {
      for (int k = 0, u, v; k < i; ++k) {
        u = b[j + k], v = b[j + k + i], b[j + k] = 1LL * inv * (u + v) % mod, b[j + k + i] = 1LL * inv * (u - v + mod) % mod;
      }
    }
  }
  for (int i = 0; i < 1 << m; ++i) {
    a[i] = 1LL * a[i] * f[i] % mod;
    b[i] = 1LL * b[i] * f[i] % mod;
    e[i] = 1LL * d[__builtin_popcount(i)][i] * f[i] % mod;
  }
  for (int i = 1; i < 1 << m; i <<= 1) {
    for (int j = 0; j < 1 << m; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        a[j + k] = (a[j + k] + a[j + k + i]) % mod, b[j + k] = (b[j + k] + b[j + k + i]) % mod, e[j + k] = (e[j + k] + e[j + k + i]) % mod;
      }
    }
  }
  for (int i = 0; i < 1 << m; ++i) {
    a[i] = 1LL * a[i] * b[i] % mod * e[i] % mod;
  }
  for (int i = 1; i < 1 << m; i <<= 1) {
    for (int j = 0; j < 1 << m; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        a[j + k] = (a[j + k] - a[j + k + i] + mod) % mod;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    ans = (ans + a[1 << i]) % mod;
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}