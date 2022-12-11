#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n; scanf("%d", &n);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	arr.push_back(0LL);
	arr.push_back(0LL);
	ll ans = 0;
	for (int i = 0; i < n + 2; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < j; ++k) {
//				printf("triple %lld %lld %lld\n", arr[i], arr[j], arr[k]);
				ans = max(ans, arr[i] | arr[j] | arr[k]);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}