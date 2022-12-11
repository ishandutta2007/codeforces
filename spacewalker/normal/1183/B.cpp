#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		int mineq = -1000000000, maxeq = 1000000000;
		for (int i = 0; i < n; ++i) {
			mineq = max(mineq, arr[i] - k);
			maxeq = min(maxeq, arr[i] + k);
		}
		if (mineq > maxeq) {
			printf("-1\n");
		} else {
			printf("%d\n", maxeq);
		}
	}
	return 0;
}