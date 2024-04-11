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

const int N = 300005;

int n;

const int Node = N * 33;
int c[Node][2], nc = 0;
vector<int> pos[Node];
void ins(int v, int id) {
  int x = 0;
  for (int i = 30; i >= 0; --i) {
    int d = (v >> i) & 1;
    if (!c[x][d]) c[x][d] = ++nc;
    x = c[x][d];
    pos[x].push_back(id);
  }
}
ll cnt[32], all[32];
void solve(int x, int dep) {
  if (dep < 0) return;
  if (c[x][0] && c[x][1]) {
    const vector<int> &rc = pos[c[x][1]];
    auto p = rc.begin();
    all[dep] += 1LL * pos[c[x][0]].size() * pos[c[x][1]].size();
    for (int x : pos[c[x][0]]) {
      while (p != rc.end() && *p < x) ++p;
      cnt[dep] += p - rc.begin();
    }
    solve(c[x][0], dep - 1); solve(c[x][1], dep - 1);
  }
  else solve(c[x][0] | c[x][1], dep - 1);
}

int main() {
  // File("c");
  read(n);
  for (int i = 0; i < n; ++i) {
    int x;
    read(x);
    ins(x, i);
  }
  solve(0, 30);
  ll res = 0, Inv = 0;
  for (int i = 30; i >= 0; --i) {
    if (cnt[i] > all[i] - cnt[i]) Inv += all[i] - cnt[i], res |= (1 << i);
    else Inv += cnt[i];
  }
  write(Inv, res), endl();
  return 0;
}