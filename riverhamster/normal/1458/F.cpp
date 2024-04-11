#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;

namespace io {
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  inline char getc () {return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++);}
  inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
  inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
  template<class T>
  inline void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while(isspace(ch = getc()));
    if(ch == '-') ch = getc(), f = -1;
    do x = x * 10 + ch - '0'; while(isdigit(ch = getc()));
    x *= f;
  }
  template<class T, class ...Args>
  inline void read(T &x, Args&... args) {read(x); read(args...);}
  template<class T>
  inline void write(T x) {
    static char stk[128];
    int top = 0;
    if(x == 0) {putc('0'); return;}
    if(x < 0) putc('-'), x = -x;
    while(x) stk[top++] = x % 10, x /= 10;
    while(top) putc(stk[--top] + '0');
  }
  template<class T, class ...Args>
  inline void write(T x, Args... args) {write(x); putc(' '); write(args...);}
  inline void space() {putc(' ');}
  inline void endl() {putc('\n');}
  struct _flush {~_flush() {flush();}} __flush;
};
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;

const int N = 200005, logN = 19;
vector<int> G[N];
int n, logn;

namespace LCA {
  int dep[N], fa[N][logN];
  void dfs(int x) {
    for (int i = 1; i <= logn; ++i) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int v : G[x]) {
      if (v == fa[x][0]) continue;
      dep[v] = dep[x] + 1; fa[v][0] = x; dfs(v);
    }
  }
  int kparent(int x, int k) {
    for (int i = 0; k; k >>=1, ++i) if (k & 1) x = fa[x][i];
    return x;
  }
  int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    x = kparent(x, dep[x] - dep[y]);
    if (x == y) return x;
    for (int i = logn; i >= 0; --i)
      if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
  }
  int dist(int x, int y) { return dep[x] + dep[y] - 2 * dep[LCA(x, y)]; }
  int walk(int x, int y, int len) {
    int lca = LCA(x, y);
    if (dep[x] - len >= dep[lca]) return kparent(x, len);
    else return kparent(y, dep[x] + dep[y] - 2 * dep[lca] - len);
  }
  void init() { fill(fa[1], fa[1] + logn + 1, 1); dfs(1); }
};
using LCA::dist; using LCA::walk; using LCA::dep;

namespace HLD {
  int idx = 0;
  ll d[N], ds[N];
  void addt(ll *t, int p, int v) {
    for (; p <= idx; p += p & -p) t[p] += v;
  }
  ll askt(ll *t, int p) {
    ll s = 0;
    for (; p; p ^= p & -p) s += t[p];
    return s;
  }
  void add(int p, int v) { addt(d, p, v); addt(ds, p, (p - 1) * v); }
  ll ask(int p) { return p * askt(d, p) - askt(ds, p); }

  int fa[N], top[N], sz[N], id[N], son[N];
  void dfs1(int x) {
    sz[x] = 1;
    for (int v : G[x]) {
      if (v == fa[x]) continue;
      fa[v] = x;
      dfs1(v);
      sz[x] += sz[v];
      if (sz[v] > sz[son[x]]) son[x] = v;
    }
  }
  void dfs2(int x) {
    id[x] = ++idx;
    if (!son[x]) return;
    top[son[x]] = top[x]; dfs2(son[x]);
    for (int v : G[x])
      if (v != son[x] && v != fa[x])
        top[v] = v, dfs2(v);
  }
  void init() {
    dfs1(1);
    for (int v : G[1]) top[v] = v, dfs2(v);
  }
  
  void path_add(int x, int v) {
    while (x != 1) {
      add(id[top[x]], v); add(id[x] + 1, -v);
      x = fa[top[x]];
    }
  }
  ll path_sum(int x) {
    ll s = 0;
    while (x != 1) {
      s += ask(id[x]) - ask(id[top[x]] - 1);
      x = fa[top[x]];
    }
    return s;
  }
};
using HLD::path_add; using HLD::path_sum;

ll res = 0;

struct circle {
  int c, r;
  circle() : c(0), r(0) {}
  circle(int _x, int _r = 0) : c(_x), r(_r) {}
};
// subset of
bool operator<=(const circle &a, const circle &b) { return dist(a.c, b.c) + a.r <= b.r; }
bool operator!=(const circle &a, const circle &b) { return a.c != b.c || a.r != b.r; }
circle extend(const circle &c, int x) {
  int d = dist(c.c, x);
  if (d <= c.r) return c;
  else return circle(walk(c.c, x, ((c.r + d) / 2 - c.r)), (c.r + d) / 2);
}

circle R[N];
ll rsum[N];

void solve(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  circle L(mid);
  R[mid + 1] = circle(mid + 1);
  for (int i = mid + 2; i <= r; ++i) R[i] = extend(R[i - 1], i);
  rsum[r + 1] = 0;
  for (int i = r; i > mid; --i) rsum[i] = rsum[i + 1] + R[i].r;
  int p = mid + 1, q = mid + 1;
  ll depsum = 0;

  for (int i = mid; i >= l; --i) {
    while (q <= r && !(L <= R[q] && L != R[q])) {
      depsum += dep[R[q].c]; path_add(R[q].c, 1);
      ++q;
    }
    while (p <= r && R[p] <= L) {
      depsum -= dep[R[p].c]; path_add(R[p].c, -1);
      ++p;
    }

    res += 1LL * L.r * (p - mid - 1);
    res += rsum[q];
    res += (ll(dep[L.c] + L.r) * (q - p) + depsum + rsum[p] - rsum[q] - 2 * path_sum(L.c)) / 2;

    if (i != l) L = extend(L, i - 1);
  }
  while (p < q) path_add(R[p++].c, -1);

  solve(l, mid); solve(mid + 1, r);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n);
  logn = log2(2 * n - 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(n + i); G[n + i].push_back(u);
    G[v].push_back(n + i); G[n + i].push_back(v);
  }
  LCA::init();
  HLD::init();

  solve(1, n);
  write(res), endl();
  return 0;
}