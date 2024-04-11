#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	ll mx = -1;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	ll cnt = 0;
	ll res = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] == mx) {
			cnt++;
		} else {
			cnt = 0;
		}
		res = max(res, cnt);
	}
	cout << res << "\n";
}

const ll TESTS = 1;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	for (ll i = 0; i < TESTS; i++) {
		solve();
	}
}