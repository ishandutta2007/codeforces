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

const int N = 300005;
const int M = 9000005;

int n, tot, a[N], siz[M], nxt[M][2];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), tot = 1;
  for (int i = 1; i <= n; ++i) {
    Read(a[i]);
  }
  for (int i = 1, x, v; i <= n; ++i) {
    Read(v), x = 1;
    for (int j = 29; ~j; --j) {
      if (!nxt[x][v >> j & 1]) {
        nxt[x][v >> j & 1] = ++tot;
      }
      ++siz[x = nxt[x][v >> j & 1]];
    }
  }
  for (int i = 1; i <= n; ++i) {
    int x = 1, ans = 0;
    for (int j = 29; ~j; --j) {
      if (siz[nxt[x][a[i] >> j & 1]]) {
        --siz[x = nxt[x][a[i] >> j & 1]];
      } else {
        --siz[x = nxt[x][!(a[i] >> j & 1)]], ans |= 1 << j;
      }
    }
    printf("%d%c", ans, i == n ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}