#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <numeric>
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
using io::read; using io::write; using io::flush; using io::space; using io::endl;

const int N = 3005;
int len[N];
int a[1000005];
ll f[N], tp[18][N], s[N][N], res = 0;
int n, k;

void dp(int c, ll x) {
  for (int i = k; i >= c; --i)
    f[i] = max(f[i], f[i - c] + x);
}

void solve(int l, int r, int dep = 0) {
  if (l + 1 == r) {
    for (int i = 0; i <= len[l]; ++i)
      res = max(res, f[k - i] + s[l][i]);
    return;
  }
  int mid = (l + r) >> 1;
  copy(f + 1, f + 1 + k, tp[dep] + 1);
  for (int i = l; i < mid; ++i) dp(len[i], s[i][len[i]]);
  solve(mid, r, dep + 1);
  copy(tp[dep] + 1, tp[dep] + 1 + k, f + 1);
  for (int i = mid; i < r; ++i) dp(len[i], s[i][len[i]]);
  solve(l, mid, dep + 1);
  copy(tp[dep] + 1, tp[dep] + 1 + k, f + 1);
}

int main() {
  read(n, k);
  for (int i = 0; i < n; ++i) {
    int c; read(c);
    for (int i = 1; i <= c; ++i) read(a[i]);
    c = min(c, k);
    len[i] = c;
    for (int j = 1; j <= c; ++j) s[i][j] = s[i][j - 1] + a[j];
  }
  solve(0, n);
  write(res), endl();
  return 0;
}