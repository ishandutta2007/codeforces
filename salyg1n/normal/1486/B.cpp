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
		vector<ll> x, y;
		for (int j = 0; j < n; ++j) {
			ll x1, y1;
			cin >> x1 >> y1;
			x.push_back(x1);
			y.push_back(y1);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		if (n % 2 == 0)
			cout << (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1]  + 1);
		else
			cout << 1;
		cout << "\n";
	}
}