#include <bits/stdc++.h>

using namespace std;

#define N 1010

char s[N], t[N];
int n, m, K;
int f[11][N][N], g[11][N][N];

template <typename T> inline void chkmax(T &a, T b) { if(a < b) a = b; }

int main() {
	scanf("%d%d%d", &n, &m, &K);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
		if(s[i] == t[j]) {
			for(int k = 1; k <= K; k ++) {
				f[k][i][j] = g[k][i-1][j-1] + 1;
				chkmax(f[k][i][j], f[k-1][i-1][j-1] + 1);
				g[k][i][j] = f[k][i][j];
			}
		}
		for(int k = 1; k <= K; k ++) {
			chkmax(f[k][i][j], f[k][i-1][j]);
			chkmax(f[k][i][j], f[k][i][j-1]);
		}
	}
	printf("%d\n", f[K][n][m]);
	return 0;
}