#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	bool ok = false;
	for (ll i = l; i <= r; i++) {
		if (i % k == 0 && i/k <= y && i/k >= x) ok = true;
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	cin >> l;
}