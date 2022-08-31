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

const int N = 1005;
const int M = 55;
const int mod = 1e9 + 7;

int n, m, f[N], g[N], h[N], c[N][N];
char s[M][N];

inline int F(int x) {
  while (x != f[x]) {
    x = f[x] = f[f[x]];
  }
  return x;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 0; i < m; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  g[0] = g[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      g[i] = (1LL * g[i - j - 1] * c[i - 1][j] + g[i]) % mod;
    }
  }
  for (int i = 0; i < n; ++i) {
    f[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (F(i) != F(j)) {
        bool flg = true;
        for (int k = 0; k < m; ++k) {
          if (s[k][i] != s[k][j]) {
            flg = false;
            break;
          }
        }
        if (flg) {
          f[F(i)] = F(j);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    ++h[F(i)];
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (F(i) == i) {
      ans = 1LL * ans * g[h[i]] % mod;
    }
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}