#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod;
int dp[505][505];
vector<int> a;

int main() {
	int n, m, b;
	cin >> n >> m >> b >> mod;
	a.resize(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	// x1 + x2 + ... + xn = m
	// a1x1 + a2x2 + ... + anxn <= b
	ll ans = 0;
	for(int i = 0; i < 505; i++)
		for(int j = 0; j < 505; j++)
			dp[i][j] = 0;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = a[i]; k <= b; k++) {
				dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;
			}
		}
	}
	for(int tb = 0; tb <= b; tb++)
		ans = (ans + dp[m][tb]) % mod;
	cout << ans << '\n';
}