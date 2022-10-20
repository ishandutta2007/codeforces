#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <tuple>
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

const int N = 120005;
const int INF = 1e9;

int p[N];

struct value {
  int v;
  ll c;
  value() : v(+INF), c(0) {}
  value(int _v, ll _c) : v(_v), c(_c) {}
};
value operator+(const value &a, const value &b) {
  if (a.v < b.v) return a;
  else if (b.v < a.v) return b;
  else return {a.v, a.c + b.c};
}
struct node {
  value mn, sum, scnt;
  int inc;
} t[N * 4];

void up(int x) {
  t[x].mn = t[x << 1].mn + t[x << 1 | 1].mn;
  t[x].sum = t[x << 1].sum + t[x << 1 | 1].sum;
}
void tag_mn(int x, int v) {
  t[x].scnt.v -= v;
  t[x].mn.v += v; t[x].inc += v;
}
void tag_sum(int x, value v) {
  t[x].sum = t[x].sum + value(t[x].mn.v + v.v, t[x].mn.c * v.c);
  t[x].scnt = t[x].scnt + v;
}
void down(int x) {
  if (t[x].inc) {
    tag_mn(x << 1, t[x].inc);
    tag_mn(x << 1 | 1, t[x].inc);
    t[x].inc = 0;
  }
  if (t[x].scnt.c) {
    tag_sum(x << 1, t[x].scnt);
    tag_sum(x << 1 | 1, t[x].scnt);
    t[x].scnt = value();
  }
}

void modify(int x, int l, int r, int ql, int qr, int d) {
  if (ql <= l && r <= qr) return tag_mn(x, d);
  int mid = (l + r) >> 1;
  down(x);
  if (ql <= mid) modify(x << 1, l, mid, ql, qr, d);
  if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, d);
  up(x);
}
void cumulate(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return tag_sum(x, {0, 1});
  int mid = (l + r) >> 1;
  down(x);
  if (ql <= mid) cumulate(x << 1, l, mid, ql, qr);
  if (qr > mid) cumulate(x << 1 | 1, mid + 1, r, ql, qr);
  up(x);
}
value sum(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return t[x].sum;
  int mid = (l + r) >> 1;
  down(x);
  if (ql <= mid && qr <= mid) return sum(x << 1, l, mid, ql, qr);
  if (ql > mid && qr > mid) return sum(x << 1 | 1, mid + 1, r, ql, qr);
  return sum(x << 1, l, mid, ql, qr) + sum(x << 1 | 1, mid + 1, r, ql, qr);
}
void build(int x, int l, int r) {
  if (l == r) {
    t[x].mn = {0, 1};
    t[x].sum = {+INF, 0};
    t[x].inc = 0;
    t[x].scnt = {+INF, 0};
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  up(x);
}
void upall(int x, int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  down(x);
  upall(x << 1, l, mid); upall(x << 1 | 1, mid + 1, r);
  up(x);
}

vector<pair<int, int>> Q[N];
ll res[N];
int mx[N], mxt = 0;
int mn[N], mnt = 0;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, qc;
  read(n);
  for (int i = 1; i <= n; ++i) read(p[i]);
  read(qc);
  for (int i = 1; i <= qc; ++i) {
    int l, r;
    read(l, r);
    Q[r].emplace_back(l, i);
  }
  build(1, 1, n);

  for (int i = 1; i <= n; ++i) {
    while (mxt && p[i] > p[mx[mxt]]) {
      modify(1, 1, n, mx[mxt - 1] + 1, mx[mxt], -p[mx[mxt]]);
      --mxt;
    }
    modify(1, 1, n, mx[mxt] + 1, i, p[i]);
    mx[++mxt] = i;

    while (mnt && p[i] < p[mn[mnt]]) {
      modify(1, 1, n, mn[mnt - 1] + 1, mn[mnt], p[mn[mnt]]);
      --mnt;
    }
    modify(1, 1, n, mn[mnt] + 1, i, -p[i]);
    mn[++mnt] = i;
  
    modify(1, 1, n, 1, i, -1);
    cumulate(1, 1, n, 1, i);
    for (auto [l, id] : Q[i]) {
      auto ret = sum(1, 1, n, l, i);
      res[id] = ret.c * int(ret.v == -1);
    }
  }

  for (int i = 1; i <= qc; ++i) write(res[i]), endl();
  return 0;
}