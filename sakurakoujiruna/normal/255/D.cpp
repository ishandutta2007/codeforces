#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios :: sync_with_stdio(false);
	ll n, x, y, c;
	cin >> n >> x >> y >> c;

	auto t1 = [](ll t) {
		if(t < 0) return 0LL;
		return t * t;
	};
	auto t2 = [](ll t) {
		if(t < 0) return 0LL;
		return t * (t + 1) / 2;
	};
	auto solve = [&](ll t) {
		ll ret = 2 * t * (t + 1) + 1;
		ret -= t1(x + t - n); ret -= t1(y + t - n);
		ret -= t1(t - x + 1); ret -= t1(t - y + 1);
		ret += t2(t - x - y + 1);
		ret += t2(t - x + y - n);
		ret += t2(t + x - y - n);
		ret += t2(t + x + y - 2 * n - 1);
		return ret;
	};

	ll l = 0, r = 2 * n;
	while(l + 1 < r) {
		ll m = (l + r) / 2;
		if(solve(m - 1) >= c)
			r = m;
		else
			l = m;
	}
 	cout << l << '\n';
	return 0;
}