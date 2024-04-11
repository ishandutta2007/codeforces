#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll exgcd(ll a, ll b, ll &x, ll &y) { // ax + by = gcd(a,b)
	if (b == 0) return x = 1, y = 0, a;
	ll t = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return t;
}

int main() {
	ios :: sync_with_stdio(false);
	ll a, b, c; cin >> a >> b >> c;
	c = -c;
	int sa = 1, sb = 1;
	if(a < 0) { a = -a; sa = -1; }
	if(b < 0) { b = -b; sb = -1; }
	ll g = abs(__gcd(a, b));
	if(c % g != 0) cout << -1 << '\n';
	else {
		ll x, y;
		exgcd(a, b, x, y);
		cout << x * sa * (c / g) << ' ' << y * sb * (c / g) << '\n';
	}
	return 0;
}