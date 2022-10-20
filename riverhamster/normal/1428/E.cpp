#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
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

const int N = 100005;
int a[N], cnt[N];
ll cost[N];
int n, k;

ll D(int p) {
  if (cnt[p] == a[p]) return -1000000000000000000LL;
  int c = cnt[p] + 1;
  int s = a[p] / c;
  int ci = a[p] - c * s;
  int cs = c - ci;
  ll now = 1LL * ci * (s + 1) * (s + 1) + 1LL * cs * s * s;
  return cost[p] - now;
}

priority_queue<pair<ll, int> > q;

int main() {
  read(n, k);
  for (int i = 1; i <= n; ++i)
    read(a[i]), cnt[i] = 1, cost[i] = 1LL * a[i] * a[i], q.emplace(D(i), i);
  for (int i = n + 1; i <= k; ++i) {
    auto p = q.top(); q.pop();
    cost[p.second] -= p.first;
    ++cnt[p.second];
    q.emplace(D(p.second), p.second);
  }
  write(accumulate(cost + 1, cost + 1 + n, 0LL)), endl();
  return 0;
}