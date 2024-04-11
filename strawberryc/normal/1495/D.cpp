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

const int N = 405, M = 1205, INF = 0x3f3f3f3f, EI = 998244353;

int n, m, f[N][N], cnt[N], ad[N], z[N], ecnt, nxt[M], adj[N], go[M];
std::vector<std::pair<int, int> > ooo[N];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

int main() {
  memset(f, INF, sizeof(f)); memset(ad, -1, sizeof(ad));
  int x, y;
  read(n); read(m);
  while (m--) read(x), read(y), f[x][y] = f[y][x] = 1, add_edge(x, y), add_edge(y, x);
  for (int i = 1; i <= n; i++) f[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (f[i][k] + f[k][j] < f[i][j])
          f[i][j] = f[i][k] + f[k][j];
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      int d = f[x][y];
      memset(cnt, 0, sizeof(cnt));
      for (int i = 1; i <= n; i++)
        if (f[x][i] + f[i][y] == f[x][y]) cnt[f[x][i]]++, z[f[x][i]] = i;
      bool is = 1;
      for (int i = 0; i <= d; i++) if (cnt[i] != 1) is = 0;
      if (!is) {printf("0 "); continue;}
      for (int i = 0; i <= n; i++) ooo[i].clear();
      for (int i = 1; i <= n; i++)
        if (f[x][i] + f[i][y] > f[x][y]) {
          int dm = f[x][i] + f[i][y] - f[x][y],
            th = f[x][i] - (dm >> 1);
          if ((dm & 1) || th < 0 || th > d) is = 0;
          else ooo[th].push_back(std::make_pair(i, dm >> 1));
		}
	  if (!is) {printf("0 "); continue;}
	  int ans = 1;
	  for (int T = 0; T <= d; T++) {
	  	int md = 0, sz = ooo[T].size(); ad[z[T]] = 0;
	  	for (int i = 0; i < sz; i++) ad[ooo[T][i].first] = ooo[T][i].second;
	  	for (int i = 0; i < sz; i++) {
	  	  int u = ooo[T][i].first, cnt = 0;
	  	  for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
	  	    if (ad[v] + 1 == ad[u]) cnt++;
	  	  ans = 1ll * ans * cnt % EI;
		}
		for (int i = 0; i < sz; i++) ad[ooo[T][i].first] = -1;
		ad[z[T]] = -1;
	  }
	  printf("%d ", ans);
	}
	puts("");
  }
  return 0;
}