#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;

int main() {
	int n; scanf("%d", &n);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	map<ll, int> latestOcc;
	for (int i = 0; i < n; ++i) latestOcc[arr[i]] = i;
	vector<int> reachFar(n);
	for (int i = 0; i < n; ++i) reachFar[i] = latestOcc[arr[i]];
	int forceSame = -1;
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		if (forceSame < i && i > 0) ans = (ans * 2) % MOD;
		forceSame = max(forceSame, reachFar[i]);
	}
	printf("%lld\n", ans);
	return 0;
}