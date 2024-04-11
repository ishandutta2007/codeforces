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

const int N = 100005;
vector<int> G[N];
vector<pair<int, int> > res;
int t = 0, maxdeg = 0;

void dfs(int x, int fa) {
  bool flag = false;
  res.emplace_back(x, t);
  if(t == maxdeg) {
    t -= G[x].size(), flag = true;
    res.emplace_back(x, t);
  }
  for (int v : G[x]) {
    if(v == fa) continue;
    ++t;
    dfs(v, x);
    res.emplace_back(x, t);
    if(x != 1 && t == maxdeg) {
      t -= G[x].size(), flag = true;
      res.emplace_back(x, t);
    }
  }
  if(x != 1 && !flag) {
    t -= G[x].size(); flag = true;
    res.emplace_back(x, t);
  }
  ++t;
}

int main() {
  int n;
  read(n);
  if(n == 1) {
    write(1), endl();
    write(1, 0), endl();
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i)
    maxdeg = max(maxdeg, (int)G[i].size());
  dfs(1, 1);
  write(res.size()), endl();
  for (auto p : res)
    write(p.first, p.second), endl();
  return 0;
}