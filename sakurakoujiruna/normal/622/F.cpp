#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;
using ll = long long;
const int Mod = (int)1e9 + 7;

ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a % Mod;
		a = a * a % Mod;
	}
	return r;
}

ll s[N];
ll fac[N], inv[N];

int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for(int i = 2; i < N; i ++)
		inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
	for(int i = 2; i < N; i ++) {
		fac[i] = fac[i] * i % Mod;
		inv[i] = inv[i] * inv[i - 1] % Mod;
	}
	ios :: sync_with_stdio(false);
	int n, k; cin >> n >> k;
	for(int i = 1; i <= k + 1; i ++)
		s[i] = (s[i - 1] + qpow(i, k)) % Mod;

	if(n <= k + 1) {
		cout << s[n] << '\n';
		return 0;
	}

	ll mul = 1;
	for(int i = 0; i <= k + 1; i ++)
		mul = mul * (n - i) % Mod;

	ll ans = 0;
	for(int i = 1; i <= k + 1; i ++) {
		int sgn = ((k + 1 - i)) & 1 ? -1 : 1;
		ans += sgn * mul * qpow(n - i, Mod - 2) % Mod *
			inv[i] % Mod * inv[k + 1 - i] % Mod * s[i] % Mod;
		ans %= Mod;
	}
	cout << (ans + Mod) % Mod << '\n';
	return 0;
}