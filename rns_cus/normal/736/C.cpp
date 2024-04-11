#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 110

LL dp[N][N], f[N];
const int mod = 1e9 + 7;
vector <int> v[N];
int n, k;

void dfs(int x, int pre = 0){
	dp[x][0] = dp[x][k+1] = 1;
	for (auto y : v[x]) if(y != pre) {
		dfs(y, x);
		for(int i = 0; i <= 2 * k; i ++){
			for(int j = 0; j <= 2 * k; j ++){
				int t = (i + j <= 2 * k) ? min(i, j + 1) : max(i, j + 1);
				f[t] = (f[t] + dp[x][i] * dp[y][j]) % mod;
			}
		}
		for(int i = 0; i <= 2 * k; i ++) dp[x][i] = f[i], f[i] = 0;
	}
}

int x, y;

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; i ++){
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1, 0);

	int ans = 0;
	for(int i = 0; i <= k; i ++) ans = (ans + dp[1][i]) % mod;
	cout << ans << endl;
}