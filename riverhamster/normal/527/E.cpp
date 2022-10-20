#include <cstdio>
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

const int N = 100005, M = 800005;
int hd[N], nt[M], to[M], deg[N], ec = 0;
bool vis[M];
int cnt = 0;
void link(int x, int y) {
  to[ec] = y; nt[ec] = hd[x]; hd[x] = ec; ++ec;
  to[ec] = x; nt[ec] = hd[y]; hd[y] = ec; ++ec;
}

void euler(int x) {
  for (int &i = hd[x]; i != -1; i = nt[i]) {
    if(vis[i]) continue;
    vis[i] = vis[i ^ 1] = true;
    int v = to[i];
    euler(to[i]);
    ++cnt;
    if(cnt & 1) write(x, v), endl();
    else write(v, x), endl();
    if(i == -1) break;
  }
}

int main() {
//  File("cf527e");
  int n, m;
  read(n, m);
  fill(hd + 1, hd + 1 + n, -1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    link(u, v);
    ++deg[u]; ++deg[v];
  }
  vector<int> odd;
  for (int i = 1; i <= n; ++i)
    if(deg[i] & 1) odd.push_back(i);
  int cnt = (m + odd.size() / 2);
  if(cnt & 1)
    link(1, 1), ++cnt;
  write(cnt), endl();
  for (unsigned i = 0; i < odd.size(); i += 2)
    link(odd[i], odd[i + 1]);
  for (int i = 1; i <= n; ++i) euler(i);
  return 0;
}