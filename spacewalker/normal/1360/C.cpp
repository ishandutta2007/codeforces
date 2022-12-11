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
		bool stepOneExists = false;
		vector<int> cts(2);
		for (int i = 0; i < n; ++i) {
			++cts[arr[i] % 2];
			if (i + 1 < n && arr[i+1] - arr[i] == 1) stepOneExists = true;
		}
		if (stepOneExists || (cts[0] % 2 == 0 && cts[1] % 2 == 0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}