#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q; cin >> q;

	ll n, a, b;
	while (q--) {
		cin >> n >> a >> b;

		if (a*2 <= b) {
			cout << n*a << endl;
		}
		else {
			ll res = (n/2) * b;
			if (n%2 == 1) res += a;

			cout << res << endl;
		}
	}
}