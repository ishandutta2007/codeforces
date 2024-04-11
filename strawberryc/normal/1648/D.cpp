#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 5e5 + 5, M = N << 2;
const ll INF = 6e18;

int n, q, a[3][N];
ll sl[N], sr[N], si[N], f[N], ans = -INF, T[M], xl[N], xr[N];

struct wd {
  int l, r, k;
} que[N];

struct elem {
  ll maxl, maxr, maxlr;
  
  friend inline elem operator + (elem a, elem b) {
  	return (elem) {Max(a.maxl, b.maxl), Max(a.maxr, b.maxr),
	  Max(Max(a.maxlr, b.maxlr), a.maxl + b.maxr)};
  }
} D[M];

void change(int l, int r, int pos, ll v, int p) {
  T[p] = Max(T[p], v);
  if (l == r) return;
  int mid = l + r >> 1;
  if (pos <= mid) change(l, mid, pos, v, p2);
  else change(mid + 1, r, pos, v, p3);
}

ll ask(int l, int r, int s, int e, int p) {
  if (e < l || s > r) return -INF;
  if (s <= l && r <= e) return T[p];
  int mid = l + r >> 1;
  return Max(ask(l, mid, s, e, p2), ask(mid + 1, r, s, e, p3));
}

void build(int l, int r, int p) {
  if (l == r) return (void) (D[p] = (elem) {xl[l], xr[r], xl[l] + xr[r]});
  int mid = l + r >> 1;
  build(l, mid, p2); build(mid + 1, r, p3);
  D[p] = D[p2] + D[p3];
}

elem query(int l, int r, int s, int e, int p) {
  if (l == s && r == e) return D[p];
  int mid = l + r >> 1;
  if (e <= mid) return query(l, mid, s, e, p2);
  else if (s > mid) return query(mid + 1, r, s, e, p3);
  else return query(l, mid, s, mid, p2) + query(mid + 1, r, mid + 1, e, p3);
}

int main() {
  for (int i = 0; i < M; i++) T[i] = -INF;
  read(n); read(q);
  for (int o = 0; o < 3; o++)
    for (int i = 1; i <= n; i++) read(a[o][i]);
  for (int i = 1; i <= q; i++) read(que[i].l), read(que[i].r), read(que[i].k);
  std::sort(que + 1, que + q + 1, [&](wd u, wd v) {return u.r < v.r;});
  for (int i = 1; i <= n; i++) sl[i] = sl[i - 1] + a[0][i],
    si[i] = si[i - 1] + a[1][i];
  for (int i = n; i >= 1; i--) sr[i] = sr[i + 1] + a[2][i];
  for (int i = 1; i <= n; i++) xl[i] = sl[i] - si[i - 1], xr[i] = sr[i] + si[i];
  build(1, n, 1);
  for (int i = 1; i <= q; i++) {
  	int l = que[i].l, r = que[i].r;
  	elem z = query(1, n, l, r, 1);
  	f[i] = Max(z.maxl, ask(1, n, l - 1, r - 1, 1)) - que[i].k;
  	change(1, n, r, f[i], 1);
  	ans = Max(ans, z.maxlr - que[i].k);
  }
  for (int i = 1; i <= n; i++) xl[i] = -INF;
  for (int i = 1; i <= q; i++) xl[que[i].r + 1] = Max(xl[que[i].r + 1], f[i]);
  build(1, n, 1);
  for (int i = 1; i <= q; i++)
    ans = Max(ans, query(1, n, que[i].l, que[i].r, 1).maxlr - que[i].k);
  return std::cout << ans << std::endl, 0;
}