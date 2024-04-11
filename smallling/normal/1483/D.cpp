#include <bits/stdc++.h>

using namespace std;

const int N = 606;

int id[N][N], ans[N * N];
long long dis[N][N], lim[N][N], edge[N][N];

int main() {
	int n, m;
	memset(dis, 0x3f, sizeof(dis));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for(int i = 1; i <= m; i++) {
		int x, y, l;
		scanf("%d%d%d", &x, &y, &l);
		dis[x][y] = dis[y][x] = l;
		id[x][y] = id[y][x] = i;
		edge[x][y] = edge[y][x] = l;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	int q;
	scanf("%d", &q);
	while(q--) {
		int x, y, l;
		scanf("%d%d%d", &x, &y, &l);
		lim[x][y] = max(lim[x][y], 1ll * l);
		lim[y][x] = max(lim[y][x], 1ll * l);
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++) {
			long long curlim = 0;
			for(int j = 1; j <= n; j++) {
				if(lim[i][j]) {
					curlim = max(curlim, lim[i][j] - dis[k][j]);
				}
			}
			if(!curlim)continue;
			for(int j = 1; j <= n; j++)
				if(id[j][k] && dis[i][j] + edge[j][k] <= curlim) {
					ans[id[j][k]] = 1;
				}
		}
	int Ans = 0;
	for(int i = 1; i <= m; i++)
		Ans += ans[i];
	printf("%d\n", Ans);
}