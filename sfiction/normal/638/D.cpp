#include <cstdio>

const int MAXN = 1E2 + 5;

char s[MAXN][MAXN][MAXN];

int main(){
	int n, m, K;
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j){
			scanf("%s", s[i][j] + 1);
			for (int k = 1; k <= K; ++k)
				s[i][j][k] -= '0';
		}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int k = 1; k <= K; ++k)
				if (s[i][j][k]){
					ans += s[i - 1][j][k] && (s[i + 1][j][k] || s[i][j + 1][k] && !s[i - 1][j + 1][k] || s[i][j][k + 1] && !s[i - 1][j][k + 1])
						|| s[i][j - 1][k] && (s[i][j + 1][k] || s[i + 1][j][k] && !s[i + 1][j - 1][k] || s[i][j][k + 1] && !s[i][j - 1][k + 1]) 
						|| s[i][j][k - 1] && (s[i][j][k + 1] || s[i + 1][j][k] && !s[i + 1][j][k - 1] || s[i][j + 1][k] && !s[i][j + 1][k - 1]);
				}
	printf("%d\n", ans);
	return 0;
}