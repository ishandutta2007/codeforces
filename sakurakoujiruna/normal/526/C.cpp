#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios :: sync_with_stdio(false);
	ll c, h1, h2, w1, w2;
	cin >> c >> h1 >> h2 >> w1 >> w2;
	if(w1 > 100 || w2 > 100) {
		if(w2 > 100) {
			swap(h1, h2);
			swap(w1, w2);
		}
		ll ans = 0;
		for(ll i = 0; i * w1 <= c; i ++)
			ans = max(ans, i * h1 + (c - i * w1) / w2 * h2);
		cout << ans << '\n';
	} else {
		if(h1 * w2 > h2 * w1) {
			swap(h1, h2);
			swap(w1, w2);
		}
		ll ans = 0;
		for(ll i = 0; i <= w2 && i * w1 <= c; i ++)
			ans = max(ans, i * h1 + (c - i * w1) / w2 * h2);
		cout << ans << '\n';
	}
	return 0;
}