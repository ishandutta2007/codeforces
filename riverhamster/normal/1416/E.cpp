#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <set>
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

const int N = 500005;

ll l, r;
int val;
set<ll> s; // elements : real x = kx + b
ll k = 1, b = 0; // k in {-1, 1}

bool transform(ll x) {
  if (l <= r) {
    ll t = l;
    l = x - r; r = x - t;
    l = max(l, 1LL); r = min(r, x - 1);
  }
  ll L, R;
  if (k == 1) L = 1 - b, R = x - 1 - b;
  else L = b - x + 1, R = b - 1;
  if (L <= R) {
    auto lb = s.lower_bound(L), rb = s.upper_bound(R);
    s.erase(s.begin(), lb), s.erase(rb, s.end());
  }
  else s.clear();
  k = -k, b = -b + x;
  if (l <= r || !s.empty()) return true;
  l = 1; r = x - 1;
  return false;
}

int a[N];

int main() {
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    s.clear();
    k = 1; b = 0;
    if (!(a[0] & 1)) {
      l = r = a[0] / 2;
      val = 1;
    }
    else {
      l = 1, r = a[0] - 1;
      val = 2;
    }
    for (int i = 1; i < n; ++i) {
      if (a[i] & 1) {
        if (transform(a[i])) ++val;
        else val += 2;
      }
      else {
        ll half = a[i] / 2;
        if (s.count(k * (half - b)) || (l <= half && half <= r)) {
          l = half; r = half;
          s.clear();
        }
        else {
          ++val;
          if (!transform(a[i])) {
            l = 1, r = 0;
            s.clear();
          }
          s.insert(k * (half - b));
        }
      }
    }
    write(val), endl();
  }
  return 0;
}