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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5;

int n, m, a[N], l[N], r[N], tot, b[N], mx[N], pre[N], nxt[N], vis[N];

bool cont(int l, int r) {
  if (l < 1 || r > n) return 0;
  return mx[l] >= r;
}

int main() {
  int T; read(T);
  while (T--) {
  	read(n); read(m);
  	for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i], mx[i] = 0;
  	for (int i = 1; i <= m; i++) read(l[i]), read(r[i]);
  	std::sort(b + 1, b + n + 1);
  	tot = std::unique(b + 1, b + n + 1) - b - 1;
  	for (int i = 1; i <= n; i++)
	  a[i] = std::lower_bound(b + 1, b + tot + 1, a[i]) - b;
	for (int i = 1; i <= m; i++) mx[l[i]] = Max(mx[l[i]], r[i]);
	for (int i = 2; i <= n; i++) mx[i] = Max(mx[i], mx[i - 1]);
	for (int i = 1; i <= tot; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) pre[i] = vis[a[i]], vis[a[i]] = i;
	for (int i = 1; i <= tot; i++) vis[i] = n + 1;
	for (int i = n; i >= 1; i--) nxt[i] = vis[a[i]], vis[a[i]] = i;
	int ans, fis = n;
	while (fis > 1 && !cont(fis - 1, nxt[fis - 1])) fis--;
	for (int i = 1; i < fis; i++) vis[a[i]] = nxt[i];
	int j = 1;
	while (j < fis && !cont(pre[j], j) && !cont(j, vis[a[j]])) j++;
	ans = fis - j;
	for (int i = fis; i <= n; i++) {
	  vis[a[i]] = nxt[i];
	  while (j <= i && !cont(pre[j], j) && !cont(j, vis[a[j]])) j++;
	  ans = Min(ans, i - j + 1);
	}
	printf("%d\n", ans);
  }
  return 0;
}