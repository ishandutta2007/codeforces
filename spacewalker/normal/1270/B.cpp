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
		int ans = -1;
		for (int i = 1; i < n; ++i) {
			if (abs(arr[i-1] - arr[i]) >= 2) {
				ans = i;
			}
		}
		if (ans == -1) printf("NO\n");
		else printf("YES\n%d %d\n", ans, ans + 1);
	}
	return 0;
}