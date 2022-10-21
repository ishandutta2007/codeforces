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
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
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

const int N = 5e5 + 5;
const ll MIN = -1e16;

int pos[N], val[N];
ll a[N], b[N], c[N];
vector<pair<int, int>> rb[N];

struct modif {
  int l, r;
  ll v;
};

vector<modif> md[N];

struct ran {
  mutable int l, r;
  ll v;
  bool operator<(const ran &rhs) const { return r < rhs.r; }
};
set<ran> s;

void addrange(int l, int k, vector<modif> &op) {
  auto it = s.lower_bound({0, l, 0});
  if (it->v >= k) return;
  if (it->l != l) {
    int ol = it->l;
    it->l = l;
    s.insert({ol, l - 1, it->v});
  }
  auto rb = it;
  while (rb != s.end() && rb->v < k) {
    op.push_back({rb->l, rb->r, k - rb->v});
    ++rb;
  }
  int r = prev(rb)->r;
  s.erase(it, rb);
  s.insert({l, r, (ll)k});
}

struct node {
  ll tag, mx;
} t[1 << 20];

void build(int x, int l, int r) {
  t[x].mx = MIN;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
}

void modify(int x, int l, int r, int ql, int qr, ll v) {
  if (ql <= l && r <= qr) {
    t[x].mx += v; t[x].tag += v;
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) modify(x << 1, l, mid, ql, qr, v);
  if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, v);
  t[x].mx = max(t[x << 1].mx, t[x << 1 | 1].mx) + t[x].tag;
}

ll query(int x, int l, int r, int ql, int qr) {
  assert(ql <= qr);
  if (ql <= l && r <= qr) {
    return t[x].mx;
  }
  int mid = (l + r) >> 1;
  if (qr <= mid) return query(x << 1, l, mid, ql, qr) + t[x].tag;
  if (ql > mid) return query(x << 1 | 1, mid + 1, r, ql, qr) + t[x].tag;
  return max(query(x << 1, l, mid, ql, qr), query(x << 1 | 1, mid + 1, r, ql, qr)) + t[x].tag;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, q;
  read(n, q);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  for (int i = 1; i <= n; ++i)
    read(b[i]);
  for (int i = 1; i <= n; ++i)
    read(c[i]);
  partial_sum(a + 1, a + 1 + n, a + 1);
  partial_sum(b + 1, b + 1 + n, b + 1);
  partial_sum(c + 1, c + 1 + n, c + 1);

  while (q--) {
    int l, r, k;
    read(l, r, k);
    rb[r].emplace_back(l, -k);
  }
  s.insert({1, n, MIN});
  build(1, 1, n);
  for (int i = n; i >= 1; --i) {
    for (auto [l, v] : rb[i])
      addrange(l, v, md[i]);

    for (auto [l, r, v] : md[i])
      modify(1, 1, n, l, r, v);
  }
  ll ans = MIN;
  ll pdp = MIN;
  for (int i = 1; i <= n; ++i) {
    ll dp = MIN;
    if (i > 1) {
      dp = max(dp, b[i] + query(1, 1, n, 1, i - 1));
    }
    dp = max(dp, max(a[i], pdp) + (b[i] - b[i - 1]) + query(1, 1, n, i, i));
    modify(1, 1, n, i, i, max(pdp, a[i]) - b[i - 1]);
    ans = max(ans, dp + c[n] - c[i - 1]);
    pdp = dp;
    for (auto [l, r, v] : md[i])
      modify(1, 1, n, l, r, -v);
  }
  printf("%lld\n", ans);
  return 0;
}