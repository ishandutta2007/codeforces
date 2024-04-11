#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; i += 1) cin >> a[i];
		for (int i = 0; i < n; i += 1) cin >> b[i];

		auto solve = [&](){
			ll res = 1e10;
			res = abs(a[0] - b[0]) + abs(a[n-1] - b[n-1]);
			
			ll f[2][2];
			for (int i = 0; i < 2; i ++) for (int j = 0; j < 2; j ++) f[i][j] = 1e10;
			
			for (int i = 0; i < n; i ++) f[0][0] = min(f[0][0], abs(a[0] - b[i]));
			for (int i = 0; i < n; i ++) f[0][1] = min(f[0][1], abs(a[n-1] - b[i]));
			for (int i = 0; i < n; i ++) f[1][0] = min(f[1][0], abs(b[0] - a[i]));
			for (int i = 0; i < n; i ++) f[1][1] = min(f[1][1], abs(b[n-1] - a[i]));

			res = min(res, abs(a[0] - b[0]) + f[0][1] + f[1][1]);
			res = min(res, abs(a[n-1] - b[n-1]) + f[0][0] + f[1][0]);
			res = min(res, f[0][0] + f[0][1] + f[1][0] + f[1][1]);
			//cout << f[0][0] + f[0][1] + f[1][0] + f[1][1] << "\n";
			return res;
		};
		ll ans = solve();
		reverse(a.begin(), a.end());
		ans = min(ans, solve());
		cout << ans << "\n";
	}
}