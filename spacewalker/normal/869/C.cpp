#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353
#define MAX 5000

typedef long long ll;
using namespace std;

ll fact[MAX + 1] = {1};
ll invFact[MAX + 1] = {1};

ll modPow(ll b, ll e) {
	if (e == 0) {
		return 1;
	} else if (e % 2 == 0) {
		return modPow((b * b) % MOD, e/2) % MOD;
	} else {
		return (b * modPow(b, e-1)) % MOD;
	}
}

ll modInv(ll n) {
	return modPow(n, MOD - 2);
}

void initFacs() {
	for (int i = 0; i <= MAX; ++i) {
		fact[i] = 1;
		invFact[i] = 1;
	}
	for (int i = 1; i <= MAX; ++i) {
		fact[i] = (i * fact[i-1]) % MOD;
		invFact[i] = modInv(fact[i]);
		//if (i <= 10) cout << i << "! = " << fact[i] << endl;
	}
}

ll choose(ll a, ll b) {
	//cout << a << "C" << b << " is " << ((fact[a] * invFact[b]) % MOD * invFact[a-b]) % MOD << endl;
	return ((fact[a] * invFact[b]) % MOD * invFact[a-b]) % MOD;
}

ll injectTo(ll a, ll b) {
	if (a > b) {
		swap(a, b);
	}
	ll total = 0;
	for (ll k = 0; k <= a; ++k) {
		ll curct = (choose(a, k) * choose(b, k)) % MOD;
		curct = (curct * fact[k]) % MOD;
		total = (total + curct) % MOD;
	}
	total = (total) % MOD;
	//cout << a << " injectedTo " << b << total << endl;
	return total;
}

int main() {
	initFacs();
	ll a, b, c; cin >> a >> b >> c;
	ll ans = (injectTo(a, b) * injectTo(b, c)) % MOD;
	ans = (ans * injectTo(a, c)) % MOD;
	cout << ans;
	return 0;
}