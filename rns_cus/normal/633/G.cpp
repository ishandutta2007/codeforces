#include <bits/stdc++.h>
using namespace std;
#define M 200010

int n, m, flag[M], p[M], cnt;

vector <int> v[M];

void init(int m) {
	for (int i = 2; i < m; i++) {
		if (flag[i]) continue;
		for (int j = 2 * i; j < m; j += i) flag[j] = 1;
	}
	for (int i = 2; i < m; i++) if (!flag[i]) p[cnt++] = i;
}

int dt[M], ft[M], T, a[M], rev[M];

void dfs(int x, int pa) {
	dt[x] = ++T; rev[T] = x;
	for (int i = 0; i < v[x].size(); i++) {
		int u = v[x][i];
		if (u == pa) continue;
		dfs(u, x);
	}
	ft[x] = T;
}

const int D = 500;

int l[M], r[M], b[M];

int sz[M/D+3][1010];
int addv[M], vis[M], TT;

int main() {
	//freopen("G.in", "r", stdin);
	int x, y, val, Q, type;

	scanf("%d %d", &n, &m);
	init(m);

	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] %= m;
	for (int i = 1; i < n; i++) scanf("%d %d", &x, &y), v[x].push_back(y), v[y].push_back(x);
	dfs(1, 0);
	scanf("%d", &Q);

	int N = (n - 1) / D + 1;

	for (int i = 1; i <= N; i++) {
		int st = (i - 1) * D + 1, en = min(i * D, n);
		l[i] = st, r[i] = en;
		for (int j = st; j <= en; j++) {
			b[j] = a[rev[j]]; sz[i][b[j]]++;
		}
	}

	while (Q--) {
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d %d", &x, &val); val %= m;
			int st = dt[x], en = ft[x];
			int S = (st - 1) / D + 1, E = (en - 1) / D + 1;

			for (int i = S + 1; i < E; i++) {
				addv[i] += val; if (addv[i] >= m) addv[i] -= m;
			}
///
			if (addv[S]) {
				for (int i = l[S]; i <= r[S]; i++) {
					sz[S][b[i]]--; b[i] += addv[S]; if (b[i] >= m) b[i] -= m;
					sz[S][b[i]]++;
				}
				addv[S] = 0;
			}

			for (int i = st; i <= min(r[S], en); i++) {
				sz[S][b[i]]--; b[i] += val; if (b[i] >= m) b[i] -= m;
				sz[S][b[i]]++;
			}
///
			if (S != E) {
				if (addv[E]) {
					for (int i = l[E]; i <= r[E]; i++) {
						sz[E][b[i]]--; b[i] += addv[E]; if (b[i] >= m) b[i] -= m;
						sz[E][b[i]]++;
					}
					addv[E] = 0;
				}

				for (int i = l[E]; i <= min(r[E], en); i++) {
					sz[E][b[i]]--; b[i] += val; if (b[i] >= m) b[i] -= m;
					sz[E][b[i]]++;
				}
			}
		}
		else {
			++TT;
			scanf("%d", &x);
			int st = dt[x], en = ft[x];
			int S = (st - 1) / D + 1, E = (en - 1) / D + 1;
			int ans = 0;
			for (int j = 0; j < cnt; j++) {
				for (int i = S + 1; i < E; i++) {
					int t = (p[j] - addv[i] + m);
					if (t >= m) t -= m;
					if (sz[i][t]) {vis[j] = TT; ans++; break;}
				}
			}


			///
			if (addv[S]) {
				for (int i = l[S]; i <= r[S]; i++) {
					sz[S][b[i]]--; b[i] += addv[S]; if (b[i] >= m) b[i] -= m;
					sz[S][b[i]]++;
				}
				addv[S] = 0;
			}

     		for (int j = 0; j < cnt; j++) {
				if (vis[j] == TT) continue;
				for (int i = st; i <= min(r[S], en); i++) {
					if (b[i] == p[j]) {vis[j] = TT; ans++; break;}
				}
			}

			///
			if (S != E) {
				if (addv[E]) {
					for (int i = l[E]; i <= r[E]; i++) {
						sz[E][b[i]]--; b[i] += addv[E]; if (b[i] >= m) b[i] -= m;
						sz[E][b[i]]++;
					}
					addv[E] = 0;
				}
				for (int j = 0; j < cnt; j++) {
					if (vis[j] == TT) continue;
					for (int i = l[E]; i <= min(r[E], en); i++) {
						if (p[j] == b[i]) {vis[j] = TT; ans++; break;}
					}
				}
			}
			printf("%d\n", ans);
		}
	}
}