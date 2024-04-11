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

const int N = 200005, M = 300005, Q = 500005;
int u[M], v[M];
bool del[M];
int type[Q], pos[Q], nodeid[Q];
int a[N];
int n, m, q;

namespace dsu {
int fa[N], rk[N], id[N];
int find(int x) {
  return !fa[x] ? x : find(fa[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (rk[x] < rk[y]) swap(x, y);
  fa[y] = x;
  rk[x] += rk[x] == rk[y];
}
}

pair<int, int> tr[N << 2];
int val[N], idx = 0;
void build(int x, int l, int r) {
  if (l == r) {
    tr[x] = {val[l], l};
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
  tr[x] = max(tr[x << 1], tr[x << 1 | 1]);
}
void modify(int x, int l, int r, int p) {
  if (l == r) {
    tr[x] = {0, l};
    return;
  }
  int mid = (l + r) >> 1;
  p <= mid ? modify(x << 1, l, mid, p) : modify(x << 1 | 1, mid + 1, r, p);
  tr[x] = max(tr[x << 1], tr[x << 1 | 1]);
}
pair<int, int> query(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return tr[x];
  int mid = (l + r) >> 1;
  pair<int, int> res = {0, 0};
  if (ql <= mid) res = max(res, query(x << 1, l, mid, ql, qr));
  if (qr > mid) res = max(res, query(x << 1 | 1, mid + 1, r, ql, qr));
  return res;
}

vector<int> G[N + M];
int L[N + M], R[N + M];
bool nrt[N + M];

void dfs(int x) {
  if (x <= n) val[++idx] = a[x], L[x] = idx;
  else L[x] = idx + 1;
  for (int v : G[x])
    dfs(v);
  R[x] = idx;
}

int main() {
  read(n, m, q);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  for (int i = 1; i <= m; ++i)
    read(u[i]), read(v[i]);
  for (int i = 1; i <= q; ++i) {
    read(type[i]); read(pos[i]);
    if (type[i] == 2) del[pos[i]] = true;
  }
  for (int i = 1; i <= m; ++i)
    if (!del[i]) dsu::merge(u[i], v[i]);
  for (int i = 1; i <= n; ++i)
    dsu::id[dsu::find(i)] = dsu::find(i);
  for (int i = 1; i <= n; ++i) {
    if (dsu::find(i) == i) continue;
    int f = dsu::find(i);
    nrt[i] = true;
    G[f].push_back(i);
  }
  int nc = n;
  for (int i = q; i >= 1; --i) {
    if (type[i] == 2) {
      int id = pos[i];
      int fu = dsu::find(u[id]), fv = dsu::find(v[id]);
      if (fu == fv) continue;
      ++nc;
      int iu = dsu::id[fu], iv = dsu::id[fv];
      dsu::merge(fu, fv);
      nrt[iu] = nrt[iv] = true;
      G[nc].push_back(iu); G[nc].push_back(iv);
      dsu::id[dsu::find(fu)] = nc;
    }
    else
      nodeid[i] = dsu::id[dsu::find(pos[i])];
  }
  for (int i = 1; i <= nc; ++i)
    if (!nrt[i]) dfs(i);
  build(1, 1, n);
  for (int i = 1; i <= q; ++i)
    if (type[i] == 1) {
      int id = nodeid[i];
      pair<int, int> p = query(1, 1, n, L[id], R[id]);
      write(p.first), endl();
      modify(1, 1, n, p.second);
    }
  return 0;
}