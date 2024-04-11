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

const int N = 50;
const int M = 8388610;

int n, m, p[N], s[N], idx[N], f[M], g[M];
char a[N][N];

inline int F(int x) {
  while (x != p[x]) {
    x = p[x] = p[p[x]];
  }
  return x;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
    p[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i][j] == 'A') {
        p[F(i)] = F(j);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    ++s[F(i)];
  }
  for (int i = 0; i < n; ++i) {
    if (F(i) == i && s[i] > 1) {
      idx[i] = 1 << m++;
    }
  }
  if (!m) {
    printf("%d\n", n - 1);
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (a[i][j] == 'X') {
          if (F(i) == F(j)) {
            puts("-1");
            return 0;
          } else if (idx[F(i)] && idx[F(j)]) {
            f[idx[F(i)] | idx[F(j)]] = 1;
          }
        }
      }
    }
    for (int i = 1; i < 1 << m; i <<= 1) {
      for (int j = 0; j < 1 << m; j += i << 1) {
        for (int k = 0; k < i; ++k) {
          f[j + k + i] += f[j + k];
        }
      }
    }
    for (int i = 0; i < 1 << m; ++i) {
      f[i] = !f[i], g[i] = 1;
    }
    for (int i = 1; i < 1 << m; i <<= 1) {
      for (int j = 0; j < 1 << m; j += i << 1) {
        for (int k = 0; k < i; ++k) {
          f[j + k + i] += f[j + k];
        }
      }
    }
    for (int i = 1; i <= m; ++i) {
      int cur = 0;
      for (int j = 0; j < 1 << m; ++j) {
        g[j] *= f[j];
        if (__builtin_popcount((1 << m) - 1 ^ j) & 1) {
          cur += g[j];
        } else {
          cur -= g[j];
        }
      }
      if (cur) {
        printf("%d\n", n + i - 1);
        break;
      }
    }
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}