#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = (int)1e5 + 11;
const ll Mod = (ll)1e9 + 7;
#define fi first
#define se second
ll a[N];

ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b > 0; b /= 2) {
		if(b & 1)
			r = r * a % Mod;
		a = a * a % Mod;
	}
	return r;
}

int main() {
	ios :: sync_with_stdio(false);
	int n; ll x; cin >> n >> x;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	sort(a, a + n);
	ll sum = accumulate(a, a + n, 0LL);
	map <int, int> mp;
	for(int i = 0; i < n; i ++)
		mp[a[n - 1] - a[i]] ++;

	while((mp.begin() -> se) % x == 0) {
		auto p = *mp.begin();
		mp.erase(p.fi);
		mp[p.fi + 1] += p.se / x;
	}
	sum = min(sum - a[n - 1] + (mp.begin() -> fi), sum);
	cout << qpow(x, sum) << '\n';
	return 0;
}