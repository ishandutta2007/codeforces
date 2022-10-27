#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
int t, n, a[N], b[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int m1 = 1e9, m2 = 1e9;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]); m1 = min(m1, a[i]);
		}
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &b[i]); m2 = min(m2, b[i]);
		}
		LL ans = 0;
		for (int i = 1; i <= n; i ++) {
			ans += max(a[i] - m1, b[i] - m2);
		}
		printf("%lld\n", ans);
	}
}