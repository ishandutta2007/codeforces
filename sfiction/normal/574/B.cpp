#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 4E3 + 10, MAXM = 4E3 + 10;

int e[MAXM][2];

int deg[MAXN];
bool a[MAXN][MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		++deg[e[i][0] = u];
		++deg[e[i][1] = v];
		a[u][v] = a[v][u] = true;
	}
	int ans = 1E8;
	for (int i = 0; i < m; ++i){
		int u = e[i][0], v = e[i][1];
		for (int j = 1; j <= n; ++j)
			if (j != u && j != v && a[u][j] && a[v][j])
				ans = min(ans, deg[u] + deg[v] + deg[j] - 6);
	}
	printf("%d\n", ans > 1E6 ? -1 : ans);
	return 0;
}