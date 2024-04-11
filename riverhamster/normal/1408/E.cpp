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

struct edge {
  int u, v, w;
}e[200005];
int ec = 0;

template<int N>
struct DSU {
  int fa[N], rk[N];
  DSU() {fill(fa, fa + N, -1); fill(rk, rk + N, 0);}
  int find(int x) { return fa[x] != -1 ? fa[x] = find(fa[x]) : x; }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rk[x] < rk[y]) swap(x, y);
    fa[y] = x, rk[x] += rk[x] == rk[y];
  }
};
DSU<200005> d;

int a[500005], b[500005];

int main() {
  int m, n;
  ll res = 0;
  read(m, n);
  for (int i = 0; i < m; ++i) read(a[i]);
  for (int i = 0; i < n; ++i) read(b[i]);
  for (int i = 0; i < m; ++i) {
    int s;
    read(s);
    for (int j = 0; j < s; ++j) {
      int x;
      read(x); --x;
      e[ec++] = {i, m + x, a[i] + b[x]};
    }
  }
  sort(e, e + ec, [] (edge x, edge y) {return x.w > y.w;});
  for (int i = 0; i < ec; ++i) {
    int fu = d.find(e[i].u), fv = d.find(e[i].v);
    if (fu == fv) res += e[i].w;
    else d.merge(fu, fv);
  }
  write(res), endl();
  return 0;
}