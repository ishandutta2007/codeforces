#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;

#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
namespace io {
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

int M;
inline int add(int x, int y) { return x + y >= M ? x + y - M : x + y; }
template <class... Args> inline int add(int x, int y, Args... args) { return add(add(x, y), args...); }
inline int sub(int x, int y) { return x - y < 0 ? x - y + M : x - y; }
inline int mul(int x, int y) { return 1LL * x * y % M; }
template <class... Args> inline int mul(int x, int y, Args... args) { return mul(mul(x, y), args...); }
inline void inc(int &x, int y=1) { x += y; if(x >= M) x -= M; }
inline void dec(int &x, int y=1) { x -= y; if(x < 0) x += M; }
inline int power(int x, int y) {
  int res = 1;
  for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x) { return power(x, M - 2); }

const int N = 250005, K = 19;
int f[N][K];
int n, k;

int fac[N], ifac[N];
void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}

int dp(int s, int c) {
  if (!s) return 1;
  if (c == k) return 0;
  int &res = f[s][c];
  if (res != -1) return res;
  res = 0;
  int hb = 1;
  while (hb <= s) hb <<= 1;
  hb >>= 1;
  for (int t = s; t != -1; --t) {
    t &= s;
    if (!(t & hb)) return res;
    inc(res, mul(ifac[t], k - c, dp(s ^ t, c + 1)));
  }
  return res;
}

int main() {
  memset(f, -1, sizeof(f));
  read(n, k, M);
  prefac(n);
  if (n & 1) {
    write(power(k, n)), endl();
    return 0;
  }
  write(sub(power(k, n), mul(fac[n], dp(n, 0)))), endl();
  return 0;
}