#include <bits/stdc++.h>

using namespace std;



const int INF = 1e9;



#define N 101010

#define M 101



int c[N];

int d[N][M];

int n, m, k, s;

bool vis[N];



vector <int> v[N];

int q[N];



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d %d %d", &n, &m, &k, &s);

	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);

	for (int i = 1, x, y; i <= m; i ++) {

		scanf("%d %d", &x, &y);

		v[x].push_back(y);

		v[y].push_back(x);

	}

	for (int i = 1; i <= n; i ++) for (int h = 1; h <= k; h ++) d[i][h] = INF;

	for (int h = 1; h <= k; h ++) {

		memset(vis, 0, sizeof vis);

		int e = 0;

		for (int i = 1; i <= n; i ++) if (c[i] == h) q[++e] = i, vis[i] = 1, d[i][h] = 0;

		for (int f = 1; f <= e; f ++) {

			int x = q[f];

			for (int i = 0; i < v[x].size(); i ++) {

				int y = v[x][i];

				if (vis[y]) continue;

				vis[y] = 1;

				d[y][h] = d[x][h] + 1;

				q[++e] = y;

			}

		}

	}

	for (int i = 1; i <= n; i ++) {

		sort(d[i] + 1, d[i] + k + 1);

		int ans = 0;

		for (int h = 1; h <= s; h ++) ans += d[i][h];

		printf("%d ", ans);

	}

	puts("");



	return 0;

}