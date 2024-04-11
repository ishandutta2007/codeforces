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

const int N = 200005;
const int M = 18;

struct Event {
  int o, t, l, r;

  Event(int o = 0, int t = 0, int l = 0, int r = 0):o(o), t(t), l(l), r(r) {}

  bool operator < (const Event &b) const {
    return t < b.t || (t == b.t && o < b.o);
  }
} eve[N << 2];

int n, m, q, t, tot, a[N], b[N], c[N], ans[N], bit[N], cnt[N], dep[N], dfn[N], par[N], siz[N], f[M][N], anc[M][N];
vector <int> adj[N];

inline int Anc(int x, int k) {
  for (int i = 0; i < M; ++i) {
    if (k >> i & 1) {
      x = anc[i][x];
    }
  }
  return x;
}

inline int LCA(int x, int y) {
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  if (dep[x] > dep[y]) {
    x = Anc(x, dep[x] - dep[y]);
  }
  if (x == y) {
    return x;
  }
  for (int i = M - 1; ~i; --i) {
    if (anc[i][x] != anc[i][y]) {
      x = anc[i][x], y = anc[i][y];
    }
  }
  return par[x];
}

inline void AddTag(int x, int y) {
  for (int i = M - 1; ~i; --i) {
    if (dep[x] - dep[y] >> i & 1) {
      if (!f[i][x] || dep[f[i][x]] > dep[y]) {
        f[i][x] = y;
      }
      x = anc[i][x];
    }
  }
}

inline pii Jump(int x, int y) {
  if (x == y) {
    return mp(0, 0);
  }
  int ret = 0;
  for (int i = M - 1; ~i; --i) {
    if (f[i][x] && dep[f[i][x]] > dep[y]) {
      x = f[i][x], ret += 1 << i;
    }
  }
  if (f[0][x] == x) {
    return mp(-1, 0);
  }
  return mp(ret + 1, x);
}

inline void DFS(int x) {
  dfn[x] = ++t, siz[x] = 1;
  for (auto y : adj[x]) {
    DFS(y), siz[x] += siz[y];
  }
}

inline void Modify(int x) {
  for (; x <= n; x += x & -x) {
    ++bit[x];
  }
}

inline int Query(int x) {
  int r = 0;
  for (; x; x -= x & -x) {
    r += bit[x];
  }
  return r;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 2; i <= n; ++i) {
    Read(par[i]), dep[i] = dep[par[i]] + 1, anc[0][i] = par[i], adj[par[i]].pb(i);
    for (int j = 1; j < M; ++j) {
      anc[j][i] = anc[j - 1][anc[j - 1][i]];
    }
  }
  DFS(1);
  Read(m);
  for (int i = 1; i <= n; ++i) {
    f[0][i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    Read(a[i]), Read(b[i]), c[i] = LCA(a[i], b[i]);
    AddTag(a[i], c[i]), AddTag(b[i], c[i]);
    eve[++tot] = Event(0, dfn[a[i]], dfn[b[i]], dfn[b[i]]);
    eve[++tot] = Event(0, dfn[b[i]], dfn[a[i]], dfn[a[i]]);
  }
  for (int j = M - 1; j; --j) {
    for (int i = 1; i <= n; ++i) {
      if (f[j][i]) {
        if (!f[j - 1][i] || dep[f[j - 1][i]] > dep[f[j][i]]) {
          f[j - 1][i] = f[j][i];
        }
        if (!f[j - 1][anc[j - 1][i]] || dep[f[j - 1][anc[j - 1][i]]] > dep[f[j][i]]) {
          f[j - 1][anc[j - 1][i]] = f[j][i];
        }
      }
    }
  }
  for (int j = 1; j < M; ++j) {
    for (int i = 1; i <= n; ++i) {
      f[j][i] = f[j - 1][f[j - 1][i]];
    }
  }
  Read(q);
  for (int i = 1, r, s, t; i <= q; ++i) {
    Read(s), Read(t), r = LCA(s, t);
    pii a = Jump(s, r), b = Jump(t, r);
    int x = a.X, y = b.X;
    if (!~x || !~y) {
      ans[i] = -1;
    } else {
      ans[i] = x + y;
      if (x && y) {
        s = a.Y, t = b.Y;
        eve[++tot] = Event(i, dfn[s] - 1, dfn[t], dfn[t] + siz[t] - 1);
        eve[++tot] = Event(i + q, dfn[s] + siz[s] - 1, dfn[t], dfn[t] + siz[t] - 1);
      }
    }
  }
  sort(eve + 1, eve + tot + 1);
  for (int i = 1; i <= tot; ++i) {
    if (!eve[i].o) {
      Modify(eve[i].l);
    } else if (eve[i].o <= q) {
      cnt[eve[i].o] += Query(eve[i].l - 1) - Query(eve[i].r);
    } else {
      cnt[eve[i].o - q] += Query(eve[i].r) - Query(eve[i].l - 1);
    }
  }
  for (int i = 1; i <= q; ++i) {
    if (cnt[i]) {
      --ans[i];
    }
    printf("%d\n", ans[i]);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}