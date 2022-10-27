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
		vector<ll> a(n);	
		for (int i = 0; i < n; i ++)
			cin >> a[i];

		ll s = accumulate(a.begin(), a.end(), 0ll);
		// a[i] + a[j] = 2 * (s / n)
		if (2 * s % n) {
			cout << 0 << "\n"; continue;
		}
		ll sum = 2 * s / n;
		map<ll, int> mp;
		ll ans = 0;
		for (int i = 0; i < n; i ++) {
			ans += mp[sum - a[i]];
			mp[a[i]] ++;
		}
		cout << ans << "\n";
	}
}