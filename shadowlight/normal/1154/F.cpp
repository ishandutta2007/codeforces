#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e18 + 7;

int main() {
	//freopen("F.in", "r", stdin);
	//freopen("F.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	vector <ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <ll> xs(m), ys(m);
	for (ll i = 0; i < m; i++) {
		cin >> ys[i] >> xs[i];
	}
	vector <ll> res(k + 1, INF);
	res[0] = 0;
	sort(a.begin(), a.end());
	while (a.size() > k) a.pop_back();
	reverse(a.begin(), a.end());
	vector <ll> pref(k + 1, 0);
	pref[0] = 0;
	for (ll i = 1; i <= k; i++) {
		pref[i] = pref[i - 1] + a[i - 1];
		//cout << a[i - 1] << " " << pref[i] << "\n"; 
	}
	for (ll i = 0; i < k; i++) {
		for (ll j = 0; j < m; j++) {
			ll x = xs[j], y = ys[j];
			if (i + y > k) continue;
			res[i + y] = min(res[i + y], res[i] + pref[i + y - x] - pref[i]);
		}
	}
	ll ans = INF;
	for (ll i = 0; i <= k; i++) {
		ans = min(ans, res[i] + pref[k] - pref[i]);
	}
	cout << ans << "\n";
}