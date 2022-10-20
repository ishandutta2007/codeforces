#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

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

const int Node = 18 * 18 + 5, Edge = (18 * 18 * 20 * 21 * 2 + 18 * 20 * 2 + 500) * 2;
struct NetworkFlows {
  int hd[Node], to[Edge], nt[Edge], f[Edge], ec = 0;
  int S, T, h[Node];
  void clear(){ec = 0; memset(hd, -1, sizeof(hd));}
  NetworkFlows(){clear();}
  void link(int x, int y, int flow){
    to[ec] = y; nt[ec] = hd[x]; hd[x] = ec; f[ec] = flow; ++ec;
    to[ec] = x; nt[ec] = hd[y]; hd[y] = ec; f[ec] = 0; ++ec;
  }

  bool bfs(){
    memset(h, -1, sizeof(h));
    static int q[Node];
    int l = 0, r = 1;
    q[l] = S; h[S] = 0;
    while(l < r){
      int x = q[l++];
      for(int i=hd[x]; i!=-1; i=nt[i])
        if(f[i] && h[to[i]] == -1) h[to[i]] = h[x] + 1, q[r++] = to[i];
    }
    return h[T] != -1;
  }
  int dfs(int x, int flow){
    if(!flow || x == T) return flow;
    int res = 0;
    for(int i=hd[x]; i!=-1; i=nt[i]){
      if(h[to[i]] != h[x] + 1) continue;
      int aug = min(flow, f[i]);
      if((aug = min(aug, dfs(to[i], aug)))){
        f[i] -= aug; f[i ^ 1] += aug;
        flow -= aug; res += aug;
      }
      if(!flow) return res;
    }
    if(res == 0) h[x] = -1;
    return res;
  }
  int maxflow(){
    int res = 0;
    while(bfs()) res += dfs(S, 0x3f3f3f3f);
    return res;
  }
}F;

const int Inf = 0x3f3f3f3f;

int main() {
  int n, m;
  read(n, m);
  F.S = 0; F.T = n * (n - 1) + 1;
  int nc = 0;
  for (int i = 1; i <= n; ++i) {
    int shift = (i - 1) * (n - 1);
    for (int j = 2; j < n; ++j)
      F.link(shift + j, shift + j - 1, Inf);
  }
  while (m--) {
    int u, v, w;
    read(u, v, w);
    swap(u, v); // b = a_v - a_u
    int su = (u - 1) * (n - 1), sv = (v - 1) * (n - 1);
    for (int i = 1; i < n; ++i)
      F.link(sv + i, su + i, w);
    F.link(F.S, sv + 1, Inf);
    for (int i = 1; i < n - 1; ++i)
      F.link(su + i, sv + i + 1, Inf);
    F.link(su + n - 1, F.T, Inf);
  }
  F.maxflow();
  for (int i = 1; i <= n; ++i) {
    int shift = (i - 1) * (n - 1);
    int val = n - 1;
    for (int j = 1; j < n; ++j)
      if (F.h[j + shift] == -1) {
        val = j - 1;
        break;
      }
    write(val), space();
  }
  endl();
  return 0;
}