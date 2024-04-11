#include <bits/stdc++.h>

using namespace std;

int w[205][205];
long long s[205][205], dp[205][205], f[205][205], fa[205];
int n;

long long dfs(int l, int r) {
	if (dp[l][r] > 0) return dp[l][r];
	if (l >= r) {
		f[l][r] = l;
		return 0;
	}
	long long ans = 1e18, pos = -1;
	for (int i = l; i <= r; ++i) {
		long long tmp = 0;
		for (int j = l; j <= i - 1; ++j) {
			tmp+=s[j][l-1]+s[j][n]-s[j][i-1];
//			for (int k = 1; k <= n; ++k) {
//				if (k < l || k >= i)
//					tmp += w[j][k];
//			}
		}
		for (int j = i + 1; j <= r; ++j) {
			tmp+=s[j][i]+s[j][n]-s[j][r];
//			for (int k = 1; k <= n; ++k) {
//				if (k <= i || k > r)
//					tmp += w[j][k];
//			}
		}
		tmp += dfs(l, i - 1) + dfs(i + 1, r);
		if (tmp < ans) ans = tmp, pos = i;
	}
	f[l][r] = pos;
	return dp[l][r] = ans;
}

void dfs2(int l, int r, int F) {
	if (l > r) return;
	int x = f[l][r];
	fa[x] = F;
	if (l == r) return;
	dfs2(l, x - 1, x);
	dfs2(x + 1, r, x);
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> w[i][j];
			s[i][j]=w[i][j]+s[i][j-1];
		}
	}
	memset(dp, -1, sizeof dp);
	dfs(1, n);
	dfs2(1, n, 0);
	for (int i = 1; i <= n; ++i) {
		cout << fa[i] << ' ';
	}
//	cout << dfs(1, n) << '\n';
//	for (int i = 1; i <= n; ++i) {
//		for (int j = i + 1; j <= n; ++j) {
//			cout << "pos[" << i << "][" << j << "]=" << f[i][j] << "\n";
//		}
//	}
	return 0;
}