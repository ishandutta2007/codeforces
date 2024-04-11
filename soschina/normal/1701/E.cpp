#include <cstdio>
#include <iostream>
using namespace std;
const int N = 5002, INF = 10000;

int T, n, m, f[N][N], g[N][N];
char s[N], t[N];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		scanf("%s%s", s + 1, t + 1);
		f[n + 1][m + 1] = 0;
		f[n][m + 1] = 0;
		f[n + 1][m] = 10000;
		for (int j = 1; j <= m; j++)
			f[n + 1][j] = 10000;
		for (int i = n; i; i--)
			for (int j = m + 1; j; j--){
				f[i][j] = f[i + 1][j] + 1;
				if (s[i] == t[j])
					f[i][j] = min(f[i][j], f[i + 1][j + 1] + 1);
			}
		g[0][0] = 0;
		g[0][1] = 10000;
		g[1][0] = 2;
		for (int j = 1; j <= m; j++)
			g[0][j] = 10000;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++){
				g[i][j] = g[i - 1][j] + 2;
				if (s[i] == t[j])
					g[i][j] = min(g[i][j], g[i - 1][j - 1] + 1);
			}
		for (int j = 1; j <= m; j++)
			for (int i = 1; i <= n; i++)
				if(s[i] == t[j])
					g[i][j] = min(g[i][j], g[i - 1][j - 1]);
		for (int j = m; j; j--)
			for (int i = n; i; i--)
				if(s[i] == t[j])
					f[i][j] = min(f[i][j], f[i + 1][j + 1]);
		int ans = f[1][1];
		for (int j = 0; j <= m; j++)
			for (int i = 0; i <= n; i++){
				ans = min(ans, g[i][j] + f[i + 1][j + 1] + 1);
			}
		printf("%d\n", ans >= 10000 ? -1 : ans);
	}
	return 0;
}