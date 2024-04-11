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

const int N = 5005;

int n, m, a[N], f[N][N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]), f[i][i] = a[i];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; i + j <= n; ++j) {
      f[j][i + j] = f[j][i + j - 1] ^ f[j + 1][i + j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      CheckMax(f[i][j], f[i][j - 1]);
    }
  }
  for (int i = n; i; --i) {
    for (int j = i; j <= n; ++j) {
      CheckMax(f[i][j], f[i + 1][j]);
    }
  }
  Read(m);
  for (int i = 1, l, r; i <= m; ++i) {
    Read(l), Read(r), printf("%d\n", f[l][r]);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}