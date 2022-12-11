#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll VMAX = 1000000;

int main() {
	ll k; scanf("%lld", &k);
	vector<ll> ans{1, -2};
	ll targetLen = (k % 2 == 0 ? 2000 : 1999);
	ll remSum = (k % 2 == 0 ? (k + 2000) / 2 : (k + 1999) / 2);
	for (int i = 2; i < targetLen; ++i) {
		ans.push_back(min(VMAX, remSum));
		remSum -= ans.back();
	}
	printf("%lld\n", targetLen);
	for (ll x : ans) printf("%lld ", x);
	printf("\n");
	return 0;
}