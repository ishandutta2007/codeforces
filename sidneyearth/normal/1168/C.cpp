#include <stdio.h>
const int m = 19;
const int maxn = 300100;
int a[maxn], lst[m + 10], f[maxn][m + 10], g[m + 10][m + 10];
int main(){
	int n, q; scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int j = 0; j < m; ++j)
		lst[j] = f[n+1][j] = n + 1;
	for(int k = n; k > 0; --k){
		for(int i = 0; i < m; ++i)
			f[k][i] = n + 1;
		for(int i = 0; i < m; ++i)
			if(a[k] >> i & 1){
				for(int j = 0; j < m; ++j)
					if(f[lst[i]][j] < f[k][j])
						f[k][j] = f[lst[i]][j];
				lst[i] = f[k][i] = k;
			}
	}
	for(int ca = 1; ca <= q; ++ca){
		int x, y; scanf("%d%d", &x, &y);
		for(int i = 0; i < m; ++i)
			g[0][i] = (a[x] >> i & 1) ? x : n + 1;
		for(int k = 1; k <= m; ++k){
			for(int i = 0; i < m; ++i)
				g[k][i] = n + 1;
			for(int i = 0; i < m; ++i)
				for(int j = 0; j < m; ++j)
					if(f[g[k-1][j]][i] < g[k][i])
						g[k][i] = f[g[k-1][j]][i];
		}
		bool ans = false;
		for(int i = 0; i < m; ++i)
			if((a[y] >> i & 1) && g[m][i] <= y)
				ans = true;
		printf("%s\n", ans ? "Shi" : "Fou");
	}
	return 0;
}