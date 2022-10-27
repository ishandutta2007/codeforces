#include <bits/stdc++.h>
using namespace std;
const int N = 52;
int t, n, a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int ans = 1000;
		for (int i = 1; i < n; i ++) {
			ans = min(ans, a[i+1] - a[i]);
		}
		printf("%d\n", ans);
	}
}