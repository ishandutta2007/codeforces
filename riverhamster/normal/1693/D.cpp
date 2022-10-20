#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)

namespace io {
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  char getc () { return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++); }
  void flush () { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
  void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
  template <class T> void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while (isspace(ch = getc()));
    if (ch == '-') ch = getc(), f = -1;
    do x = x * 10 + (ch - '0'); while(isdigit(ch = getc()));
    x *= f;
  }
  template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }
  template <class T> void write(T x) {
    static char stk[128];
    int top = 0;
    if (x == 0) { putc('0'); return; }
    if (x < 0) putc('-'), x = -x;
    while (x) stk[top++] = x % 10, x /= 10;
    while (top) putc(stk[--top] + '0');
  }
  template <class T, class ...A> void write(T x, A... args) { write(x); putc(' '); write(args...) ; }
  void space() { putc(' '); }
  void endl() { putc('\n'); }
  struct _f {~_f() { flush(); }} __f;
}
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;
const int N = 200005;
const int INF = 1e9;

int a[N];
int imn[N], dmx[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, cur = 0;
  ll ans = 0;
  read(n);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  for (int i = n; i >= 1; --i) {
    imn[i] = -INF; dmx[i] = INF;
    ++cur;
    for (int j = i + 1; j <= n; ++j) {
      int I = min(a[j] < a[j - 1] ? imn[j - 1] : INF, a[j] < dmx[j - 1] ? a[j - 1] : INF);
      int D = max(a[j] > a[j - 1] ? dmx[j - 1] : -INF, a[j] > imn[j - 1] ? a[j - 1] : -INF);
      if (I == imn[j] && D == dmx[j]) break;
      cur -= I == INF && D == -INF;
      imn[j] = I; dmx[j] = D;
    }
    ans += cur;
  }
  printf("%lld\n", ans);
  return 0;
}