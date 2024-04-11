#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
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
using ld = long double;

const int N = 4096;
int d[N][N];
int n;

void pre() {
  for (int i = 2; i <= n; ++i)
    for (int j = i - 1; j >= 2; --j)
      d[i][j - 1] += d[i][j];
  for (int j = 1; j < n - 1; ++j)
    for (int i = j + 1; i < n; ++i)
      d[i + 1][j] += d[i][j];
}

ll f[N];
int cnt[N];
void dp(int k) {
  f[0] = 0; cnt[0] = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = 1000000000000000000LL;
    for (int j = 0; j < i; ++j)
      if (f[j] + d[i][j + 1] < f[i]) {
        f[i] = f[j] + d[i][j + 1];
        cnt[i] = cnt[j] + 1;
      }
    f[i] += k;
  }
}

int main() {
  int k;
  read(n, k);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      read(d[i][j]);
  pre();
  ll l = 0, r = 9 * (n / 2) * (n - n / 2), mid;
  ll res = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    dp(mid);
    if (cnt[n] <= k) {
      res = f[n] - 1LL * k * mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  write(res), endl();
  return 0;
}