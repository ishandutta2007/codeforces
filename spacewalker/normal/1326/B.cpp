#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n; scanf("%d", &n);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	vector<ll> prefixMax(n), orig(n);
	for (int i = 0; i < n; ++i) {
		// we know that arr[i] = orig[i] - prefixMax[i]
		// prefixMax[i] is max(arr[0:i])
		orig[i] = arr[i] + prefixMax[i];
		if (i + 1 < n) prefixMax[i + 1] = max(prefixMax[i], orig[i]);
	}
	for (int i = 0; i < n; ++i) {
		printf("%lld ", orig[i]);
	}
	printf("\n");
	return 0;
}