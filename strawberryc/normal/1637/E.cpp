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

typedef long long ll;

const int N = 3e5 + 5, B = 2005;

int n, m, a[N], val[N], cnt[N], tot, tot2, to[N], tc[N];
ll ans;
std::vector<int> orz[N];
std::vector<std::pair<int, int> > disa[B][B];
std::map<int, int> id;

void yuhangjiushishena(int u, int v) {
  if (u == v && orz[u].size() == 1) return;
  int bas = tc[u] + tc[v];
  std::sort(disa[u][v].begin(), disa[u][v].end(), [&]
    (std::pair<int, int> x, std::pair<int, int> y)
	  {return x.first > y.first || (x.first == y.first && x.second > y.second);});
  int cur = 0, n1 = orz[u].size() - 1, n2 = orz[v].size() - 1, n3 = disa[u][v].size();
  for (int i = n1; i >= 0; i--) {
  	if (cur == n3 || disa[u][v][cur].first != orz[u][i])
  	  return (void) (ans = Max(ans, 1ll * bas * (val[orz[u][i]] +
		val[orz[v][u == v && i == n2 ? n2 - 1 : n2]])));
    for (int j = n2; j >= 0; j--) {
      while (cur < n3 && disa[u][v][cur].first == orz[u][i]
	    && disa[u][v][cur].second > orz[v][j]) cur++;
	  if (u == v && i == j) continue;
	  if (!(cur < n3 && disa[u][v][cur].first == orz[u][i]
	    && disa[u][v][cur].second == orz[v][j])) {
	    ans = Max(ans, 1ll * bas * (val[orz[u][i]] + val[orz[v][j]]));
	    break;
	  }
	}
	while (cur < n3 && disa[u][v][cur].first == orz[u][i]) cur++;
  }
}

void yhjssa() {
  int x, y;
  id.clear();
  read(n); read(m); ans = 0;
  for (int i = 1; i <= n; i++) read(a[i]);
  std::sort(a + 1, a + n + 1); tot = tot2 = 0;
  for (int i = 1, c = 0; i <= n; i++)
    if (c++, i == n || a[i] != a[i + 1])
      cnt[++tot] = c, val[tot] = a[i], id[a[i]] = tot, c = 0;
  for (int i = 1; i <= n; i++) to[i] = 0;
  for (int i = 1; i <= tot; i++) if (!to[cnt[i]]) to[cnt[i]] = ++tot2,
    tc[tot2] = cnt[i];
  for (int i = 1; i <= tot2; i++) orz[i].clear();
  for (int i = 1; i <= tot; i++) orz[to[cnt[i]]].push_back(i);
  for (int i = 1; i <= tot2; i++) std::sort(orz[i].begin(), orz[i].end());
  for (int i = 1; i <= tot2; i++)
    for (int j = 1; j <= tot2; j++)
      disa[i][j].clear();
  while (m--) {
  	read(x); read(y); x = id[x]; y = id[y];
  	if (to[cnt[x]] > to[cnt[y]]) std::swap(x, y);
  	disa[to[cnt[x]]][to[cnt[y]]].push_back(std::make_pair(x, y));
  	if (to[cnt[x]] == to[cnt[y]])
  	  disa[to[cnt[x]]][to[cnt[y]]].push_back(std::make_pair(y, x));
  }
  for (int i = 1; i <= tot2; i++)
    for (int j = i; j <= tot2; j++)
      yuhangjiushishena(i, j);
  printf("%lld\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}