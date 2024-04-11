#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <cassert>
#include <set>
#include <map>
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

const int N = 200005;
const int INF = 0x3f3f3f3f;

struct segment {
  mutable int l, r, mex, mdy;
  bool operator<(const segment &rhs) const {
    if (mex == rhs.mex) return mdy < rhs.mdy;
    return mex > rhs.mex;
  }
};

set<segment> s;
int n;

namespace t1 {
  int mn[N * 4];

  void modify(int x, int l, int r, int p, int v) {
    if (l == r) { mn[x] = v; return; }
    int mid = (l + r) >> 1;
    p <= mid ? modify(x << 1, l, mid, p, v) : modify(x << 1 | 1, mid + 1, r, p, v);
    mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
  }
  pair<int, int> query(int x, int l, int r, int lim) {
    if (mn[x] > lim) return {-1, 0};
    if (l == r) return {l, mn[x]};
    int mid = (l + r) >> 1;
    pair<int, int> ret = query(x << 1, l, mid, lim);
    return ~ret.first ? ret : query(x << 1 | 1, mid + 1, r, lim);
  }
}

namespace t2 {
  struct node {
    int lc, rc;
    int tagk, ks;
    ll tagb, bs;
  } t[N * 100];
  int nc = 0;

  void modify(int &x, int l, int r, int ql, int qr, int k, ll b) {
    t[++nc] = t[x]; x = nc;
    if (ql <= l && r <= qr) {
      t[x].tagk += k; t[x].tagb += b;
      t[x].ks += (ll)k * (r - l + 1); t[x].bs += b * (r - l + 1);
      return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) modify(t[x].lc, l, mid, ql, qr, k, b);
    if (qr > mid) modify(t[x].rc, mid + 1, r, ql, qr, k, b);
    t[x].ks = t[t[x].lc].ks + t[t[x].rc].ks + (r - l + 1) * t[x].tagk;
    t[x].bs = t[t[x].lc].bs + t[t[x].rc].bs + (r - l + 1) * t[x].tagb;
  }

  ll query(int x, int l, int r, int ql, int qr, int evalp) {
    if (ql <= l && r <= qr) {
      return t[x].bs + (ll)t[x].ks * evalp;
    }
    int mid = (l + r) >> 1, inter = min(r, qr) - max(l, ql) + 1;
    ll ans = (ll)inter * (evalp * t[x].tagk + t[x].tagb);
    if (ql <= mid) ans += query(t[x].lc, l, mid, ql, qr, evalp);
    if (qr > mid) ans += query(t[x].rc, mid + 1, r, ql, qr, evalp);
    return ans;
  }
}

vector<pair<int, int>> rt[N];

void push_back(int pos, int val) {
  s.insert(s.end(), segment{pos, pos, 0, pos});
  t1::modify(1, 0, n, val, pos);
  int root = rt[0].empty() ? 0 : rt[0].back().first;
  t2::modify(root, 1, n, pos, pos, 1, -pos + 1);
  rt[0].emplace_back(root, pos);

  auto itl = s.lower_bound({0, 0, val, 0});
  if (itl == s.end() || itl->mex != val) return;
  auto itr = s.upper_bound({0, 0, val, INF});
  int l = itl->l, r = prev(itr)->r;

  root = rt[val].empty() ? 0 : rt[val].back().first;
  for (auto it = itl; it != itr; ++it) {
    t2::modify(root, 1, n, it->l, it->r, -1, pos - 1); // x - mdy + 1 => pos - mdy
  }
  rt[val].emplace_back(root, pos);
  s.erase(itl, itr);

  auto hint = itr;
  int rb = r;
  while (rb >= l) {
    pair<int, int> lb = t1::query(1, 0, n, rb - 1); // mex, left boundary
    lb.second = max(lb.second + 1, l);
    hint = s.insert(hint, segment{lb.second, rb, lb.first, pos});
    int root = rt[lb.first].empty() ? 0 : rt[lb.first].back().first;
    t2::modify(root, 1, n, lb.second, rb, 1, -pos + 1);
    rt[lb.first].emplace_back(root, pos);
    rb = lb.second - 1;
  }
}

ll solve(int l, int r, int k) {
  auto it = partition_point(all(rt[k]), [&](pair<int, int> x) { return x.second <= r; });
  if (it == rt[k].begin()) return 0;
  int root = it[-1].first;
  return t2::query(root, 1, n, l, r, r);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll lst = 0;
  read(n);
  for (int i = 1; i <= n; ++i) {
    int val, l, r, k;
    read(val, l, r, k);
    val = (val + lst) % (n + 1);
    l = (l + lst) % i + 1;
    r = (r + lst) % i + 1;
    k = (k + lst) % (n + 1);
    if (l > r) swap(l, r);

    push_back(i, val);
    printf("%lld\n", lst = solve(l, r, k));
  }
  return 0;
}