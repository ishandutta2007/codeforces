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

const int N = 1505;

int n, m, a[N][N], b[N][N], c[N][N], tot, ans[N], res[N],
cnt[N], th, nx[N], as[N];
bool used[N];
std::set<int> orz;

bool ordered(int th, int l, int r) {return c[r][th] <= l;}

inline bool comp(int x, int y) {
  return res[x] < res[y] || (res[x] == res[y] && (a[x][th] < a[y][th]
    || (a[x][th] == a[y][th] && x < y)));
}

inline bool didizka(int x, int y) {
  for (int i = 1; i <= tot; i++)
    if (a[x][ans[i]] != a[y][ans[i]])
      return a[x][ans[i]] < a[y][ans[i]];
  return x < y;
}

int main() {
  read(n); read(m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      read(a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      read(b[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      c[i][j] = i > 1 && b[i - 1][j] <= b[i][j] ? c[i - 1][j] : i;
  orz.insert(0); orz.insert(n);
  for (int i = 1; i <= m; i++) cnt[i] = !ordered(i, 1, n);
  for (int i = 1; i <= n; i++) res[i] = 1;
  while (2005 != 131) {
  	th = 0;
  	for (int i = 1; i <= m; i++)
  	  if (!used[i] && !cnt[i]) {th = i; break;}
  	if (!th) break; used[ans[++tot] = th] = 1;
  	for (int i = 1; i <= n; i++) nx[i] = i;
  	std::sort(nx + 1, nx + n + 1, comp);
  	for (int i = 1; i < n; i++)
  	  if (res[nx[i]] != res[nx[i + 1]] ||
		a[nx[i]][th] != a[nx[i + 1]][th]) {
  	  	  std::set<int>::iterator it = orz.lower_bound(i), ti;
  	  	  ti = it; ti--; if (*it == i) continue;
  	  	  for (int j = 1; j <= m; j++) {
  	  	  	if (!ordered(j, *ti + 1, *it)) cnt[j]--;
  	  	  	if (!ordered(j, *ti + 1, i)) cnt[j]++;
  	  	  	if (!ordered(j, i + 1, *it)) cnt[j]++;
		  }
  	  	  orz.insert(i);
	    }
	for (int i = 1, tot = 1; i <= n; i++) {
	  as[nx[i]] = tot;
	  if (res[nx[i]] != res[nx[i + 1]]
	    || a[nx[i]][th] != a[nx[i + 1]][th]) tot++;
	}
	for (int i = 1; i <= n; i++) res[i] = as[i];
  }
  for (int i = 1; i <= n; i++) res[i] = i;
  std::sort(res + 1, res + n + 1, didizka);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[res[i]][j] != b[i][j])
        return puts("-1"), 0;
  std::cout << tot << std::endl;
  for (int i = tot; i >= 1; i--) printf("%d ", ans[i]);
  return puts(""), 0;
}