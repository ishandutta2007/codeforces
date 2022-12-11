#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		sort(begin(arr), end(arr));
		int ans = 1000000000;
		for (int i = 0; i + 1 < n; ++i) ans = min(ans, arr[i+1] - arr[i]);
		printf("%d\n", ans);
	}
	return 0;
}