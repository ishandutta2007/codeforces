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

const ll INF = 1000000000000000000LL;
ll w[6];
ll f[1000003];

int main() {
  int k;
  read(k);
  for (int i = 0; i < 6; ++i) read(w[i]);
  fill(f + 1, f + 1000000, -INF);
  f[0] = 0;
  for (int p = 0, x = 3; p < 6; x *= 10, ++p) {
    int cnt = min(999999 / x, (k - 1) * 3);
    for (int i = 1; i <= cnt; cnt -= i, i <<= 1) {
      int s = x * i;
      ll v = w[p] * i;
      for (int j = 999999; j >= s; --j)
        f[j] = max(f[j], f[j - s] + v);
    }
    int s = x * cnt;
    ll v = w[p] * cnt;
    for (int j = 999999; j >= s; --j)
      f[j] = max(f[j], f[j - s] + v);
  }
  for (int p = 0, x = 1; p < 6; ++p, x *= 10) {
    for (int i = 999999; i >= x; --i) {
      for (int j = 1; j <= 3; ++j)
        if (x * 3 * j <= i)
          f[i] = max(f[i], f[i - x * 3 * j] + j * w[p]);
      for (int j = 0; j < 9; ++j)
        if (x * j <= i && j % 3 != 0)
          f[i] = max(f[i], f[i - x * j]);
    }
  }
  int q;
  read(q);
  while (q--) {
    int x;
    read(x);
    write(f[x]), endl();
  }
  return 0;
}