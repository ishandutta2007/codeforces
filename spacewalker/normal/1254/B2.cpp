#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll BRUTE_MAX = 1000000;
constexpr ll INF = 4000000000000000000;

ll computeAns(vector<ll> &arr, ll p) {
//	printf("computing ans on %lld\n", p);
	vector<ll> psum(arr);
	int n = arr.size();
	for (int i = 1; i < n; ++i) {
		psum[i] += psum[i-1];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		// do we need to adjust this element?
		if (psum[i] % p == 0) continue;
		// if we do, check if we should adjust below or above?
		ll belowCost = psum[i] % p;
		ans += min(belowCost, p - belowCost);
	}
	return ans;
}

int main() {
	int n; scanf("%d", &n);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	ll elemsum = 0;
	for (int i = 0; i < n; ++i) elemsum += arr[i];
	if (elemsum == 1) {
		printf("-1\n");
		return 0;
	}
	vector<ll> esdiv;
	for (int i = 2; i <= BRUTE_MAX; ++i) {
		if (elemsum % i == 0) {
			esdiv.push_back(i);
			if (elemsum / i != i && elemsum / i > BRUTE_MAX) esdiv.push_back(elemsum / i);
		}
	}
	if (elemsum > BRUTE_MAX) esdiv.push_back(elemsum);
	// look at only the prime factors
	vector<ll> primesdiv;
	for (ll x : esdiv) {
		bool undiv = true;
		for (ll y : esdiv) {
			if (y < x && x % y == 0) undiv = false;
		}
		if (undiv) primesdiv.push_back(x);
	}
	// check each prime factor
	ll ans = INF;
	for (ll p : primesdiv) {
		ans = min(ans, computeAns(arr, p));	
	}
	printf("%lld\n", ans);
	return 0;
}