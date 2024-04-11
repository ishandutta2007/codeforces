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

const int N = 405;
const int M = 100005;
const int inf = 0x3f3f3f3f;

namespace Flow {
  struct Edge {
    int p, v, w;
  } e[M];

  int S, T, V, ql, qr, e_cnt, q[N], hed[N], cur[N], dis[N];

  inline void Init(int n) {
    V = n, e_cnt = 1;
    for (int i = 0; i < V; ++i) {
      hed[i] = 0;
    }
  }

  inline void AddEdge(int x, int y, int w) {
    e[++e_cnt] = {y, hed[x], w}, hed[x] = e_cnt;
    e[++e_cnt] = {x, hed[y], 0}, hed[y] = e_cnt;
  }

  inline bool BFS() {
    for (int i = 0; i < V; ++i) {
      dis[i] = 0;
    }
    dis[q[ql = 0] = S] = qr = 1;
    while (ql ^ qr) {
      int x = q[ql++];
      for (int i = hed[x]; i; i = e[i].v) {
        if (e[i].w && !dis[e[i].p]) {
          dis[q[qr++] = e[i].p] = dis[x] + 1;
        }
      }
    }
    return dis[T];
  }
  
  inline int DFS(int x, int f) {
    if (x == T) {
      return f;
    }
    int r = 0, d;
    for (int &i = cur[x]; i; i = e[i].v) {
      if (e[i].w && dis[e[i].p] == dis[x] + 1) {
        d = DFS(e[i].p, min(f - r, e[i].w)), r += d, e[i].w -= d, e[i ^ 1].w += d;
        if (r == f) {
          return r;
        }
      }
    }
    return dis[x] = -1, r;
  }
  
  inline int Dinic() {
    int r = 0;
    while (BFS()) {
      for (int i = 0; i < V; ++i) {
        cur[i] = hed[i];
      }
      r += DFS(S, inf);
    }
    return r;
  }
}

using namespace Flow;

int n, m, k, t, SS, TT, ans[M], deg[2][N], idx[N][N], tag[N][N];

inline void Solve(int x) {
  Init(n + m + 4);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (idx[i][j] && !ans[idx[i][j]]) {
        tag[i][j] = e_cnt + 1, AddEdge(i, j + n, 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    AddEdge(S, i, deg[0][i] / x);
    AddEdge(SS, T, deg[0][i] / x);
    if (deg[0][i] % x) {
      AddEdge(SS, i, 1);
    }
  }
  for (int i = 0; i < m; ++i) {
    AddEdge(S, TT, deg[1][i] / x);
    AddEdge(i + n, T, deg[1][i] / x);
    if (deg[1][i] % x) {
      AddEdge(i + n, TT, 1);
    }
  }
  AddEdge(TT, SS, inf);
  Dinic();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (idx[i][j] && !ans[idx[i][j]] && !e[tag[i][j]].w) {
        --deg[0][i], --deg[1][j], ans[idx[i][j]] = x;
      }
    }
  }
}

int cnt[N][N], u[M], v[M];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), Read(k), Read(t);
  for (int i = 1, x, y; i <= k; ++i) {
    Read(x), Read(y), --x, --y;
    u[i] = x, v[i] = y;
    ++deg[0][x], ++deg[1][y];
    idx[x][y] = i;
  }
  S = n + m, T = n + m + 1, SS = n + m + 2, TT = n + m + 3;
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (deg[0][i] % t) {
      ++ret;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (deg[1][i] % t) {
      ++ret;
    }
  }
  printf("%d\n", ret);
  for (int i = t; i; --i) {
    Solve(i);
  }
  for (int i = 1; i <= k; ++i) {
    printf("%d%c", ans[i], i == k ? '\n' : ' ');
  }
  
  int val = 0;
  for (int i = 1; i <= k; ++i) {
    ++cnt[u[i] + 0][ans[i]];
    ++cnt[v[i] + n][ans[i]];
  }
  for (int i = 0; i < n + m; ++i) {
    int t_max = 0, t_min = inf;
    for (int j = 1; j <= t; ++j) {
      CheckMax(t_max, cnt[i][j]);
      CheckMin(t_min, cnt[i][j]);
    }
    val += t_max - t_min;
  }
  assert(val == ret);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}