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
const int M = 100005;
const LD inf = 1e9;
const LD eps = 1e-9;

namespace Flow {
  struct Edge {
    int p, v;
    LD w;

    Edge(int p = 0, int v = 0, LD w = 0):p(p), v(v), w(w) {}
  } e[M];

  int S, T, V, ql, qr, e_cnt, q[N], hed[N], cur[N], dis[N];

  inline void Init(int n) {
    V = n, e_cnt = 1;
    for (int i = 0; i < V; ++i) {
      hed[i] = 0;
    }
  }

  inline void AddEdge(int x, int y, LD w) {
    e[++ e_cnt] = Edge(y, hed[x], w), hed[x] = e_cnt;
    e[++ e_cnt] = Edge(x, hed[y], 0), hed[y] = e_cnt;
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
  
  inline LD DFS(int x, LD f) {
    if (x == T) {
      return f;
    }
    LD r = 0, d;
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
  
  inline LD Dinic() {
    LD r = 0;
    while (BFS()) {
      for (int i = 0; i < V; ++i) {
        cur[i] = hed[i];
      }
      r += DFS(S, inf);
    }
    return r;
  }
}

int n, m, u[N], v[N], a[N], b[N], c[N], d[N];

inline LD Check(LD t) {
  Flow::Init(n + 2), Flow::T = n + 1;
  LD ret = 0;
  for (int i = 1; i <= m; ++i) {
    LD l = t * a[i] + b[i], r = t * c[i] + d[i];
    Flow::AddEdge(u[i], v[i], r - l);
    Flow::AddEdge(Flow::S, v[i], l);
    Flow::AddEdge(u[i], Flow::T, l);
    ret -= l;
  }
  ret += Flow::Dinic();
  return ret;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1; i <= m; ++i) {
    Read(u[i]), Read(v[i]), Read(a[i]), Read(b[i]), Read(c[i]), Read(d[i]);
  }
  LD l = 0, r = 1, L, R, ans = 0;
  for (int i = 0; i < 50; ++i) {
    LD u = (2 * l + r) / 3, v = (l + 2 * r) / 3, x = Check(u), y = Check(v);
    if (x > -eps && y > -eps) {
      l = u;
    } else if (x > y) {
      r = v;
    } else {
      l = u;
    }
  }
  L = 0, R = l;
  for (int i = 0; i < 50; ++i) {
    LD mid = (L + R) / 2;
    if (Check(mid) > -eps) {
      R = mid;
    } else {
      L = mid;
    }
  }
  ans -= L;
  L = l, R = 1;
  for (int i = 0; i < 50; ++i) {
    LD mid = (L + R) / 2;
    if (Check(mid) > -eps) {
      L = mid;
    } else {
      R = mid;
    }
  }
  ans += L;
  printf("%.9lf\n", (double)ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}