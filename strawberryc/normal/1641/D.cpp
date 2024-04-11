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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 1e5 + 5, wd = 998244353, jyh = 1e9 + 7,
I1 = 1145141919, I2 = 1191145149, M = N * 32;

int n, m, ans = 2111111111, ha[N][32], tot, cnt[M];

struct orz {
  int v[6], w;
} a[N];

struct wdzj {
  ll h; int x, y;
} hh[M];

int damn(int i) {
  int res = 0;
  for (int S = 0; S < (1 << m); S++) {
  	int delta = cnt[ha[i][S]];
  	for (int j = 0; j < m; j++)
  	  if ((S >> j) & 1) delta = -delta;
  	res += delta;
  }
  return res;
}

int main() {
  read(n); read(m);
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= m; j++)
  	  read(a[i].v[j]);
  	read(a[i].w);
  }
  std::sort(a + 1, a + n + 1, [&](orz u, orz v) {return u.w < v.w;});
  for (int i = 1; i <= n; i++) {
  	std::sort(a[i].v + 1, a[i].v + m + 1);
  	for (int S = 0; S < (1 << m); S++) {
  	  int h1 = 0, h2 = 0;
  	  for (int j = 1; j <= m; j++) {
  	    if (!((S >> j - 1) & 1)) continue;
  	    h1 = (1ll * h1 * I1 + a[i].v[j]) % wd;
  	    h2 = (1ll * h2 * I2 + a[i].v[j]) % jyh;
	  }
  	  hh[++tot] = (wdzj) {1ll * h1 * jyh + h2, i, S};
	}
  }
  std::sort(hh + 1, hh + tot + 1, [&](wdzj a, wdzj b) {return a.h < b.h;});
  for (int i = 1, c = 0; i <= tot; i++) {
  	if (i == 1 || hh[i].h != hh[i - 1].h) c++;
  	ha[hh[i].x][hh[i].y] = c;
  }
  for (int i = 1; i <= n; i++) for (int S = 0; S < (1 << m); S++) cnt[ha[i][S]]++;
  for (int i = 1, j = n; i <= n; i++) {
  	if (!damn(i)) continue;
  	while (damn(i)) {
  	  for (int S = 0; S < (1 << m); S++) cnt[ha[j][S]]--;
  	  j--;
	}
	ans = Min(ans, a[i].w + a[j + 1].w);
	if (!j) break;
  }
  return std::cout << (ans > 2000000000 ? -1 : ans) << std::endl, 0;
}