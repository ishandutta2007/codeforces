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

const int N = 2005;
const int M = 800;
const int K = 10;
const int inf = 0x3f3f3f3f;

int n, tot, a[N], b[N], add[M][K], era[M][K], f[N][M][K];
map <vector <int>, int> ind;
vector <int> rel[N];

inline void DFS(int x, int y, vector <int> v) {
  if (x == y) {
    ind[v] = ++tot, rel[tot] = v;
    return ;
  }
  for (int i = x ? v.back() : 1; i <= 9; ++i) {
    v.pb(i), DFS(x + 1, y, v), v.pop_back();
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  for (int i = 0; i <= 4; ++i) {
    DFS(0, i, vector <int> {});
  }
  Read(n);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]), Read(b[i]);
  }
  for (int i = 1; i <= tot; ++i) {
    for (int j = 1; j <= 9; ++j) {
      vector <int> v;
      for (auto x : rel[i]) {
        if (x != j) {
          v.pb(x);
        }
      }
      era[i][j] = ind[v];
      if (rel[i].size() != 4) {
        v = rel[i], v.pb(j), sort(v.begin(), v.end());
        add[i][j] = ind[v];
      }
    }
  }
  memset(f, inf, sizeof f);
  f[1][1][1] = 0;
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = tot; j; --j) {
      for (int k = 1; k <= 9; ++k) {
        if (f[i][j][k] != inf) {
          for (auto l : rel[j]) {
            CheckMin(f[i][era[j][l]][l], f[i][j][k] + abs(k - l));
          }
          if (rel[j].size() != 4 && i <= n) {
            CheckMin(f[i + 1][add[j][b[i]]][a[i]], f[i][j][k] + abs(k - a[i]));
          }
        }
      }
    }
  }
  int ans = inf;
  for (int i = 1; i <= 9; ++i) {
    CheckMin(ans, f[n + 1][1][i]);
  }
  printf("%d\n", ans + (n << 1));
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}