#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
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

const int N = 100005;
int sum[N * 2];
char a[N];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, p, k, x, y;
    cin >> n >> p >> k;
    cin >> (a + 1);
    cin >> x >> y;
    fill(sum + 1, sum + n + k + 1, 0);
    for (int i = n; i >= 1; --i)
      sum[i] = sum[i + k] + (a[i] == '0');
    int res = numeric_limits<int>::max();
    for (int i = 0; i <= n - p; ++i) {
      res = min(res, i * y + sum[i + p] * x);
    }
    cout << res << '\n';
  }
  return 0;
}