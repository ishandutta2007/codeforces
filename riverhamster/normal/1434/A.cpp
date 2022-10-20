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

int a[6];
int c[100005];
int tot = 0;
struct pt {
  int p, c;
}p[600005];
bool operator<(pt a, pt b) {return a.p < b.p;}

int cnt = 0;
int n;
void ins(int x) {
  ++c[x];
  cnt += c[x] == 1;
}
void del(int x) {
  --c[x];
  cnt -= c[x] == 0;
}
bool check(int x) {
  int r = 0;
  for (int i = 0; i < tot; ++i) {
    while (r < tot && p[r].p - p[i].p <= x) ins(p[r].c), ++r;
    if (cnt == n) {
      for (int j = i; j < r; ++j) del(p[j].c);
      return true;
    }
    del(p[i].c);
  }
  return false;
}

int main() {
  for (int i = 0; i < 6; ++i) read(a[i]);
  read(n);
  for (int i = 0; i < n; ++i) {
    int x;
    read(x);
    for (int j = 0; j < 6; ++j) {
      p[tot].p = x - a[j];
      p[tot].c = i;
      ++tot;
    }
  }
  sort(p, p + tot);
  int L = 0, R = 1000000000, M;
  while (L < R) (check(M = (L + R) / 2) ? R = M : L = M + 1);
  write(L), endl();
  return 0;
}