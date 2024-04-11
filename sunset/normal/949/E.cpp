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

const int N = 262145;
const int M = 18;
const int inf = 0x3f3f3f3f;

int n, ans, cur, ret[N], val[N];
bool f[M][N];

inline void DFS(int x) {
  if (cur >= ans) {
    return ;
  }
  if (x == 17) {
    if (f[x][0]) {
      val[++cur] = -(1 << x);
    }
    if (f[x][2]) {
      val[++cur] = 1 << x;
    }
    if (cur < ans) {
      ans = cur;
      for (int i = 1; i <= cur; ++i) {
        ret[i] = val[i];
      }
    }
    if (f[x][0]) {
      --cur;
    }
    if (f[x][2]) {
      --cur;
    }
    return ;
  }
  bool flg = true;
  for (int i = 1; i <= 1 << 18 - x; i += 2) {
    if (f[x][i]) {
      flg = false;
      break;
    }
  }
  if (flg) {
    for (int i = 0; i <= 1 << 17 - x; ++i) {
      f[x + 1][i] = f[x][i << 1];
    }
    DFS(x + 1);
  } else {
    for (int i = 0; i <= 1 << 17 - x; ++i) {
      f[x + 1][i] = f[x][i << 1] | f[x][i << 1 | 1];
    }
    val[++cur] = 1 << x, DFS(x + 1), --cur;
    f[x + 1][0] = f[x][0];
    for (int i = 1; i <= 1 << 17 - x; ++i) {
      f[x + 1][i] = f[x][i << 1] | f[x][(i << 1) - 1];
    }
    val[++cur] = -(1 << x), DFS(x + 1), --cur;
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), ans = inf;
  for (int i = 1, x; i <= n; ++i) {
    Read(x), f[0][x + (1 << 17)] = true;
  }
  DFS(0);
  printf("%d\n", ans);
  for (int i = 1; i <= ans; ++i) {
    printf("%d%c", ret[i], i == ans ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}