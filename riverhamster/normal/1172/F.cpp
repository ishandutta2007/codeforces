#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

#define LOG(f...) fprintf(stderr, f)

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
    do x = x * 10 + (ch - '0'); while(isdigit(ch = getc()));
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

constexpr int N = 1e6 + 5;
constexpr ll inf = 1e16;

int n, Q, p;
int a[N];

struct fn {
  vector<ll> t;
  ll s;
  ll operator()(ll x) { return x + s - ll(upper_bound(t.begin(), t.end(), x) - t.begin() - 1) * p; }
} t[N * 4];

fn composite(const fn &a, const fn &b) {
  fn res;
  res.t.resize(a.t.size() + b.t.size() - 1);
  res.t[0] = -inf;
  res.s = a.s + b.s;
  int pl = 1, pr = 1;
  while (pl < (int)a.t.size() && pr < (int)b.t.size()) {
    ll adv_l = max(a.t[pl], b.t[pr - 1] - a.s + ll(pl) * p);
    ll adv_r = max(a.t[pl - 1], b.t[pr] - a.s + ll(pl - 1) * p);
    if (adv_l < adv_r) res.t[pl + pr - 1] = adv_l, ++pl;
    else res.t[pl + pr - 1] = adv_r, ++pr;
  }
  while (pl < (int)a.t.size()) {
    ll adv_l = max(a.t[pl], b.t[pr - 1] - a.s + ll(pl) * p);
    res.t[pl + pr - 1] = adv_l, ++pl;
  }
  while (pr < (int)b.t.size()) {
    ll adv_r = max(a.t[pl - 1], b.t[pr] - a.s + ll(pl - 1) * p);
    res.t[pl + pr - 1] = adv_r, ++pr;
  }
  return res;
}

void build(int x, int l, int r) {
  if (l == r) {
    t[x].s = a[l];
    t[x].t = {-inf, p - t[x].s};
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  t[x] = composite(t[x << 1], t[x << 1 | 1]);
}

ll query(int x, int l, int r, int ql, int qr, ll val = 0) {
  if (ql <= l && r <= qr) return t[x](val);
  int mid = (l + r) >> 1;
  if (ql <= mid) val = query(x << 1, l, mid, ql, qr, val);
  if (qr > mid) val = query(x << 1 | 1, mid + 1, r, ql, qr, val);
  return val;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, Q, p);
  for (int i = 1; i <= n; ++i) read(a[i]);
  build(1, 1, n);
  while (Q--) {
    int l, r;
    read(l, r);
    write(query(1, 1, n, l, r)), endl();
  }
  return 0;
}