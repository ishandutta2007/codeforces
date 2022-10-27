#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	//cin >> t;
	t = 1;
	while (t --) {
		int k;
		cin >> k;
		vector<ll> dp(k);
		dp[0] = 1;
		for (int i = 1; i < k; i ++) {
			dp[i] = dp[i-1] * dp[i-1] % mod * 16 % mod;
		}
		cout << 6 * dp[k-1] % mod << "\n";
	}
}