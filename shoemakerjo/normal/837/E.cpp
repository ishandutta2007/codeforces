#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<ll> facts;

ll gcd(ll x, ll y) {
	
	if (x == 0) return y;
	if (y == 0) return x;
	if (x > y) {
		return gcd(x%y, y);
	}
	return gcd(x, y%x);
}

int main() {
	ll x, y;
	cin >> x >> y;
	ll g = gcd(x, y);
	ll rem = x/g;
	for (ll i = 2; i <= sqrt(rem); i++) {
		while (rem%i == 0) {
			facts.push_back(i);
			rem = rem/i;
		}
	}
	if (rem > 1) facts.push_back(rem);
	int taken = 0;
	bool in[facts.size()];
	for (int i = 0; i < facts.size(); i++) {
		in[i] = false;
	}
	ll ans = 0;
	while (taken < facts.size()) {
		ll small = y;
		int re = -1;
		ll div = y/g;
		for (int i = 0; i < facts.size(); i++) {
			if (in[i]) continue;
			ll num = div % facts[i];
			if (num < small) {
				small = num;
				re = i;
			}
		}
		if (re == -1) 
			break;
		ans += small;
		in[re] = true;
		taken++;
		y = y-small*g;
		g = g*facts[re];
		
	}
	if (y> 0) ans+= y/g;
	cout << ans << endl;
	cin >> x;
}