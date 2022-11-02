#include <bits/stdc++.h>
using namespace std;

const int N = 1011;

int c[2][N][N];
int f[2][N][N];

void dfs(int f[N][N], int c[N][N], int i, int j) {
	if(i == 1 && j == 1) return;
	if(i != 1 && f[i][j] == f[i - 1][j] + c[i][j]) {
		dfs(f, c, i - 1, j);
		putchar('D');
	} else {
		dfs(f, c, i, j - 1);
		putchar('R');
	}
}

int main() {
	int n; scanf("%d", &n);
	bool zero = false;
	int zi;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++) {
			int x; scanf("%d", &x);
			if(x == 0) {
				zero = true;
				zi = i;
				c[0][i][j] = c[1][i][j] = 1;
			} else {
				while(x % 2 == 0) { x /= 2; c[0][i][j] ++; }
				while(x % 5 == 0) { x /= 5; c[1][i][j] ++; }
			}
		}
	memset(f, 0x3f, sizeof(f));
	f[0][0][1] = f[1][0][1] = 0;
	for(int t = 0; t < 2; t ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				f[t][i][j] = min(f[t][i - 1][j], f[t][i][j - 1]) + c[t][i][j];
	int ans = min(f[0][n][n], f[1][n][n]);
	if(zero) ans = min(ans, 1);
	printf("%d\n", ans);
	if(ans == 1 && zero) {
		for(int i = 1; i < zi; i ++) putchar('D');
		for(int i = 1; i < n; i ++) putchar('R');
		for(int i = zi; i < n; i ++) putchar('D');
	}
	else if(ans == f[0][n][n])
		dfs(f[0], c[0], n, n);
	else 
		dfs(f[1], c[1], n, n);
	puts("");
	return 0;
}