#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios :: sync_with_stdio(0);
	ll n; cin >> n;
	if(n == 0)
		cout << "1\n";
	else if(n == 1)
		cout << "4\n";
	else {
		ll ans = 0;
		ll x = 0, y = n;
		while(x < y) {
			ans ++;
			x ++;
			if(x * x + y * y > n * n)
				y --;
		}
		ans *= 8;
		if(x != y) ans -= 4;
		cout << ans << '\n';
	}
}