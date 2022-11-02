#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Ans {
	ll s, a, b;
	bool operator <(Ans ans) const {
		return tie(s, a, b) < tie(ans.s, ans.a, ans.b);
	}
};

int main() {
	ios :: sync_with_stdio(false);
	ll n, a, b; cin >> n >> a >> b;
	Ans ans = {(ll)1e18 + 1, -1, -1};
	bool sw = false;
	if(a > b) { swap(a, b); sw = true; }
	for(ll x = a; x <= (ll)1e5; x ++) {
		ll y = max({6 * n / x + (6 * n % x != 0), x, b});
		ans = min(ans, {x * y, x, y});
	}
	if(6 * n <= a * b)
		ans = min(ans, {a * b, a, b});
	cout << ans.s << '\n';
	if(!sw)
		cout << ans.a << ' ' << ans.b << '\n';
	else
		cout << ans.b << ' ' << ans.a << '\n';
	return 0;
}