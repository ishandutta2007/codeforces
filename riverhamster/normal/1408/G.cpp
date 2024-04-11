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

const int M = 998244353;
inline int add(int x, int y) { return x + y >= M ? x + y - M : x + y; }
template <class... Args> inline int add(int x, int y, Args... args) { return add(add(x, y), args...); }
inline int sub(int x, int y) { return x - y < 0 ? x - y + M : x - y; }
inline int mul(int x, int y) { return 1LL * x * y % M; }
template <class... Args> inline int mul(int x, int y, Args... args) { return mul(mul(x, y), args...); }
inline void inc(int &x, int y=1) { x += y; if(x >= M) x -= M; }
inline void dec(int &x, int y=1) { x -= y; if(x < 0) x += M; }
inline int power(int x, int y) {
  int res = 1;
  for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x) { return power(x, M - 2); }

using poly = vector<int>;
poly operator*(poly a, poly b) {
  poly c(a.size() + b.size() + 1);
  for (size_t i = 0; i < a.size(); ++i)
    for (size_t j = 0; j < b.size(); ++j)
      inc(c[i + j + 1], mul(a[i], b[j]));
  return c;
}

const int N = 1505;
int fa[N], siz[N], edges[N];
poly f[N];
int find(int x) {
  return !fa[x] ? x : fa[x] = find(fa[x]);
}
void link(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) {
    ++edges[x];
    if (edges[x] == siz[x] * (siz[x] - 1) / 2)
      ++f[x][0];
    return;
  }
  if (siz[x] < siz[y]) swap(x, y);
  fa[y] = x;
  siz[x] += siz[y];
  edges[x] += edges[y] + 1;
  f[x] = f[x] * f[y];
  if (edges[x] == siz[x] * (siz[x] - 1) / 2)
    ++f[x][0];
}

struct edge {
  int x, y, w;
}e[N * N / 2];

int main() {
  int n;
  read(n);
  fill(f + 1, f + 1 + n, poly({1}));
  fill(siz + 1, siz + 1 + n, 1);
  fill(edges + 1, edges + 1 + n, 0);
  int ec = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int w; read(w);
      if (i < j) e[++ec] = {i, j, w};
    }
  sort(e + 1, e + 1 + ec, [] (edge x, edge y) {return x.w < y.w;});
  for (int i = 1; i <= ec; ++i)
    link(e[i].x, e[i].y);
  int rt = find(1);
  for (int i = 0; i < n; ++i)
    write(f[rt][i]), space();
  endl();
  return 0;
}