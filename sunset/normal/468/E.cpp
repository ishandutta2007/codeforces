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
const int mod = 1e9 + 7;

int n, m, cnt_x, cnt_y, ans[M], cur[M], fac[N], adj[M][M];
bool vis_x[M], vis_y[M];
map <int, int> x, y;
vector <int> l, r;

inline int Qow(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod) {
    if (y & 1) {
      r = 1LL * r * x % mod;
    }
  }
  return r;
}

inline void DFS(int x, bool t) {
  if (t) {
    vis_y[x] = true, r.pb(x);
    for (int i = 0; i < cnt_x; ++i) {
      if (!vis_x[i] && adj[i][x]) {
        DFS(i, 0);
      }
    }
  } else {
    vis_x[x] = true, l.pb(x);
    for (int i = 0; i < cnt_y; ++i) {
      if (!vis_y[i] && adj[x][i]) {
        DFS(i, 1);
      }
    }
  }
}

namespace BruteTree {
  int n, chs, tim, pro, u[M], v[M], dfn[M], par[M], siz[M], f[M][M], g[M][M];
  vector <pair <pii, int>> all;
  vector <pii> gra[M];
  map <int, int> idx;
  bool vis[M];

  inline void DFS(int x) {
    dfn[x] = ++tim;
    for (auto e : gra[x]) {
      if (e.X != par[x]) {
        if (!dfn[e.X]) {
          par[e.X] = x, DFS(e.X);
        } else if (dfn[x] < dfn[e.X]) {
          all.pb(mp(mp(x, e.X), e.Y));
        }
      }
    }
  }

  inline void DP(int x) {
    if (vis[x]) {
      g[x][0] = 1;
    } else {
      f[x][0] = 1;
    }
    siz[x] = 1;
    for (auto e : gra[x]) {
      if (par[e.X] == x) {
        DP(e.X);
        for (int i = 0; i <= siz[x] + siz[e.X]; ++i) {
          u[i] = v[i] = 0;
        }
        for (int i = siz[x]; ~i; --i) {
          for (int j = siz[e.X]; ~j; --j) {
            u[i + j] = (1LL * f[x][i] * (f[e.X][j] + g[e.X][j]) + u[i + j]) % mod;
            v[i + j] = (1LL * g[x][i] * (f[e.X][j] + g[e.X][j]) + v[i + j]) % mod;
            v[i + j + 1] = (1LL * f[x][i] * f[e.X][j] % mod * e.Y + v[i + j + 1]) % mod;
          }
        }
        siz[x] += siz[e.X];
        for (int i = 0; i <= siz[x]; ++i) {
          f[x][i] = u[i], g[x][i] = v[i];
        }
      }
    }
  }

  inline void Solve() {
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= m; ++j) {
        f[i][j] = g[i][j] = 0;
      }
    }
    DP(1);
    for (int i = 0; i <= n; ++i) {
      f[1][i] = (f[1][i] + g[1][i]) % mod;
      if (f[1][i]) {
        cur[i + chs] = (1LL * f[1][i] * pro + cur[i + chs]) % mod;
      }
    }
  }

  inline void DFS(int x, int n) {
    if (x == n) {
      Solve();
      return ;
    }
    DFS(x + 1, n);
    if (!vis[all[x].X.X] && !vis[all[x].X.Y]) {
      ++chs, pro = 1LL * pro * all[x].Y % mod;
      vis[all[x].X.X] = vis[all[x].X.Y] = true;
      DFS(x + 1, n);
      --chs, pro = 1LL * pro * Qow(all[x].Y, mod - 2) % mod;
      vis[all[x].X.X] = vis[all[x].X.Y] = false;
    }
  }

  int Main() {
    n = chs = tim = 0, pro = 1, all.clear(), idx.clear();
    for (auto x : l) {
      idx[x] = ++n;
    }
    for (auto y : r) {
      idx[y + cnt_x] = ++n;
    }
    for (int i = 1; i <= n; ++i) {
      dfn[i] = 0, vis[i] = false, gra[i].clear();
    }
    for (auto x : l) {
      for (auto y : r) {
        if (adj[x][y]) {
          gra[idx[x]].pb(mp(idx[y + cnt_x], adj[x][y]));
          gra[idx[y + cnt_x]].pb(mp(idx[x], adj[x][y]));
        }
      }
    }
    DFS(1), DFS(0, all.size());
  }
}

namespace BitMaskDP {
  const int N = 131075;
  
  int f[2][N];

  int Main() {
    if (l.size() <= r.size()) {
      int n = l.size(), m = r.size();
      for (int i = 0; i < 1 << n; ++i) {
        f[0][i] = f[1][i] = 0;
      }
      f[0][0] = 1;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (adj[l[j]][r[i]]) {
            for (int k = 0; k < 1 << n; ++k) {
              if (f[0][k] && !(k >> j & 1)) {
                f[1][k | 1 << j] = (1LL * adj[l[j]][r[i]] * f[0][k] + f[1][k | 1 << j]) % mod;
              }
            }
          }
        }
        for (int j = 0; j < 1 << n; ++j) {
          f[0][j] = (f[0][j] + f[1][j]) % mod, f[1][j] = 0;
        }
      }
      for (int i = 0; i < 1 << n; ++i) {
        cur[__builtin_popcount(i)] = (cur[__builtin_popcount(i)] + f[0][i]) % mod;
      }
    } else {
      int n = r.size(), m = l.size();
      for (int i = 0; i < 1 << n; ++i) {
        f[0][i] = f[1][i] = 0;
      }
      f[0][0] = 1;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (adj[l[i]][r[j]]) {
            for (int k = 0; k < 1 << n; ++k) {
              if (f[0][k] && !(k >> j & 1)) {
                f[1][k | 1 << j] = (1LL * adj[l[i]][r[j]] * f[0][k] + f[1][k | 1 << j]) % mod;
              }
            }
          }
        }
        for (int j = 0; j < 1 << n; ++j) {
          f[0][j] = (f[0][j] + f[1][j]) % mod, f[1][j] = 0;
        }
      }
      for (int i = 0; i < 1 << n; ++i) {
        cur[__builtin_popcount(i)] = (cur[__builtin_popcount(i)] + f[0][i]) % mod;
      }
    }
    return 0;
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), fac[0] = ans[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
  }
  for (int i = 1, u, v, w; i <= m; ++i) {
    Read(u), Read(v), Read(w);
    if (x.find(u) == x.end()) {
      x[u] = cnt_x++;
    }
    if (y.find(v) == y.end()) {
      y[v] = cnt_y++;
    }
    adj[x[u]][y[v]] = (w + mod - 1) % mod;
  }
  for (int i = 0; i < cnt_x; ++i) {
    if (!vis_x[i]) {
      l.clear(), r.clear(), DFS(i, 0);
      int edg = 0;
      for (auto x : l) {
        for (auto y : r) {
          if (adj[x][y]) {
            ++edg;
          }
        }
      }
      for (int j = 0; j <= m; ++j) {
        cur[j] = 0;
      }
      if (edg - l.size() - r.size() + 1 <= min(l.size(), r.size())) {
        BruteTree::Main();
      } else {
        BitMaskDP::Main();
      }
      for (int j = m; ~j; --j) {
        ans[j] = 1LL * ans[j] * cur[0] % mod;
        for (int k = j - 1; ~k; --k) {
          ans[j] = (1LL * ans[k] * cur[j - k] + ans[j]) % mod;
        }
      }
    }
  }
  int ret = 0;
  for (int i = 0; i <= min(n, m); ++i) {
    ret = (1LL * ans[i] * fac[n - i] + ret) % mod;
  }
  printf("%d\n", ret);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}