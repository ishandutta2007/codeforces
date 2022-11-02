#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	for (ll T = 0; T < t; ++T) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		map<ll, ll> m;
		for (auto& i : a)
			cin >> i;
		ll ans = 0;
		for (ll i = 1; i < n; ++i) {
			if (i == a[i] - a[0])
				ans++;
			m[i - (a[i] - a[0])]++;
		}
		for (auto i : m) {
			ans += i.second * (i.second - 1) / 2;
		}
		cout << ans << "\n";
	}
	return 0;
}