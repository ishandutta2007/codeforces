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

const int N = 200004;
vector<int> divisor[N];

int main() {
  // File("cf1418f");
  int n, m;
  ll L, R;
  read(n, m, L, R);
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; j += i)
      divisor[j].push_back(i);
  for (int x1 = 1; x1 < n; ++x1) { // x1 / y2 = x2 / y1 = a / b, where gcd(a, b) = 1
    ll left = max((L - 1) / x1 + 1, 1LL), right = min(R / x1, ll(m)); // bound for y1
    // x1 * y1 in [L, R], left, right in [1, m]
    if (left > right) {
      write(-1), endl();
      continue;
    }
    bool flag = false;
    for (int d : divisor[x1]) {
      int a = x1 / d;
      for (int k = x1 / a + 1, li = n / a, nxt; k <= li; k = nxt + 1) { // x2 = k * a
        nxt = 0x3fffffff;
        if (left > k) nxt = min(ll(nxt), (left - 1) / ((left - 1) / k));
        if (right >= k) nxt = min(ll(nxt), right / (right / k));
        int lb = (left - 1) / k + 1, rb = right / k; // bound for b, since y1 = kb
        if (lb <= rb && lb * d <= m) {
          write(x1, k * lb, k * a, d * lb), endl();
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if(!flag) write(-1), endl();
  }
  write(-1), endl();
  return 0;
}