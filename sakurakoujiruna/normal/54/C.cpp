#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = ll(1e3) + 11;

double p[N];
double dp[N][N];

int main() {
	cout << fixed << setprecision(12);
	ios :: sync_with_stdio(false);
	int n; cin >> n;

	auto solve = [](ll n) {
		ll ret = 0;
		for(ll i = 0, pow10 = 1; i <= 18; i ++, pow10 *= 10) {
			if(pow10 <= n) {
				if(pow10 * 2 <= n)
					ret += pow10;
				else
					ret += n - pow10 + 1;
			}
		}
		return ret;
	};
	for(int i = 1; i <= n; i ++) {
		ll l, r; cin >> l >> r;
		p[i] = double(solve(r) - solve(l - 1)) / (r - l + 1);
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= i; j ++) {
			dp[i][j] += (1 - p[i]) * dp[i - 1][j];
			if(j > 0)
				dp[i][j] += p[i] * dp[i - 1][j - 1];
		}

	double ans = 0;
	int k; cin >> k;
	for(int i = 0; i <= n; i ++)
		if(100 * i >= n * k)
			ans += dp[n][i];

	cout << ans << '\n';
	return 0;
}