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

struct Graph {
  set <pii> all, edg, lef;
  set <int> ver, adj[N];
  int n, d[N];

  inline void AddEdge(int x, int y) {
    edg.insert(mp(x, y)), edg.insert(mp(y, x));
    adj[x].insert(y), adj[y].insert(x);
    ++d[x], ++d[y];
  }

  inline void Init() {
    for (int i = 1; i <= n; ++i) {
      ver.insert(i), all.insert(mp(d[i], i));
      if (d[i] == 1) {
        lef.insert(mp(*adj[i].begin(), i));
      }
    }
  }

  inline int Star() {
    return ver.size() - all.rbegin()->X - 1;
  }

  inline void Erase(int x) {
    int y = *adj[x].begin();
    ver.erase(x), lef.erase(mp(y, x)), all.erase(mp(1, x));
    adj[x].erase(y), adj[y].erase(x);
    all.erase(mp(d[y], y)), all.insert(mp(--d[y], y));
    if (d[y] == 1) {
      lef.insert(mp(*adj[y].begin(), y));
    }
  }

  inline pii Leaves() {
    set <pii> s;
    s.insert(*lef.begin()), s.insert(*++lef.begin());
    s.insert(*lef.rbegin()), s.insert(*++lef.rbegin());
    int big = -1;
    for (auto a : s) {
      if (d[a.X] > 2) {
        big = a.X;
        break;
      }
    }
    if (~big) {
      int x = -1, y = -1;
      for (auto a : s) {
        if (a.X == big) {
          x = a.Y;
        } else {
          y = a.Y;
        }
      }
      return mp(x, y);
    } else {
      return mp(lef.begin()->Y, lef.rbegin()->Y);
    }
  }
} G, H;

int n, ans[N], ret[N];

inline void SolveStar(Graph &G, Graph &H) {
  int u, v, w, uu, vv, ww;
  vector <int> g, h;
  u = (++G.all.rbegin())->Y, v = *G.adj[u].begin(), w = *G.adj[u].rbegin();
  if (G.d[w] == 1) {
    swap(v, w);
  }
  ww = H.lef.begin()->Y, vv = H.lef.begin()->X, uu = -1;
  for (auto x : H.ver) {
    if (H.edg.find(mp(x, vv)) == H.edg.end() && H.edg.find(mp(x, ww)) == H.edg.end()) {
      uu = x;
      break;
    }
  }
  ans[u] = uu, ans[v] = vv, ans[w] = ww;
  for (auto x : G.ver) {
    if (x != u && x != v && x != w) {
      g.pb(x);
    }
  }
  for (auto x : H.ver) {
    if (x != uu && x != vv && x != ww) {
      h.pb(x);
    }
  }
  for (int i = 0; i < g.size(); ++i) {
    ans[g[i]] = h[i];
  }
}

inline void SolveBrute() {
  vector <int> g, h;
  int n = G.ver.size();
  for (auto x : G.ver) {
    g.pb(x);
  }
  for (auto x : H.ver) {
    h.pb(x);
  }
  do {
    bool flg = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (G.edg.find(mp(g[i], g[j])) != G.edg.end() && H.edg.find(mp(h[i], h[j])) != H.edg.end()) {
          flg = false, i = j = n;
        }
      }
    }
    if (flg) {
      for (int i = 0; i < n; ++i) {
        ans[g[i]] = h[i];
      }
      return ;
    }
  } while (next_permutation(g.begin(), g.end()));
  assert(false);
}

inline void Solve() {
  if (G.ver.size() <= 5) {
    SolveBrute();
  } else if (G.Star() == 1) {
    SolveStar(G, H);
  } else if (H.Star() == 1) {
    SolveStar(H, G);
    for (int i = 1; i <= n; ++i) {
      ret[ans[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
      ans[i] = ret[i];
    }
  } else {
    pii a = G.Leaves(), b = mp(*G.adj[a.X].begin(), *G.adj[a.Y].begin()), c = H.Leaves(), d = mp(*H.adj[c.X].begin(), *H.adj[c.Y].begin());
    G.Erase(a.X), G.Erase(a.Y), H.Erase(c.X), H.Erase(c.Y), Solve();
    if (ans[b.X] != d.X && ans[b.Y] != d.Y) {
      ans[a.X] = c.X, ans[a.Y] = c.Y;
    } else {
      ans[a.X] = c.Y, ans[a.Y] = c.X;
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), G.n = H.n = n;
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y), G.AddEdge(x, y);
  }
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y), H.AddEdge(x - n, y - n);
  }
  G.Init(), H.Init();
  if (!G.Star() || !H.Star()) {
    puts("No");
    return 0;
  }
  puts("Yes");
  Solve();
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", ans[i] + n, i == n ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}