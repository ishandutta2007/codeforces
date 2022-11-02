#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll Mod = (ll)1e9 + 7;

ll qpow(ll a, ll b) {
	ll ret = 1, tmp = a;
	for(; b > 0; b >>= 1) {
		if(b & 1)
			ret = ret * tmp % Mod;
		tmp = tmp * tmp % Mod;
	}
	return ret;
}

int main() {
	ios :: sync_with_stdio(false);
	ll n; cin >> n;
	cout << (qpow(2, n) + 1) * qpow(2, n) % Mod *
		qpow(2, Mod - 2) % Mod << '\n';
	return 0;
}