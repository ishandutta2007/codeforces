#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll fac[MAXN], eval[MAXN], prod[MAXN];

ll mpow(ll b, ll e) {
	ll res = 1;
	for(ll k = 1; k <= e; k *= 2) {
		if(k & e) res = (res * b) % MOD;
		b = (b * b) % MOD;
	}
	return res;
}

ll inv(ll b) {
	return mpow(b, MOD - 2);
}

int main() {
	fac[0] = 1;
	for(ll i = 1; i < MAXN; i++)
		fac[i] = (i * fac[i - 1]) % MOD;
	int n, k;
	cin >> n >> k;
	for(ll m = 1; m <= k + 1; m++)
		eval[m] = (eval[m - 1] + mpow(m, k)) % MOD;
	//for(ll m = 0; m <= k + 1; m++)
	//	cout << eval[m] << " ";
	//cout << endl;
	if(n <= k + 1) {
		cout << eval[n] << '\n';
		return 0;
	}
	ll P = 1, ans = 0;
	for(ll r = 0; r <= k + 1; r++) {
		P = (P * (n - r)) % MOD;
		ll x = (fac[k + 1 - r] * fac[r]) % MOD;
		x = inv(x);
		if((k + 1 - r) % 2)
			prod[r] = -x;
		else
			prod[r] = x;
	}
	//for(ll r = 0; r <= k + 1; r++)
	//	cout << prod[r] << endl;
	for(ll r = 0; r <= k + 1; r++) {
		ll t = (eval[r] * prod[r]) % MOD;
		t = (t * P) % MOD;
		t = (t * inv(n - r)) % MOD;
		ans = (ans + t) % MOD;
	}
	cout << (ans + MOD) % MOD << endl;
}