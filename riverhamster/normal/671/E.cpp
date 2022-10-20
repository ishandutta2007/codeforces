#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while (isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;
const ll inf = 1e15;

int n, K;
int g[N], w[N];
ll pre[N], suf[N];
int nxt[N], stk[N], top = 0;
vector<int> G[N];
int res[N];

// range increment, query max {i | a_i - min_{j=1}^{i-1} b_j <= K}
namespace segt {
  struct node {
    ll mna, mnb, mndiff, r_mndiff, tag;
  } t[N * 4];

  void tag(int x, ll v) { t[x].mnb += v; t[x].tag += v; t[x].mndiff -= v; t[x].r_mndiff -= v; }
  void down(int x) {
    if (t[x].tag) {
      tag(x << 1, t[x].tag);
      tag(x << 1 | 1, t[x].tag);
      t[x].tag = 0;
    }
  }
  ll getmin(int x, int l, int r, ll premin) {
    if (l == r) return t[x].mna - premin;
    int mid = (l + r) >> 1;
    down(x);
    if (t[x << 1].mnb <= premin) return min(t[x].r_mndiff, getmin(x << 1, l, mid, premin));
    return min(t[x << 1].mna - premin, getmin(x << 1 | 1, mid + 1, r, premin));
  }
  void up(int x, int l, int r) {
    int mid = (l + r) >> 1;
    t[x].mnb = min(t[x << 1].mnb, t[x << 1 | 1].mnb);
    t[x].r_mndiff = getmin(x << 1 | 1, mid + 1, r, t[x << 1].mnb);
    t[x].mndiff = min(t[x << 1].mndiff, t[x].r_mndiff);
  }

  ll _build_premin = inf;
  void build(int x = 1, int l = 1, int r = n) {
    if (l == r) {
      t[x].mna = suf[l]; t[x].mnb = suf[l];
      t[x].mndiff = suf[l] - _build_premin;
      t[x].r_mndiff = inf;
      _build_premin = min(_build_premin, suf[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    t[x].mna = min(t[x << 1].mna, t[x << 1 | 1].mna);
    up(x, l, r);
  }
  void modify(int ql, int qr, ll v, int x = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) return tag(x, v);
    int mid = (l + r) >> 1;
    down(x);
    if (ql <= mid) modify(ql, qr, v, x << 1, l, mid);
    if (qr > mid) modify(ql, qr, v, x << 1 | 1, mid + 1, r);
    up(x, l, r);
  }
  int query(ll premin = inf, int x = 1, int l = 1, int r = n) {
    if (l == r)
      return t[x].mna - premin <= K ? l : -1;
    int mid = (l + r) >> 1;
    down(x);
    ll tP = min(premin, t[x << 1].mnb);
    if (getmin(x << 1 | 1, mid + 1, r, tP) <= K) return query(tP, x << 1 | 1, mid + 1, r);
    return query(premin, x << 1, l, mid);
  }
} // namespace segt

namespace BIT {
  ll tr[N];
  void modify(int p, int v) {
    for (; p < N; p += p & -p) tr[p] += v;
  }
  int find(int k) {
    int p = 0;
    for (int i = __lg(N); i >= 0; --i) {
      int np = p | (1 << i);
      if (k >= tr[np]) {
        p = np;
        k -= tr[np];
      }
    }
    return min(p, n);
  }
} // namespace BIT

void DFS(int l) {
  if (nxt[l]) {
    segt::modify(nxt[l] - 1, n, pre[l] - pre[nxt[l]]);
    BIT::modify(nxt[l], pre[nxt[l]] - pre[l]);
  }
  int r = BIT::find(K);
  if (l > 1) segt::modify(1, l - 1, +inf);
  segt::modify(r, n, -inf);
  res[l] = segt::query() - l + 1;
  if (l > 1) segt::modify(1, l - 1, -inf);
  segt::modify(r, n, +inf);
  for (int v : G[l])
    DFS(v);
  if (nxt[l]) {
    segt::modify(nxt[l] - 1, n, pre[nxt[l]] - pre[l]);
    BIT::modify(nxt[l], pre[l] - pre[nxt[l]]);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, K);
  for (int i = 1; i < n; ++i) read(w[i]);
  for (int i = 1; i <= n; ++i) read(g[i]);
  pre[1] = 0;
  for (int i = 2; i <= n; ++i) pre[i] = pre[i - 1] + w[i - 1] - g[i - 1];
  suf[1] = 0;
  for (int i = 2; i <= n; ++i) suf[i] = suf[i - 1] + w[i - 1] - g[i];

  for (int i = n; i >= 1; --i) {
    while (top && pre[i] >= pre[stk[top]]) --top;
    stk[++top] = i;
    nxt[i] = stk[top - 1];
  }
  for (int i = 1; i <= n; ++i)
    if (nxt[i])
      G[nxt[i]].push_back(i);

  segt::build();

  for (int i = 1; i <= n; ++i)
    if (!nxt[i])
      DFS(i);

  printf("%d\n", max(1, *max_element(res + 1, res + 1 + n)));
  return 0;
}