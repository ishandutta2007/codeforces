#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> a(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<int> minPrefix(n, a[0]);
	vector<int> minSuffix(n, a[n-1]);
	for (int i = 1; i < n; ++i) {
		minPrefix[i] = min(a[i], minPrefix[i-1]);
	}
	for (int i = n-2; i >= 0; --i) {
		minSuffix[i] = min(a[i], minSuffix[i+1]);
	}
	int ans = -2000000000;
	if (k == 1) {
		ans = minSuffix[0];
	} else if (k == 2) {
		for (int i = 0; i < n-1; ++i) {
			ans = max(ans, max(minPrefix[i], minSuffix[i+1]));
		}
	} else {
		ans = *max_element(a.begin(), a.end());
	}
	printf("%d\n", ans);
	return 0;
}