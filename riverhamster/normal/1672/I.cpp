#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <set>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
// #define DBG(f...) printf("%3d: ", __LINE__), printf(f)
#define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 500005;
const int INF = 0x3f3f3f3f;

int n;
int p[N], ip[N];

struct BIT {
  int t[N];
  void init(int n) {
    for (int i = 1; i <= n; ++i)
      t[i] = i & -i;
  }
  void erase(int x) {
    while (x < N) --t[x], x += x & -x;
  }
  int query(int x) {
    int s = 0;
    while (x) s += t[x], x &= x - 1;
    return s;
  }
} sx, sy;

int eval(int i) { return sx.query(i) - sy.query(p[i]); }
int ans = 0;

#define LCH x << 1, l, mid
#define RCH x << 1 | 1, mid + 1, r
#define segc int mid = (l + r) >> 1

struct sgt {
  struct node {
    int mn, pos, tag;
  } t[1 << 20];
  void build(int x, int l, int r) {
    t[x].mn = INF; t[x].pos = l;
    if (l == r) return;
    segc;
    build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
  }
  void up(int x) {
    const auto &lc = t[x << 1], &rc = t[x << 1 | 1];
    if (lc.mn < rc.mn) t[x].mn = lc.mn, t[x].pos = lc.pos;
    else t[x].mn = rc.mn, t[x].pos = rc.pos;
    t[x].mn += t[x].tag;
  }
  void modify(int x, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
      t[x].mn += v; t[x].tag += v;
      return;
    }
    segc;
    if (ql <= mid) modify(LCH, ql, qr, v);
    if (qr > mid) modify(RCH, ql, qr, v);
    up(x);
  }
  void insert(int x, int l, int r, int p, int v) {
    if (x == 1) DBG("insert %d %d\n", p, v);
    if (l == r) { t[x].mn = v; return; }
    segc;
    v -= t[x].tag;
    p <= mid ? insert(LCH, p, v) : insert(RCH, p, v);
    up(x);
  }
} pf, sf;

set<int> pre, suf;

namespace findkey {
  struct node {
    int mn, mx;
  } t[1 << 20];
  void up(int x) {
    t[x].mn = min(t[x << 1].mn, t[x << 1 | 1].mn);
    t[x].mx = max(t[x << 1].mx, t[x << 1 | 1].mx);
  }
  void build(int x, int l, int r) {
    if (l == r) {
      if (l < p[l]) t[x].mn = p[l], t[x].mx = -INF;
      else t[x].mx = p[l], t[x].mn = INF;
      return;
    }
    segc; build(LCH); build(RCH); up(x);
  }
  void erase(int x, int l, int r, int p) {
    if (l == r) { t[x].mn = INF; t[x].mx = -INF; return; }
    segc; p <= mid ? erase(LCH, p) : erase(RCH, p); up(x);
  }
  void pmx(int x, int l, int r, int ql, int qr, int &mx) {
    if (t[x].mx < mx) return;
    if (l == r) {
      if (!pre.insert(p[l]).second) return;
      pf.insert(1, 1, n, l, eval(l));
      DBG("pmx insert %d p %d mx %d mxlim %d\n", l, p[l], t[x].mx, mx);
      mx = p[l];
      DBG("mx = %d\n", mx);
      return;
    }
    segc;
    if (ql <= mid) pmx(LCH, ql, qr, mx);
    if (qr > mid) pmx(RCH, ql, qr, mx);
  }
  void smn(int x, int l, int r, int ql, int qr, int &mn) {
    // DBG("SMN %d[%d, %d] mn %d\n", x, l, r, mn);
    if (t[x].mn > mn) return;
    if (l == r) {
      if (!suf.insert(p[l]).second) return;
      sf.insert(1, 1, n, l, -eval(l));
      mn = p[l];
      return;
    }
    segc;
    if (qr > mid) smn(RCH, ql, qr, mn);
    if (ql <= mid) smn(LCH, ql, qr, mn);
  }
};
// prefix max for i > p[i], while suffix min for i < p[i]

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  setbuf(stdout, 0);
#endif
  read(n);
  for (int i = 1; i <= n; ++i)
    read(p[i]), ip[p[i]] = i;
  sx.init(n); sy.init(n); pf.build(1, 1, n); sf.build(1, 1, n);
  findkey::build(1, 1, n);
  int $;
  findkey::pmx(1, 1, n, 1, n, $ = 0);
  findkey::smn(1, 1, n, 1, n, $ = n + 1);
  DBG("initalized\n");
  for (int i = 1; i <= n; ++i) {
    int pos;
    if (pf.t[1].mn < sf.t[1].mn) { // pre mx, i > p[i]
      DBG("pre mx\n");
      ans = max(ans, pf.t[1].mn), pos = pf.t[1].pos;
      sx.erase(pos); sy.erase(p[pos]);
      auto it = suf.upper_bound(p[pos]);
      if (it != suf.end()) {
        if (ip[*it] < pos) sf.modify(1, 1, n, ip[*it], pos - 1, -1), DBG("MODIFY");
      }
      findkey::erase(1, 1, n, pos);
      it = pre.find(p[pos]);
      assert(it != pre.end());
      it = pre.erase(it);
      int rb = it == pre.end() ? n : ip[*it] - 1;
      $ = it == pre.begin() ? 0 : *prev(it);
      findkey::pmx(1, 1, n, pos + 1, rb, $);
    }
    else { // suf mn, i < p[i]
      ans = max(ans, sf.t[1].mn), pos = sf.t[1].pos;
      sx.erase(pos); sy.erase(p[pos]);
      auto it = pre.upper_bound(p[pos]);
      if (it != pre.begin()) {
        --it;
        if (ip[*it] > pos) pf.modify(1, 1, n, pos + 1, ip[*it], -1);
      }
      findkey::erase(1, 1, n, pos);
      it = suf.find(p[pos]);
      assert(it != suf.end());
      it = suf.erase(it);
      $ = it == suf.end() ? n + 1 : *it;
      int lb = it == suf.begin() ? 1 : ip[*prev(it)] + 1;
      findkey::smn(1, 1, n, lb, pos - 1, $);
    }
    DBG("i = %d ans = %d\n", i, ans);
    assert(ans <= n);
    assert(1 <= pos && pos <= n);
    pf.insert(1, 1, n, pos, INF); sf.insert(1, 1, n, pos, INF);
  }
  printf("%d\n", ans);
  return 0;
}