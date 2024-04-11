#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int n; ll m; scanf("%d %lld", &n, &m);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	ll comdif = 0;
	for (int i = 0; i < n; ++i) comdif = gcd(comdif, arr[i] - 1);
	while (comdif % 2 == 0) comdif /= 2;
//	printf("even %lld\n", comdif);
	set<ll> cdDiv;
	for (int test = 1; test < 100000; ++test) {
		if (comdif % test == 0) {
			cdDiv.insert(test);
			cdDiv.insert(comdif / test);
		}
	}
	ll ans = 0;
	for (int x : cdDiv) {
		for (ll evenPart = 1; 1 + x * evenPart <= m; evenPart *= 2) {
			ans += m - x * evenPart;
		}
	}
	printf("%lld\n", ans);
	return 0;
}