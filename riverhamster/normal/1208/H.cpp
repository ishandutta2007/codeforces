#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;

int n, curk;
vector<int> G[N];

struct fn {
  int r, b;
  int eval(int x) const {
    if (x <= r) return r;
    return min(x, b);
  }
};
fn operator*(const fn &a, const fn &b) { return {a.eval(b.r), a.eval(b.b)}; }

namespace seg {
  struct node {
    int s;
    int lc, rc;
  } t[N * 2 * 19];
  int stk[N * 2 * 19], top = 0;
  int nc = 0;
  int getnode() {
    int v = top ? stk[--top] : ++nc;
    t[v].s = t[v].lc = t[v].rc = 0;
    return v;
  }

  void insert(int &x, int l, int r, int p, int v) {
    if (!x) x = getnode();
    t[x].s += v;
    if (l == r) return;
    int mid = (l + r) >> 1;
    p <= mid ? insert(t[x].lc, l, mid, p, v) : insert(t[x].rc, mid + 1, r, p, v);
    if (t[x].s == 0) stk[top++] = x, x = 0;
  }
  int query(int x, int l, int r, int ext) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (ext - t[t[x].lc].s + t[t[x].rc].s < mid) return query(t[x].lc, l, mid, ext + t[t[x].rc].s);
    return query(t[x].rc, mid + 1, r, ext - t[t[x].lc].s);
  }
}
int rt[N];

int col[N];
int sz[N], son[N], top[N], fa[N];
int lts[N];

struct node {
  int lc, rc;
  int fa;
  fn p;
} t[N * 2];
int nc = 0;
void up(int x) { t[x].p = t[t[x].lc].p * t[t[x].rc].p; }

void DFS1(int u) {
  sz[u] = 1;
  for (int v : G[u]) {
    if (v == fa[u]) continue;
    fa[v] = u; DFS1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
  lts[u] = sz[u] - sz[son[u]];
}

int path[N], pc = 0;

int build(int l, int r) {
  if (l + 1 == r) return path[l];
  int sum = 0, sep = -1;
  for (int i = l; i < r; ++i)
    sum += lts[path[i]];
  sum /= 2;
  for (int i = l; i < r; ++i) {
    sum -= lts[path[i]];
    if (sum < 0) { sep = i; break; }
  }
  if (sep == l) ++sep;
  int u = ++nc;
  t[u].lc = build(l, sep); t[t[u].lc].fa = u;
  t[u].rc = build(sep, r); t[t[u].rc].fa = u;
  up(u);
  return u;
}

pair<int, int> DFS2(int u) {
  for (int v = u; v; v = son[v]) {
    top[v] = u;
    for (int w : G[v])
      if (w != fa[v] && w != son[v]) {
        auto ret = DFS2(w);
        t[ret.first].fa = v;
        seg::insert(rt[v], -n, n, ret.second, 1);
      }
    if (~col[v]) {
      int K = col[v] ? n : -n;
      t[v].p.r = t[v].p.b = K;
    }
    else {
      t[v].p.r = seg::query(rt[v], -n, n, -1);
      t[v].p.b = seg::query(rt[v], -n, n, 1);
    }
  }
  pc = 0;
  for (int v = u; v; v = son[v])
    path[pc++] = v;
  int rt = build(0, pc), bot = path[pc - 1];
  return {rt, col[bot] ? t[rt].p.b : t[rt].p.r};
}

void change(int u, int col) {
  ::col[u] = col;
  int pre = t[u].p.r;
  t[u].p.r = t[u].p.b = (col ? n : -n);
  int cur = t[u].p.r;
  while (u) {
    for (u = t[u].fa; u > n; u = t[u].fa)
      pre = t[u].p.r, up(u), cur = t[u].p.r;
    seg::insert(rt[u], -n, n, pre, -1);
    seg::insert(rt[u], -n, n, cur, 1);
    t[u].p.r = seg::query(rt[u], -n, n, -1);
    t[u].p.b = seg::query(rt[u], -n, n, 1);
  }
}
int query(int u) {
  fn p = t[u].p;
  for (; t[u].fa > n; u = t[u].fa)
    if (u == t[t[u].fa].lc) p = p * t[t[t[u].fa].rc].p;
  return p.r;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, curk);
  nc = n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i)
    read(col[i]);
  DFS1(1);
  DFS2(1);

  int qc;
  read(qc);
  while (qc--) {
    int opt, u;
    read(opt, u);
    if (opt == 1)
      printf("%d\n", ~col[u] ? col[u] : query(u) > curk);
    else if (opt == 2) {
      int c; read(c);
      change(u, c);
    }
    else curk = u;
  }
  return 0;
}