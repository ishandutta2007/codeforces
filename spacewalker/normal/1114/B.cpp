#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	vector<int> index(n);
	for (int i = 0; i < n; ++i) index[i] = i;
	sort(index.begin(), index.end(), [&arr] (int i, int j) {
		return arr[i] < arr[j];
	});
	vector<bool> marked(n);
	ll ans = 0;
	for (int i = 0; i < m*k; ++i) {
		marked[index[n-1-i]] = true;
		ans += arr[index[n-1-i]];
	}
	vector<int> part;
	int markedInc = 0;
	for (int i = 0; i < n; ++i) {
		if (marked[i]) ++markedInc;
		if (markedInc == m) {
			part.push_back(i);
			markedInc = 0;
		}
	}
	printf("%lld\n", ans);
	for (int i = 0; i < k - 1; ++i) {
		printf("%d ", part[i] + 1);
	}
	printf("\n");
	return 0;
}