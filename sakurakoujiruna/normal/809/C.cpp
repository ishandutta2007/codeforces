#include <bits/stdc++.h>
using namespace std;

using db = double;
using ll = long long;
using vi = vector <int>;
#define op operator
#define pb push_back

const ll mod = 1e9L + 7;

ll f(ll x, ll y, ll k, ll offset) {
	//cout << x << ' ' << y << ' ' << k << ' ' << offset << '\n';
	if(x > y) swap(x, y);
	offset &= ~(y - 1);
	k -= offset;
	if(k >= y) k = y;
	if(k <= 0) return 0;
	//cout << x << ' ' << y << ' ' << k << ' ' << offset << ' ' << (k * (1 + k) / 2 % mod * x % mod + x * y % mod * offset % mod) << '\n';
	return (k * (1 + k) / 2 % mod * x % mod + k * x % mod * offset % mod) % mod; 
}

ll get(ll n, ll m) {
	return n ^ m;
	if(n > m) swap(n, m);
	if(n == m) return 0;
	//if(n * 2 == m) return n;
	return n + m;
}

ll solve(ll x, ll y, ll k, ll offset = 0) {
	//cout << x << ' ' << y << '\n';
	//if(x && y) cout << x << ' ' << y << ' ' << k << ' ' << offset << '\n';
	if(x > y) swap(x, y);
	if(x == 0) return 0;
	ll n = 1, m = 1;
	while(n * 2 <= x) n *= 2;
	while(m * 2 <= y) m *= 2;
	//cout << n << ' ' << m << '\n';

	ll r = f(n, m, k, offset);

	if(n == m) {
		r += solve(x - n, m, k, offset ^ n);
		r += solve(n, y - m, k, offset ^ m);
		r += solve(x - n, y - m, k, offset);
	} else {

		r += solve(x - n, m, k, offset);
		r += solve(n, y - m, k, offset ^ m);
		r += solve(x - n, y - m, k, offset ^ get(n, m));
	}
	return r % mod;
}

int main() {

	//cout << solve(2, 5, 2) << '\n';

	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(0);
	/*
	for(int i : {1, 2, 4})
		for(int j : {1, 2, 4}) cout << get(i, j) << '\n';
*/
		
	int q; cin >> q;
	while(q --) {
		ll x1, x2, y1, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		//cout << "------\n";
		//cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << ' ' << k << '\n';

		//cout << solve(x2, y2, k) << ' ' << solve(x1 - 1, y2, k) << ' ' << solve(x2, y1 - 1, k) << ' ' << solve(x1 - 1, y1 - 1, k) << '\n';

		ll ans = solve(x2, y2, k) - solve(x1 - 1, y2, k) - solve(x2, y1 - 1, k) + solve(x1 - 1, y1 - 1, k);
		ans = (ans % mod + mod) % mod;
		cout << ans << '\n';
	}
	

	return 0;
}