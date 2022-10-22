#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e9 + 7;

void solve() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	ll res = INF;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	for (ll i = 0; i < n; i++) {
		for (ll j = 1; j <= 100; j++) {
			if (a[i] % j) continue;
			ll now = sum;
			now -= a[i];
			now -= a[(i ? 0 : 1)];
			now += a[i] / j;
			now += a[(i ? 0 : 1)] * j;
			res = min(res, now);
		}
	}
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