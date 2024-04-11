
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	vector<long long> a(n), mb(n), ad(n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	mb[0] = a[0];
	for (int i = 1; i < n; i++) {
		mb[i] = max(mb[i - 1] + 1, a[i]);
		ad[i] = ad[i - 1] + mb[i] - a[i];
	}
	long long cm = -1, ca = 0, ans = ad[n - 1];
	for (int i = n - 1; i > 0; i--) {
		cm = max(cm + 1, a[i]);
		ca += cm - a[i];
		ans = min(ans, ad[i - 1] + ca + max(0ll, cm - mb[i - 1] + 1));
	}
	ans = min(ans, ca);
	printf("%lld\n", ans);
}