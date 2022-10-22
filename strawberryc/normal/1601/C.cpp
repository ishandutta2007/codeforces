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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 1e6 + 5, M = N << 1, L = M << 1;

int n, m, a[N], b[N], A[N], p[M], tot;
ll ans;
std::vector<int> pos[M];

struct seg {
  int s, mi;
  
  friend inline seg operator + (seg a, seg b) {
  	return (seg) {a.s + b.s, Min(a.mi, a.s + b.mi)};
  }
} T[L];

void changeA(int x, int v) {
  for (; x <= n; x += x & -x)
    A[x] += v;
}

int askA(int x) {
  int res = 0;
  for (; x; x -= x & -x)
    res += A[x];
  return res; 
}

void build(int l, int r, int p) {
  if (l == r) return (void) (T[p] = (seg) {1, 0});
  int mid = l + r >> 1;
  build(l, mid, p2); build(mid + 1, r, p3);
  T[p] = T[p2] + T[p3];
}

void change(int l, int r, int pos, int v, int p) {
  if (l == r) return (void) (T[p] = (seg) {v, Min(v, 0)});
  int mid = l + r >> 1;
  if (pos <= mid) change(l, mid, pos, v, p2);
  else change(mid + 1, r, pos, v, p3);
  T[p] = T[p2] + T[p3];
}

void yhjssa() {
  read(n); read(m);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= m; i++) read(b[i]);
  ans = tot = 0;
  for (int i = 1; i <= n; i++) A[i] = 0, p[i] = i;
  std::sort(p + 1, p + n + 1, [&](int x, int y)
    {return a[x] > a[y] || (a[x] == a[y] && x > y);});
  for (int i = 1; i <= n; i++) ans += askA(p[i]), changeA(p[i], 1);
  std::sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++) p[++tot] = a[i];
  for (int i = 1; i <= m; i++) p[++tot] = b[i];
  std::sort(p + 1, p + tot + 1);
  tot = std::unique(p + 1, p + tot + 1) - p - 1;
  for (int i = 1; i <= n; i++)
    a[i] = std::lower_bound(p + 1, p + tot + 1, a[i]) - p;
  for (int i = 1; i <= m; i++)
    b[i] = std::lower_bound(p + 1, p + tot + 1, b[i]) - p;
  for (int i = 1; i <= tot; i++) pos[i].clear();
  for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);
  build(1, n, 1);
  for (int i = 1, k = 1, cur = 0; i <= tot; i++) {
  	int tcur = cur;
  	for (int j = 0; j < pos[i].size(); j++) change(1, n, pos[i][j], 0, 1), cur++;
  	for (int j = 0; j < pos[i - 1].size(); j++) change(1, n, pos[i - 1][j], -1, 1);
  	while (k <= m && b[k] == i) ans += tcur + T[1].mi, k++;
  }
  printf("%lld\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}