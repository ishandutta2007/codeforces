#include <bits/stdc++.h>
using namespace std;

long long a[200010];
vector <long long> all;

int main() {
	int n; long long k, x; scanf("%d%I64d%I64d", &n, &k, &x);
	for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
	sort(a, a + n);
	for (int i = 1; i < n; i++) all.push_back(max(0ll, (a[i] - a[i - 1] + x - 1) / x - 1));
	sort(all.begin(), all.end());
	int pos = 0; while (pos < all.size() && all[pos] <= k) k -= all[pos], pos++;
	printf("%d\n", n - pos);
	return 0;
}