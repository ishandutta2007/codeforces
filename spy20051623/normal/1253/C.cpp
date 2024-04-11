#include <bits/stdc++.h>

using namespace std;

int a[200005];
long long sum[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		sum[i % m] += a[i];
		ans += sum[i % m];
		printf("%lld ", ans);
	}
	return 0;
}