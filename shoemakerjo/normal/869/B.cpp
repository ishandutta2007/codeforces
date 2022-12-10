#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll a, b;
	cin >> a >> b;
	if (b - a >= 10) {
		cout << 0 << endl;
	}
	else {
		ll ans = 1LL;
		for (ll c = a+1; c <= b; c++) {
			ans = ((c%10)*ans)%10LL;
		}
		cout << ans << endl;
	}
	// cin >> a;
}