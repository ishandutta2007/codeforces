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

const int N = 100005;

int n, m, ans, a[N], b[N], f[N], g[N];

inline void Modify(int x, int v) {
  for (++x; x <= n + 1; x += x & -x) {
    CheckMax(b[x], v);
  }
}

inline int Query(int x) {
  int r = 0;
  for (++x; x; x -= x & -x) {
    CheckMax(r, b[x]);
  }
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1, l, r; i <= n; ++i) {
    Read(l), Read(r);
    ++a[l], --a[r + 1];
  }
  for (int i = 1; i <= m; ++i) {
    a[i] += a[i - 1];
  }
  memset(b, 0, sizeof b);
  for (int i = 1; i <= m; ++i) {
    f[i] = Query(a[i]) + 1, Modify(a[i], f[i]);
  }
  memset(b, 0, sizeof b);
  for (int i = m; i; --i) {
    g[i] = Query(a[i]) + 1, Modify(a[i], g[i]);
  }
  for (int i = 1; i <= m; ++i) {
    CheckMax(ans, f[i] + g[i] - 1);
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}