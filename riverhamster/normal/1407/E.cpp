#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
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

const int N = 500005;

struct edge {
  int v, t;
  edge(int _v, int _t) : v(_v), t(_t) {}
};
vector<edge> R[N];
int col[N], dis[N];

int main() {
  int n, m;
  read(n, m);
  for (int i = 1; i <= m; ++i) {
    int u, v, t;
    read(u, v, t);
    R[v].emplace_back(u, t);
  }

  fill(col + 1, col + 1 + n, -1);
  queue<int> q;
  q.push(n); dis[n] = 1;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (x == 1) {
      write(dis[1] - 1), endl();
      for (int i = 1; i <= n; ++i) write(int(col[i] > 0));
      endl();
      return 0;
    }
    for (edge e : R[x]) {
      if (dis[e.v] != 0) continue;
      if (col[e.v] == -1) {
        if (e.t == 2) {
          col[e.v] = 0;
          dis[e.v] = dis[x] + 1;
          q.push(e.v);
        }
        else col[e.v] = e.t ^ 1;
      }
      else if (col[e.v] == e.t || e.t == 2) {
        dis[e.v] = dis[x] + 1;
        q.push(e.v);
      }
    }
  }
  write(-1), endl();
  for (int i = 1; i <= n; ++i) write(int(col[i] > 0));
  endl();
}