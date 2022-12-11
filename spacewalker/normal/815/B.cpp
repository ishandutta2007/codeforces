#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1'000'000'007;
constexpr int NMAX = 200'010;

ll modexp(ll b, ll e) {
	return (e == 0 ? 1 : (e & 1 ? b : 1) * modexp(b*b % MOD, e/2) % MOD);
}

ll modinv(ll x) {return modexp(x, MOD - 2);}

ll fact[NMAX], invfact[NMAX];

ll choose(int n, int r) {
	return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

vector<ll> stepThrough(vector<ll> arr, bool startPlus) {
	int n = arr.size();
	vector<ll> ans(n - 1);
	for (int i = 0, cSign = (startPlus ? 1 : -1); i < n-1; ++i, cSign *= -1) {
		ans[i] = (arr[i] + cSign * arr[i+1]) % MOD;
	}
	return ans;
}

ll magicalFunnel(vector<ll> arr) {
	ll ans = 0;
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		ans = (ans + choose(n-1, i) * arr[i] % MOD) % MOD;
	}
	return ans;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < NMAX; ++i) fact[i] = (fact[i-1] * i) % MOD;
	invfact[NMAX-1] = modinv(fact[NMAX-1]);
	for (int i = NMAX - 2; i >= 0; --i) invfact[i] = (invfact[i+1] * (i+1)) % MOD;
	int n; scanf("%d", &n);	
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &arr[i]);
	}
	if (n == 1) {
		printf("%lld\n", arr[0]);
		return 0;
	}
	if (n % 2 == 1) arr = stepThrough(arr, true);

	vector<ll> even, odd;
	for (int i = 0; i < arr.size(); ++i) {
		if (i % 2 == 0) even.push_back(arr[i]);
		else odd.push_back(arr[i]);
	}
	ll evres = magicalFunnel(even), odres = magicalFunnel(odd);
	ll ans = ((ll)n*(n-1)/2 % 2 == 1 ? evres + odres : evres - odres);
	printf("%lld\n", (ans + MOD) % MOD);
	return 0;
}