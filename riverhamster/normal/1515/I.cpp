#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
// #define DBG(f...) printf("%3d: ", __LINE__), printf(f)
#define DBG(f...) void()
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

const int N = 200005;
const int logN = 18;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll cnt[N];
int n, pos[N];

struct item {
  ll cnt;
  int w, v, id;
} a[N];

struct BIT {
  struct node { ll sw, sv; } t[N];

  void insert(int p, ll w, ll v) {
    for (; p < N; p += p & -p)
      t[p].sw += w, t[p].sv += v;
  }
  ll queryv(int p) {
    ll s = 0;
    for (; p; p ^= p & -p)
      s += t[p].sv;
    return s;
  }
  ll queryw(int p) {
    ll s = 0;
    for (; p; p ^= p & -p)
      s += t[p].sw;
    return s;
  }
  int maxpos(ll w) {
    int p = 0;
    for (int i = __lg(N); i >= 0; --i) {
      int np = p | (1 << i);
      if (np < N && t[np].sw <= w)
        w -= t[np].sw, p = np;
    }
    return p;
  }
} small[logN];

struct segt {
  struct node {
    ll mn;
    ll tag;
  } t[N * 4];

  segt() { fill(all(t), node{INF, 0}); }

  void modify(int x, int l, int r, int ql, int qr, ll val) {
    if (ql <= l && r <= qr) {
      t[x].mn += val;
      t[x].tag += val;
      return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) modify(x << 1, l, mid, ql, qr, val);
    if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, val);
    t[x].mn = min(t[x << 1].mn, t[x << 1 | 1].mn) + t[x].tag;
  }

  int query(int x, int l, int r, int ql, ll val) {
    if (val < t[x].mn || r < ql) return -1;
    if (l == r) return l;
    int mid = (l + r) >> 1, ret = query(x << 1, l, mid, ql, val - t[x].tag);
    if (~ret) return ret;
    return query(x << 1 | 1, mid + 1, r, ql, val - t[x].tag);
  }
} large[logN];

void initalize() {
  for (int i = 1; i <= n; ++i) {
    large[__lg(a[i].w)].modify(1, 1, n, i, i, +a[i].w);
  }
}

void insert(int i, int cnt) {
  a[i].cnt += cnt;
  bool is_large = true;
  for (int k = __lg(a[i].w); k < logN; ++k, is_large = false) {
    if (is_large) {
      if (cnt && a[i].cnt == cnt) {
        large[k].modify(1, 1, n, i, i, -INF);
      }
      else if (!a[i].cnt && cnt < 0) {
        large[k].modify(1, 1, n, i, i, +INF);
      }
    }
    else {
      small[k].insert(i, (ll)cnt * a[i].w, (ll)cnt * a[i].v);
      large[k].modify(1, 1, n, i + 1, n, (ll)cnt * a[i].w);
    }
  }
}

ll query(ll cap) {
  ll ans = 0;
  int last = 0;
  while (cap) {
    int k = min(17LL, __lg(cap));
    ll removed_w = small[k].queryw(last);
    ll removed_v = small[k].queryv(last);
    int ps = small[k].maxpos(cap + removed_w);
    int pl = large[k].query(1, 1, n, last + 1, cap + removed_w);
    if (pl == -1 || ps < pl) {
      ll v = small[k].queryv(ps) - removed_v, w = small[k].queryw(ps) - removed_w;
      if (ps + 1 <= n) {
        ll ex_cnt = min(a[ps + 1].cnt, (cap - w) / a[ps + 1].w);
        if (ex_cnt) {
          last = ps + 1;
          v += ex_cnt * a[ps + 1].v;
          w += ex_cnt * a[ps + 1].w;
        }
        else last = ps;
      }
      else last = ps;
      ans += v; cap -= w;
      if (!w) return ans;
    }
    else {
      ll v = small[k].queryv(pl - 1) - removed_v, w = small[k].queryw(pl - 1) - removed_w;
      ans += v + a[pl].v; cap -= w + a[pl].w;
      last = pl;
    }
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int qc;
  read(n, qc);
  for (int i = 1; i <= n; ++i)
    read(a[i].cnt, a[i].w, a[i].v), a[i].id = i;
  sort(a + 1, a + 1 + n, [](const item &a, const item &b) {
    if (a.v == b.v) return a.w < b.w;
    return a.v > b.v;
  });
  for (int i = 1; i <= n; ++i)
    pos[a[i].id] = i;

  initalize();

  for (int i = 1, t; i <= n; ++i) {
    t = a[i].cnt; a[i].cnt = 0;
    insert(i, t);
  }
  while (qc--) {
    int opt;
    read(opt);
    if (opt == 1 || opt == 2) {
      int x, y;
      read(x, y);
      insert(pos[y], opt == 1 ? x : -x);
    }
    else {
      ll x;
      read(x);
      printf("%lld\n", query(x));
    }
  }
  return 0;
}