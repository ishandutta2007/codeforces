#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	cin >> t;
	for (ll i = 0; i < t; ++i) {
		ll n;
		cin >> n;
		ll sum1 = 0, sum2 = 0;
		string ans = "YES";
		for (ll j = 0; j < n; ++j) {
			ll x;
			cin >> x;
			sum1 += x;
			sum2 += j;
			if (sum1 < sum2)
				ans = "NO";
		}
		cout << ans << "\n";
	}
}