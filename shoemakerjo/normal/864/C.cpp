#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll spot = 0LL;
	ll a, b, f;
	int k;
	cin >> a >> b >> f >> k;
	ll curtank = b;
	bool ok = true;
	ll ans = 0LL;
	for (int i = 0; i < k; i++) {
		if (curtank < 0) {
			ok = false;
		}
		if (spot == 0LL) {
			if (curtank < f) {
				ok = false;
			}
			curtank-=f;
			if (i == k-1) {
				if (a-f > curtank) {
					ans += 1LL;
					curtank = b;
				}
			}
			else if (2LL*(a-f) > curtank) {
				ans += 1LL;
				curtank = b;
			}
			curtank -= (a-f);
			spot = a;
		}
		else {
			if (curtank < a-f) {
				ok = false;
			}
			curtank -= (a-f);
			if (i == k-1) {
				if (f > curtank) {
					curtank = b;
					ans += 1LL;
				}
			}
			else if (2LL*(f) > curtank ) {
				ans += 1LL;
				curtank = b;
			}
			curtank -= f;
			spot = 0LL;
		}
	}
	if (curtank < 0) {
		ok = false;
	}
	if (!ok) cout << -1 << endl;
	else cout << ans << endl;
	// cin >> ans;
}