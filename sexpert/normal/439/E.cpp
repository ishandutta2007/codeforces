#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
int prime[MAXN];
ll fac[MAXN], ifac[MAXN];

void sieve() {
	for(int p = 2; p < MAXN; p++) {
		if(prime[p])
			continue;
		for(int q = p; q < MAXN; q += p)
			prime[q] = p;
	}
}

ll inv(ll b) {
	ll e = MOD - 2, res = 1;
	for(ll k = 1; k <= e; k *= 2) {
		if(k & e) res = (res * b) % MOD;
		b = (b * b) % MOD;
	}
	return res;
}

ll binom(ll n, ll k) {
	ll d = (ifac[k] * ifac[n - k]) % MOD;
	return (fac[n] * d) % MOD;
}

ll ways(ll n, ll f) {
	if(n < f)
		return 0;
	//distrib n - f, f
	return binom(n - 1, f - 1);
}

vi prod(vi A, vi B) {
	vi C;
	for(auto a : A)
		for(auto b : B)
			C.push_back(a * b);
	return C;
}

void solve(int n, int f) {
	vector<int> divs = {1};
	int tmp = n;
	while(tmp > 1) {
		int p = prime[tmp];
		divs = prod(divs, {1, -p});
		while(tmp % p == 0)
			tmp /= p;
	}
	ll ans = 0;
	for(auto d : divs) {
		ll sgn = (d > 0 ? 1 : -1);
		d = abs(d);
		ll w = ways(n / d, f);
		//cout << d << "  " << w << endl;
		ans = (ans + sgn * w) % MOD;
	}
	cout << (ans + MOD) % MOD << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	fac[0] = 1;
	for(ll i = 1; i < MAXN; i++)
		fac[i] = (fac[i - 1] * i) % MOD;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(ll i = MAXN - 1; i > 0; i--)
		ifac[i - 1] = (i * ifac[i]) % MOD;
	int q;
	cin >> q;
	while(q--) {
		int n, f;
		cin >> n >> f;
		if(f == 1)
			cout << (n == 1 ? 1 : 0) << '\n';
		else
			solve(n, f);
	}
}