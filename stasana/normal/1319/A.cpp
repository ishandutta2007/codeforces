// Codeforces - mycopka

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef int64_t ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll cnt1 = 0;
	ll cnt2 = 0;
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		a[i] = a[i] - x;
		if (a[i] == 1) {
			++cnt1;
		}
		if (a[i] == -1) {
			++cnt2;
		}
	}
	if (cnt1 == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << (cnt2 + cnt1)/ cnt1 << endl;
	return 0;
}