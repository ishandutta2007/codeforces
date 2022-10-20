#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
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
#define LOG(f...) fprintf(stderr, f)
const int N = 500005;

struct edge {
  int v;
  ll w;
  edge(int _v, ll _w) : v(_v), w(_w) {}
};
vector<edge> G[N];
int u[N], v[N];
ll wt[N];
int L[N], R[N], dep[N], idx = 0;
ll dis[N], val[N * 2];

void dfs(int x, int fa) {
  L[x] = ++idx; val[idx] = dis[x];
  for (edge e : G[x]) {
    if (e.v == fa) continue;
    dep[e.v] = dep[x] + 1;
    dis[e.v] = dis[x] + e.w;
    dfs(e.v, x);
    ++idx; val[idx] = dis[x];
  }
  R[x] = idx;
}

struct node {
  ll v, m, lm, mr, lmr, tag;
}t[N * 8];
void up(int x) {
  int lc = x << 1, rc = x << 1 | 1;
  t[x].v = max(t[lc].v, t[rc].v);
  t[x].m = max(t[lc].m, t[rc].m);
  t[x].lm = max({t[lc].lm, t[rc].lm, t[lc].v + t[rc].m});
  t[x].mr = max({t[lc].mr, t[rc].mr, t[lc].m + t[rc].v});
  t[x].lmr = max({t[lc].lmr, t[rc].lmr, t[lc].lm + t[rc].v, t[lc].v + t[rc].mr});
}
void down(int x) {
  if (t[x].tag) {
    int lc = x << 1, rc = x << 1 | 1;
    t[lc].v += t[x].tag; t[rc].v += t[x].tag;
    t[lc].m -= 2 * t[x].tag; t[rc].m -= 2 * t[x].tag;
    t[lc].lm -= t[x].tag; t[rc].lm -= t[x].tag;
    t[lc].mr -= t[x].tag; t[rc].mr -= t[x].tag;
    t[lc].tag += t[x].tag; t[rc].tag += t[x].tag;
    t[x].tag = 0;
  }
}
const ll INF = 1000000000000000000LL;
void build(int x, int l, int r) {
  if (l == r) {
    t[x].v = val[l]; t[x].m = -2 * val[l];
    t[x].lm = -val[l]; t[x].mr = -val[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
  up(x);
}
void modify(int x, int l, int r, int ql, int qr, ll d) {
  if (ql <= l && r <= qr) {
    t[x].v += d; t[x].m -= 2 * d;
    t[x].lm -= d; t[x].mr -= d;
    t[x].tag += d;
    return;
  }
  down(x);
  int mid = (l + r) >> 1;
  if (ql <= mid) modify(x << 1, l, mid, ql, qr, d);
  if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, d);
  up(x);
}

int main() {
  int n, q;
  ll w;
  read(n, q, w);
  for (int i = 0; i < n - 1; ++i) {
    read(u[i], v[i], wt[i]);
    G[u[i]].emplace_back(v[i], wt[i]); G[v[i]].emplace_back(u[i], wt[i]);
  }
  dfs(1, 1);
  build(1, 1, idx);
  ll last = 0;
  for (int i = 1; i <= q; ++i) {
    int id;
    ll Wt;
    read(id, Wt);
    id = (id + last) % (n - 1);
    Wt = (Wt + last) % w;
    ll delta = Wt - wt[id];
    wt[id] = Wt;
    int x = dep[u[id]] > dep[v[id]] ? u[id] : v[id];
    modify(1, 1, idx, L[x], R[x], delta);
    write(last = t[1].lmr), endl();
  }
  return 0;
}