#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e18 + 7;

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	vector <ll> mink(m, INF);
	mink[0] = 0;
	ll sum = 0, res = 0;
	for (ll i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		sum += x;
		ll add = (((i - 1) / m) + 1) * k;
		//cout << "iter " << i << " " << sum << " " << add << "\n";
		for (int t = 0; t < m; t++) {
			ll now = sum - add - mink[t];
			if (t != 0) {
				now -= k;
			}
			int val = (i % m == 0 ? m : i % m);
			//cout << now << "\n";
			//cout << t << ""  << now << "\n";
			if (t >= val) {
				now += k;
			}
			if (res < now) {
				res = now;
				//cout << now << " " << i << " " << t << "\n";
			}
		}
		mink[i % m] = min(mink[i % m], sum - add);
		//cout << i % m << " " << mink[i % m] << "\n";
	}	
	cout << res << "\n";
}