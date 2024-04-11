#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	ll x = k + 1;
	ll val = k * a[0] + a[1];
	ll res = val * (m / x) + (m % x) * a[0];
	cout << res << "\n";
}

const ll TESTS = 1;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	for (ll i = 0; i < TESTS; i++) {
		solve();
	}
}