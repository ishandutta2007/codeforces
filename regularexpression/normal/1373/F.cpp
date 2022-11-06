#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	using ll = long long;
	const ll INF = 2e18 + 123;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<ll> b(n);
		for (int i = 0; i < n; i++)
			cin >> b[i];
		auto getRest = [&] (ll rest) {
			for (int i = 1; i < n; i++) {
				ll need = max(0LL, a[i] - rest);
				rest = b[i] - need;
				if (rest < 0)
					return -INF;
			}
			return rest;
		};
		ll l = 0, r = b[0];
		while (r - l > 3) {
			ll m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			ll rest1 = max(-INF, getRest(m1) - m1);
			ll rest2 = max(-INF, getRest(m2) - m2);
			if (rest1 > rest2)
				r = m2;
			else
				l = m1;
		}
		ll maxRest = -INF;
		for (ll i = l; i <= r; i++)
			maxRest = max(maxRest, getRest(i) - i);
		cout << (maxRest >= a[0] - b[0] ? "YES\n" : "NO\n");
	}
	return 0;
}