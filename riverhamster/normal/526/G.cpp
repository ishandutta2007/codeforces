#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cmath>
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

const int N = 100005;
int lgn;

struct edge {
  int v, w;
  edge() {}
  edge(int _v, int _w) : v(_v), w(_w) {}
};
vector<edge> G[N];
int n, q;

struct rooted_tree {
  int rt;
  int son[N], len[N], top[N], mxlen[N], dis[N], last[N];
  int val[N], fa[N][18], res[N];
  void dfs1(int x) {
    len[x] = 0;
    for (int i = 1; i <= lgn; ++i)
      fa[x][i] = fa[fa[x][i - 1]][i - 1];
    mxlen[x] = dis[x];
    for (edge e : G[x]) {
      if (e.v == fa[x][0]) continue;
      fa[e.v][0] = x;
      dis[e.v] = dis[x] + e.w;
      dfs1(e.v);
      len[e.v] += e.w;
      mxlen[x] = max(mxlen[x], mxlen[e.v]);
      len[x] = max(len[x], len[e.v]);
      if (len[e.v] > len[son[x]]) son[x] = e.v;
    }
  }
  void dfs2(int x) {
    if (!son[x]) return;
    top[son[x]] = top[x], dfs2(son[x]);
    for (edge e : G[x])
      if (e.v != fa[x][0] && e.v != son[x])
        top[e.v] = e.v, dfs2(e.v);
  }
  int tops[N], tc = 0;
  void build() {
    for (int i = 0; i <= lgn; ++i) fa[rt][i] = rt;
    dis[rt] = 0, dfs1(rt);
    top[rt] = rt, dfs2(rt);
    for (int i = 1; i <= n; ++i)
      if (top[i] == i) tops[++tc] = i;
    sort(tops + 1, tops + 1 + tc, [this](int x, int y) {return len[x] > len[y];});
    for (int i = 1; i <= tc; ++i) {
      res[i] = res[i - 1] + len[tops[i]];
      for (int x = tops[i]; x; x = son[x])
        last[x] = i;
    }
  }
  int work(int x, int y, int dec[]) {
    int p = x;
    for (int i = lgn; i >= 0; --i)
      if (last[fa[p][i]] > y) p = fa[p][i];
    p = fa[p][0];
    return res[y] + mxlen[x] - dec[p];
  }
  int query(int x, int y) {
    y = 2 * y - 1;
    if (y >= tc) return res[tc];
    if (last[x] <= y) return res[y];
    return max(work(x, y - 1, dis), work(x, y, mxlen));
  }
}t1, t2;

pair<int, int> farthest(int x, int fa) {
  pair<int, int> res = {0, x};
  for (edge e : G[x]) {
    if (e.v == fa) continue;
    pair<int, int> fv = farthest(e.v, x);
    fv.first += e.w;
    res = max(res, fv);
  }
  return res;
}

int main() {
  read(n, q);
  lgn = log2(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    read(u, v, w);
    G[u].emplace_back(v, w); G[v].emplace_back(u, w);
  }
  t1.rt = farthest(1, 1).second;
  t2.rt = farthest(t1.rt, t1.rt).second;
  t1.build(), t2.build();
  int lastans = 0;
  for (int i = 1; i <= q; ++i) {
    int x, y;
    read(x, y);
    x = (x + lastans - 1) % n + 1;
    y = (y + lastans - 1) % n + 1;
    printf("%d\n", lastans = max(t1.query(x, y), t2.query(x, y)));
  }
  return 0;
}