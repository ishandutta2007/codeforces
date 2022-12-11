#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, inv2 = 499122177;

int R;
vector <int> from[310];
int dp[310][310][2];
long long tmp[310][2];

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void dfs(int x, int last) {
	for (int j = 0; j <= R; j++) {
		for (int pd = 0; pd < 2; pd++) {
			if (pd != (j == R || j == 0)) dp[x][j][pd] = 0;
			else dp[x][j][pd] = (j == R ? mod - inv2 : j == 0 ? 1 : inv2);
		}
	}
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dfs(v, x);
		for (int j = 0; j <= R; j++) {
			tmp[j][0] = tmp[j][1] = 0;
		}
		for (int j = 0; j <= R; j++) {
			for (int pd = 0; pd < 2; pd++) {
				for (int k = j - 1; k <= j + 1; k++) {
					if (k < 0 || k > R) continue;
					long long val = dp[v][k][1] + (j == k + 1 ? dp[v][k][0] : 0);
					tmp[j][pd | (k == j + 1)] += val * dp[x][j][pd];
				}
			}
		}
		for (int j = 0; j <= R; j++) {
			for (int pd = 0; pd < 2; pd++) {
				dp[x][j][pd] = tmp[j][pd] % mod;
			}
		}
	}
}

int main() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		from[x].push_back(y);
		from[y].push_back(x);
	}
	long long ans = 0, inv = power(inv2, n);
	for (R = 1; R <= n; R++) {
		dfs(1, 1);
		for (int i = 0; i <= R; i++) {
			ans = (ans + mod - dp[1][i][1]) % mod;
		}
		ans = (ans + 1) % mod;
	}
	cout << (ans - 1 + power(inv2, n)) % mod << endl;
	return 0;
}