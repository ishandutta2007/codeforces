#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios :: sync_with_stdio(false);
	ll n; cin >> n;
	auto solve = [](ll n) {
		ll ret = 0;
		for(ll k = 2; k <= (ll)3e5; k ++)
			ret += n / k / k / k;
		return ret;
	};
	ll l = 1, r = (ll)1e16 + 1;
	while(l + 1 < r) {
		ll m = (l + r) / 2;
		if(solve(m - 1) >= n)
			r = m;
		else
			l = m;
	}
	if(solve(l) == n)
		cout << l << '\n';
	else
		cout << "-1\n";
	return 0;
}