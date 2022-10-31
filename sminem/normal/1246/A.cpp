#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, p;
	cin >> n >> p;
	if (p <= 0) {
		for (ll i=0;; i++) {
			ll x = n - p*i;
			ll pc = __builtin_popcountll(x);
			if (pc <= i && i <= x) {
				cout << i << '\n';
				return 0;
			}
		}
	} else {
		for (ll i=0; i<=1000000; i++) {
			ll x = n - p*i;
			if (x < 0)
				break;
			ll pc = __builtin_popcountll(x);
			if (pc <= i && i <= x) {
				cout << i << '\n';
				return 0;
			}
		}
		cout << "-1\n";
	}
		
	return 0;
}