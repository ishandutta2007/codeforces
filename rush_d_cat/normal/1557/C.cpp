#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	vector<ll> pw(200000 + 10, 0);
	pw[0] = 1; for (int i = 1; i <= 200000; i ++) pw[i] = pw[i-1] * 2 % mod;

	int t; cin >> t;
	while (t --) {
		int n, k;
		cin >> n >> k;
		if (n == 1) {
			cout << pw[k] << endl; continue;
		}

		vector<ll> p(k+1, 0), q(k+1, 0), g(k+1, 0);
		p[0] = 1; q[0] = 1; g[0] = 1;
		for (int i = 1; i <= k; i ++) {
			p[i] = p[i-1] * pw[n] % mod;
			q[i] = q[i-1] * (pw[n-1] + 1) % mod;
			g[i] = g[i-1] * ((pw[n-1] - 1 + mod) % mod) % mod;
		}
		ll ans;
		if (n % 2 == 0) {
			ans = 0;
			for (int i = 0; i < k; i ++) {
				ans = (ans + g[i] * p[k-i-1] % mod) % mod;
			}
			ans = (ans + g[k]) % mod;
		} else {
			ans = 0;
			ans = (ans + q[k]) % mod;
		}
		cout << ans << endl;
	}
}