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
const int M = 10;
const int K = 260;

int n, m, lim, d[M][M], dis[N][M], cnt[2][M][K];
LL ans[M << 1];
char s[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), m = 8, lim = (m << 1) - 1, scanf("%s", s + 1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      d[i][j] = i == j ? 0 : n;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = max(1, i - lim); j <= min(n, i + lim); ++j) {
      CheckMin(d[s[i] - 'a'][s[j] - 'a'], abs(i - j));
    }
  }
  for (int k = 0; k < m; ++k) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        CheckMin(d[i][j], d[i][k] + d[k][j] + 1);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i] - 'a' == j) {
        dis[i][j] = 0;
      } else {
        dis[i][j] = d[s[i] - 'a'][j] + 1;
      }
    }
    for (int j = max(1, i - lim); j <= min(n, i + lim); ++j) {
      CheckMin(dis[i][s[j] - 'a'], abs(i - j));
      for (int k = 0; k < m; ++k) {
        CheckMin(dis[i][k], abs(i - j) + 1 + d[s[j] - 'a'][k]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = max(1, i - lim); j < i; ++j) {
      int val = abs(i - j);
      for (int k = 0; k < m; ++k) {
        CheckMin(val, dis[i][k] + dis[j][k] + 1);
      }
      ++ans[val];
    }
    for (int j = 0; j < m; ++j) {
      int sta = 0, val = n;
      for (int k = 0; k < m; ++k) {
        CheckMin(val, dis[i][k] + d[k][j] + 1);
      }
      for (int k = 0; k < m; ++k) {
        if (val == dis[i][k] + d[k][j] + 1) {
          sta |= 1 << k;
        }
      }
      ans[val] += cnt[0][j][sta], ans[val + 1] += cnt[1][j][sta];
    }
    int p = i - lim;
    if (p > 0) {
      int sta = 0;
      for (int j = 0; j < m; ++j) {
        if (dis[p][j] == d[s[p] - 'a'][j] + 1) {
          sta |= 1 << j;
        }
      }
      for (int j = 0; j < 1 << m; ++j) {
        ++cnt[(sta & j) == j][s[p] - 'a'][j];
      }
    }
  }
  int ret = 0;
  for (int i = 1; i <= lim; ++i) {
    if (ans[i]) {
      ret = i;
    }
  }
  printf("%d %lld\n", ret, ans[ret]);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}