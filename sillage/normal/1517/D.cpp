#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
long long f[maxn][maxn][21];
int n, m, k;
long long w1[maxn][maxn], w2[maxn][maxn];
long long dfs(int l,int r,int k) {
	if (k == 0) return f[l][r][k]=0;
	if (~f[l][r][k]) return f[l][r][k];
	long long mn = 1e18;
	if (l > 1) mn = min(mn, dfs(l - 1, r, k - 1) + 2 * w2[l - 1][r]);
	if (l < n) mn = min(mn, dfs(l + 1, r, k - 1) + 2 * w2[l][r]);
 
	if (r > 1) mn = min(mn, dfs(l, r - 1, k - 1) + 2 * w1[l][r - 1]);
	if (r < m) mn = min(mn, dfs(l, r + 1, k - 1) + 2 * w1[l][r]);
	return f[l][r][k] = mn;
}

int main(){
	cin >> n >> m >> k;
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++) scanf("%lld", &w1[i][j]);
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++) scanf("%lld", &w2[i][j]);
	if (k & 1) {
		for (int i = 1; i <= n; i++, puts(""))
			for (int j = 1; j <= m; j++) printf("-1 ");
		return 0;
	}
	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 1; j <= m; j++) printf("%lld ", dfs(i, j, k / 2));
	return 0;
}