#include <stdio.h>
const int maxn = 510;
int a[maxn][maxn], col[maxn], row[maxn];
int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			int t; scanf("%d", &t);
			a[i][j] ^= t;
		}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	bool ans = true;
	for(int i = 1; i <= n; ++i) if(row[i] & 1) ans = false;
	for(int i = 1; i <= m; ++i) if(col[i] & 1) ans = false;
	printf("%s\n", ans ? "Yes" : "No");
	return 0;
}