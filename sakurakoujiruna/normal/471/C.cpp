#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios :: sync_with_stdio(false);
	ll n; cin >> n;
	int ans = 0;
	for(ll h = 1; h < 1e7; h ++) {
		ll c = h * (h + 1) / 2 * 3 - h;
		if((c - n) % 3 == 0 && c <= n)
			ans ++;
	}
	cout << ans << '\n';
	return 0;
}