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

const int M = 1000000007;
inline int add(int x, int y) {return x+y>=M ? x+y-M : x+y;}
template<class ...Args> inline int add(int x, int y, Args... args) {return add(add(x, y), args...);}
inline int sub(int x, int y) {return x-y<0 ? x-y+M : x-y;}
inline int mul(int x, int y) {return 1LL * x * y % M;}
template<class ...Args> inline int mul(int x, int y, Args... args) {return mul(mul(x, y), args...);}
inline void inc(int &x, int y=1) {x += y; if(x >= M) x -= M;}
inline void dec(int &x, int y=1) {x -= y; if(x < 0) x += M;}
inline int power(int x, int y){
  int res = 1;
  for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x){return power(x, M - 2);}

const int N = 2005, S = 1005;

int x[N], y[N], xL[N], xR[N], yL[N], yR[N], ban[N], bc[N], val[N];
int s[S][S];

int fac[N], ifac[N];
void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}
int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return mul(fac[n], ifac[m], ifac[n - m]);
}

int main() {
  int n, m, r;
  read(n, m, r);
  prefac(n);
  for (int i = 1; i <= n; ++i) {
    read(x[i], y[i], val[i]);
    ++s[x[i]][y[i]];
    xL[i] = max(x[i] - r, 1); xR[i] = min(x[i] + r, 1000);
    yL[i] = max(y[i] - r, 1); yR[i] = min(y[i] + r, 1000);
  }
  for (int i = 1; i <= 1000; ++i)
    for (int j = 1; j <= 1000; ++j)
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
  for (int i = 1; i <= n; ++i) {
    bc[i] = s[xR[i]][yR[i]] - s[xL[i] - 1][yR[i]] - s[xR[i]][yL[i] - 1] + s[xL[i] - 1][yL[i] - 1];
    ban[i] = C(n - bc[i], m);
  }
  int all = C(n, m), res = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int xl = max(x[i], x[j]) - r, xr = min(x[i], x[j]) + r;
      int yl = max(y[i], y[j]) - r, yr = min(y[i], y[j]) + r;
      xl = max(xl, 1); xr = min(xr, 1000);
      yl = max(yl, 1); yr = min(yr, 1000);
      int cnt = 0;
      if (xl > xr || yl > yr) cnt = 0;
      else cnt = s[xr][yr] - s[xl - 1][yr] - s[xr][yl - 1] + s[xl - 1][yl - 1];
      int banall = bc[i] + bc[j] - cnt;
      int way = sub(all, sub(add(ban[i], ban[j]), C(n - banall, m)));
      inc(res, mul(way, val[i], val[j]));
    }
  write(res), endl();
  return 0;
}