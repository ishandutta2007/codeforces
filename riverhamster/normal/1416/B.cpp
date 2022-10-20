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

const int N = 10005;
int a[N];
struct op {
  int i, j, x;
  op() {}
  op(int _i, int _j, int _x) : i(_i), j(_j), x(_x) {}
}o[3 * N];
int oc = 0;

int main() {
  // File("b");
  int T;
  read(T);
  while (T--) {
    int n, s = 0;
    read(n);
    for (int i = 1; i <= n; ++i)
      read(a[i]), s += a[i];
    if (s % n != 0) {
      write(-1), endl();
      continue;
    }
    oc = 0;
    for (int i = 2; i <= n; ++i) {
      if (a[i] % i != 0) {
        o[++oc] = op(1, i, i - a[i] % i);
      }
      o[++oc] = op(i, 1, (a[i] - 1) / i + 1);
    }
    int Val = s / n;
    for (int i = 2; i <= n; ++i)
      o[++oc] = op(1, i, Val);
    write(oc), endl();
    for (int i = 1; i <= oc; ++i)
      write(o[i].i, o[i].j, o[i].x), endl();
  }
  return 0;
}