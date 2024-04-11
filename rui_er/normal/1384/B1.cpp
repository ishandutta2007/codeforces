//By: Luogu@rui_er(122461)
//
#include <bits/stdc++.h>
using namespace std;

int T, n, k, l, a[105][305], dp[105][305], vis[105][305];

bool dfs(int i, int j) {
	if(i == n + 1) {
		return true;
	}
	if(dp[i][j]) {
		return dp[i][j] == 2;
	}
	if(vis[i][j]) {
		return false;
	}
	vis[i][j] = 1;
	bool res = false;
	if(a[i+1][(j+1)%(2*k)] <= l) {
//		printf("test: %d %d %d %d\n", i, j, (i+j+1)%(2*k), a[j][(i+j+1)%(2*k)]);
		res |= dfs(i+1, (j+1)%(2*k));
	}
	if(a[i][(j+1)%(2*k)] <= l) {
//		printf("test: %d %d %d %d\n", i, j, (i+j)%(2*k), a[j][(i+j)%(2*k)]);
		res |= dfs(i, (j+1)%(2*k));
	}
	dp[i][j] = res ? 2 : 1;
	return res;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d%d", &n, &k, &l);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i][0]);
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=k;j++) {
				a[i][j] = a[i][j-1] + 1;
			}
			for(int j=1;j<k;j++) {
				a[i][k+j] = a[i][k+j-1] - 1;
			}
		}
/*		for(int i=1;i<=n;i++) {
			for(int j=0;j<2*k;j++) {
				printf("%d ", a[i][j]);
			}
			puts("");
		}*/
		if(dfs(0, 0)) {
			puts("Yes");
		}
		else {
			puts("No");
		}
	}
	return 0;
}