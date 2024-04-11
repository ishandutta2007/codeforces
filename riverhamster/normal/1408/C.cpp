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
int a[N];
#define double long double

int main() {
  // File("c");
  int T;
  read(T);
  while (T--) {
    int n, l;
    read(n, l);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    int p = 0, q = n - 1;
    double x = 0, y = l, v1 = 1, v2 = 1;
    double res = 0;
    while (p <= q) {
      double t1, t2;
      t1 = (a[p] - x) / v1;
      t2 = (y - a[q]) / v2;
      res += min(t1, t2);
      x += min(t1, t2) * v1;
      y -= min(t1, t2) * v2;
      if (t1 < t2) {
        ++p;
        ++v1;
      }
      else {
        --q;
        ++v2;
      }
    }
    printf("%.15Lf\n", res + (y - x) / (v1 + v2));
  }
  return 0;
}