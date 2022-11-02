#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios :: sync_with_stdio(false);
	ll n; cin >> n;
	if(n % 3 != 0) {
		cout << "0\n";
		return 0;
	}
	n /= 3; int ans = 0;
	vector <ll> divs;
	for(ll i = 1; i * i <= n; i ++)
		if(n % i == 0) divs.push_back(i);
	int m = divs.size();
	for(int i = 0; i < m; i ++) {
		if(divs[i] * divs[i] * divs[i] > n) break;
		for(int j = i; j < m; j ++) {
			if(divs[i] * divs[j] * divs[j] > n) break;
			if(n % (divs[i] * divs[j])) continue;
			ll x = divs[i], y = divs[j], z = n / divs[i] / divs[j];
			if((x + y + z) & 1) continue;
			ll s = (x + y + z) / 2, a = s - x, b = s - y, c = s - z;
			if(z >= y && a > 0 && b > 0 && c > 0) {
				if(a == b && b == c) ans ++;
				else if(a == b || b == c || c == a) ans += 3;
				else ans += 6;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}