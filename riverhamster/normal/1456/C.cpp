#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
using ll = long long;

#define PB push_back
#define EB emplace_back

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
int c[N];

int main() {
  int n, k;
  read(n, k);
  for (int i = 1; i <= n; ++i) read(c[i]);
  sort(c + 1, c + 1 + n, greater<int>());
  ll s = 0, res = 0;
  int p = -1;
  for (int i = 1; i <= n; ++i) {
    res += s;
    s += c[i];
    if (s < 0) { s -= c[i]; p = i; break; }
  }
  if (p == -1) {
    write(res), endl();
    return 0;
  }
  c[p] += s;
  ll co = 0;
  int cnt = k + 1;
  for (int i = n; i >= p; --i) {
    res += c[i] * co;
    --cnt;
    if (cnt == 0) cnt = k + 1, ++co;
  }
  write(res), endl();
  return 0;
}