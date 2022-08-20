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

const int N = 105;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, stx, sty, ans, per[4];
char opt[N], s[N][N];

inline bool Check() {
  int x = stx, y = sty;
  for (int i = 0; opt[i]; ++i) {
    int u = x + dx[per[opt[i] - '0']], v = y + dy[per[opt[i] - '0']];
    if (u < 0 || v < 0 || u >= n || v >= m || s[u][v] == '#') {
      return false;
    }
    x = u, y = v;
    if (s[x][y] == 'E') {
      return true;
    }
  }
  return false;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'S') {
        stx = i, sty = j;
      }
    }
  }
  scanf("%s", opt);
  for (int i = 0; i < 4; ++i) {
    per[i] = i;
  }
  do {
    ans += Check();
  } while (next_permutation(per, per + 4));
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}