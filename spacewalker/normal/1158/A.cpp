#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<ll> boys(n), girls(m);
	for (int i = 0; i < n; ++i) scanf("%lld", &boys[i]);
	for (int i = 0; i < m; ++i) scanf("%lld", &girls[i]);
	sort(boys.begin(), boys.end());
	sort(girls.begin(), girls.end());	
	if (girls.front() < boys.back()) {
		printf("-1\n");
		return 0;
	}
	ll minBound = 0;
	for (ll bc : boys) minBound += bc * m;
	int maxUnsat = 0;
	for (ll gc : girls) {
		if (gc > boys.back()) {
			++maxUnsat; minBound += gc;
		}
	}
	if (maxUnsat == m) {
		minBound -= (maxUnsat-1)*boys[n-1] + boys[n-2];
	} else {
		minBound -= maxUnsat*boys[n-1];
	}
	printf("%lld\n", minBound);
	return 0;
}