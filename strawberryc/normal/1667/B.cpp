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

const int N = 5e5 + 5, M = N << 2, INF = 0x3f3f3f3f;

int n, a[N], m, id[N], mx[N], T1[M], T2[M];
ll s[N], to[N];

void build(int l, int r, int p) {
  T1[p] = T2[p] = -INF;
  if (l == r) return (void) (mx[l] = -INF);
  int mid = l + r >> 1;
  build(l, mid, p2); build(mid + 1, r, p3);
}

void change(int l, int r, int pos, int v, int w, int x, int p) {
  if (l == r) return (void)
    (mx[pos] = Max(mx[pos], v), T1[p] = Max(T1[p], w), T2[p] = Max(T2[p], x));
  int mid = l + r >> 1;
  if (pos <= mid) change(l, mid, pos, v, w, x, p2);
  else change(mid + 1, r, pos, v, w, x, p3);
  T1[p] = Max(T1[p2], T1[p3]); T2[p] = Max(T2[p2], T2[p3]);
}

int ask1(int l, int r, int s, int e, int p) {
  if (e < l || s > r || s > e) return -INF;
  if (s <= l && r <= e) return T1[p];
  int mid = l + r >> 1;
  return Max(ask1(l, mid, s, e, p2), ask1(mid + 1, r, s, e, p3));
}

int ask2(int l, int r, int s, int e, int p) {
  if (e < l || s > r || s > e) return -INF;
  if (s <= l && r <= e) return T2[p];
  int mid = l + r >> 1;
  return Max(ask2(l, mid, s, e, p2), ask2(mid + 1, r, s, e, p3));
}

void yhjssa() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  for (int i = 0; i <= n; i++) to[i + 1] = s[i];
  std::sort(to + 1, to + n + 2);
  m = std::unique(to + 1, to + n + 2) - to - 1;
  for (int i = 0; i <= n; i++)
    id[i] = std::lower_bound(to + 1, to + m + 1, s[i]) - to;
  build(1, m, 1);
  change(1, m, id[0], 0, 0, 0, 1);
  for (int i = 1; i <= n; i++) {
  	int f = Max(mx[id[i]], Max(ask1(1, m, 1, id[i] - 1, 1) + i,
	  ask2(1, m, id[i] + 1, m, 1) - i));
	if (i == n) return (void) printf("%d\n", f);
	change(1, m, id[i], f, f - i, f + i, 1);
  }
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}