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
const int M = 105;

int n, m, k, s, a[N], f[N][M];
vector <int> adj[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), Read(k), Read(s);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]);
  }
  for (int i = 1, x, y; i <= m; ++i) {
    Read(x), Read(y);
    adj[x].pb(y), adj[y].pb(x);
  }
  for (int i = 1; i <= k; ++i) {
    queue <int> q;
    for (int j = 1; j <= n; ++j) {
      if (a[j] == i) {
        f[j][i] = 0, q.push(j);
      } else {
        f[j][i] = -1;
      }
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto y : adj[x]) {
        if (!~f[y][i]) {
          f[y][i] = f[x][i] + 1, q.push(y);
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    nth_element(f[i] + 1, f[i] + s + 1, f[i] + k + 1);
    int ret = 0;
    for (int j = 1; j <= s; ++j) {
      ret += f[i][j];
    }
    printf("%d%c", ret, i == n ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}