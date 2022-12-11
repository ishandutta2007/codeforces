#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll getLegendre(ll n, ll x) {
	if (n < x) return 0;
	else return n/x + getLegendre(n/x, x);
}

int main() {
	ll n, b; scanf("%lld %lld", &n, &b);
	map<ll, ll> primes;
	for (ll i = 2; i <= 1000000; ++i) {
		while (b % i == 0) {
			b /= i;
			++primes[i];
		}
	}
	if (b > 1) ++primes[b];
	ll ans = 2000000000000000000;
	for (auto x : primes) {
		ans = min(ans, getLegendre(n, x.first) / x.second);
	}
	printf("%lld\n", ans);
	return 0;
}