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
		for (int i = 0; i < n; i ++) cin >> a[i];
		sort(a.begin(), a.end());

		ll mn = (n-1) * a[0]   + accumulate(a.begin() + 1, a.end(), 0ll);
		ll mx = (n-1) * a[n-1] + accumulate(a.begin(), a.end() - 1, 0ll);
	
		if (mn <= 0 and mx >= 0) {		
			ll pre = 0, suf = accumulate(a.begin(), a.end(), 0ll);
			ll ans = - 1e18;
			for (int i = 0; i < n; i ++) {
				ll t = - a[i];
				ll res = - (a[0] + t) * (a[n-1] + t);
				pre += a[i];
				suf -= a[i];
				res += ((a[n-1] + t) * (pre + (i + 1) * t));
				res += ((a[0] + t) * (suf + (n - i - 1) * t));
				res -= (t * t) * (n - 1);
				
				
				ans = max(ans, res);
			}
			cout << ans << "\n";
		} else {	
			cout << "INF" << "\n";
		}
	}
}