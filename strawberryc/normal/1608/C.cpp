#include <bits/stdc++.h>

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

const int N = 1e5 + 5;

int n, fa[N], par[N];
char ans[N];

struct elem {
  int id, x, y;
} a[N];

int cx(int x) {
  if (fa[x] != x) fa[x] = cx(fa[x]);
  return fa[x];
}

void zm(int x, int y) {
  if ((x = cx(x)) != (y = cx(y))) fa[y] = x;
}

void yhjssa() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i].x), fa[i] = i;
  for (int i = 1; i <= n; i++) read(a[i].y), a[i].id = i;
  std::sort(a + 1, a + n + 1, [&](elem a, elem b) {return a.x < b.x;});
  for (int i = 1; i < n; i++) par[i] = i + 1;
  for (int i = 1; i <= n; i++) a[i].x = i;
  std::sort(a + 1, a + n + 1, [&](elem a, elem b) {return a.y < b.y;});
  for (int i = 1; i < n; i++) if (a[i].x > a[i + 1].x) {
  	int u = a[i + 1].x, v = a[i].x, w;
  	while ((w = cx(u)) < v) zm(w + 1, u);
  }
  std::sort(a + 1, a + n + 1, [&](elem a, elem b) {return a.x < b.x;});
  for (int i = 1; i <= n; i++) ans[a[i].id] = '0' + (cx(i) == n);
  for (int i = 1; i <= n; i++) putchar(ans[i]);
  puts("");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}