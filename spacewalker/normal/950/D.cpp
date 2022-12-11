#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

ll solve(ll n, ll q) {
	if (q % 2 == 1 && q <= n) {
		return (q + 1) / 2;
	} else if (n % 2 == 0) {
		return solve(n/2, q/2) + n/2;
	} else {
		if (q == 2) {
			return solve(n/2, n/2) + n/2 + 1;
		} else {
			return solve(n/2, (q/2) - 1) + n/2 + 1;
		}
	}
}

int main() {
	ll n; int q; cin >> n >> q;
	for (int qta = 0; qta < q; ++qta) {
		ll qi; cin >> qi;
		cout << solve(n, qi) << endl;
	}
	return 0;
}