#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

template <class T> void write(T x) {
  static char stk[128];
  int top = 0;
  if (x == 0) { putchar('0'); return; }
  if (x < 0) putchar('-'), x = -x;
  while (x) stk[top++] = x % 10, x /= 10;
  while (top) putchar(stk[--top] + '0');
}

const int N = 200005;
const int INF = 0x3f3f3f3f;

int n;

struct dual_bit {
  struct { ll d, ds; } t[N];
  void modify(int p, int v) {
    ll vp = v * (p - 1);
    for (; p <= n; p += p & -p)
      t[p].d += v, t[p].ds += vp;
  }
  ll prefix(int p) {
    ll s = 0, sp = 0;
    for (int q = p; q; q &= q - 1)
      s += t[q].d, sp += t[q].ds;
    return s * p - sp;
  }
} b;

pair<int, int> t[N * 4][2];
int tag[N * 4];
void tapply(int x, int val) {
  tag[x] = min(tag[x], val);
  t[x][0].first = min(t[x][0].first, val);
  t[x][1].first = min(t[x][1].first, val);
}
void down(int x) {
  if (tag[x] != INF) {
    tapply(x << 1, tag[x]);
    tapply(x << 1 | 1, tag[x]);
    tag[x] = INF;
  }
}
void up(int x) {
  pair<int, int> *pl = t[x << 1], *pr = t[x << 1 | 1];
  if (pl->first == pr->first) {
    t[x][0] = {pl->first, pl->second + pr->second};
    ++pl, ++pr;
  }
  else t[x][0] = pl->first > pr->first ? *(pl++) : *(pr++);
  if (pl->first == pr->first) {
    t[x][1] = {pl->first, pl->second + pr->second};
    ++pl, ++pr;
  }
  else t[x][1] = pl->first > pr->first ? *(pl++) : *(pr++);
}

void build(int x, int l, int r) {
  tag[x] = INF;
  if (l == r) {
    t[x][0] = {l, 1}; t[x][1] = {-INF, 0};
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  up(x);
}

void assign(int x, int l, int r, int p, int v) {
  if (l == r) {
    if (v > t[x][0].first) b.modify(t[x][0].first + 1, +1), b.modify(v + 1, -1);
    else if (v < t[x][0].first) b.modify(v + 1, -1), b.modify(t[x][0].first + 1, +1);
    t[x][0] = {v, 1}; tag[x] = INF;
    return;
  }
  int mid = (l + r) >> 1;
  down(x);
  p <= mid ? assign(x << 1, l, mid, p, v) : assign(x << 1 | 1, mid + 1, r, p, v);
  up(x);
}

void dfs(int x, int l, int r, int p) {
  if (t[x][0].first <= p) return;
  if (r <= p && t[x][1].first < p) {
    b.modify(p + 1, -t[x][0].second);
    b.modify(t[x][0].first + 1, +t[x][0].second);
    t[x][0].first = p;
    tag[x] = min(tag[x], p);
    return;
  }
  int mid = (l + r) >> 1;
  down(x);
  dfs(x << 1, l, mid, p);
  if (p > mid) dfs(x << 1 | 1, mid + 1, r, p);
  up(x);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int qc;
  read(n, qc);
  b.modify(1, 1);
  build(1, 1, n);
  while (qc--) {
    int opt, x, y;
    read(opt, x, y);
    if (opt == 1) {
      if (x > 1) dfs(1, 1, n, x - 1);
      assign(1, 1, n, x, y);
    }
    else
      write(b.prefix(y) - b.prefix(x - 1)), putchar('\n');
  }
  return 0;
}