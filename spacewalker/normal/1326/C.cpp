#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	vector<int> watchPos;
	for (int i = 0; i < n; ++i) {
		if (arr[i] >= (n - (k - 1))) watchPos.push_back(i);
	}
	ll maxval = 0, partCount = 1;
	for (int i = 0; i < k; ++i) maxval += n - i;
	for (int i = 0; i + 1 < watchPos.size(); ++i) {
		partCount = (partCount * (watchPos[i + 1] - watchPos[i])) % MOD;
	}
	printf("%lld %lld\n", maxval, partCount);
	return 0;
}