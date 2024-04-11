#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400 + 10;

int dp[N][N], c[N][N], f[N][N];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	auto upd = [&](int &x, int y) {
		x += y;
		if (x >= m) x %= m; 
	};

	vector<int> g(n+1, 0);

	for (int i = 1; i <= n; i ++) {
		memset(f,0,sizeof(f));
		f[1][i] = 1;
		for (int j = i - 1; j >= 0; j --) {
			for (int k = 1; k + j - 1 <= i; k ++) {
				int l=k, r=k+j-1;
				if(r+1<=i)
					upd(f[l][r], f[l][r+1]);
				if(l-1>=1)
					upd(f[l][r], f[l-1][r]);
			}
		}
		for (int j = 1; j <= i; j ++) {
			upd(g[i], f[j][j]);
		}
		//printf("g[%d] = %d\n", i, g[i]);
	}


	for (int i = 0; i < N; i ++) c[i][0] = 1;
	for (int i = 1; i < N; i ++) for (int j = 1; j <= i; j ++) 
		c[i][j] = (c[i-1][j] + c[i-1][j-1]) % m;

	vector<int> fac(n+1,0);
	fac[0] = 1;
	for (int i = 1; i <= n; i ++) {
		fac[i] = 1LL * fac[i-1] * i % m;
	}


	dp[0][0] = 1;
	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= n; j ++) {
			//if (dp[i][j]) printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
			for (int k = j + 1; k <= n; k ++) {
				//printf("(%d,%d)=>(%d,%d)\n", i,j,i+1,k);
				if (j >= 1)
					upd(dp[i+1][k], 1LL * dp[i][j] * g[k-j-1] % m * c[k-i][k-j-1] % m);
				else
					upd(dp[i+1][k], 1LL * dp[i][j] * g[k] % m);
			}	
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += 1LL * dp[i][n];
		ans %= m;
	}
	cout << ans << endl;
}