#include <bits/stdc++.h>
using namespace std;
#define N 100100

typedef long long LL;

int n, d, a[N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	sort(a, a + n);
	LL ans = 0;
	for (int i = 0; i < n; i ++) {
		int x = lower_bound(a, a + n, a[i] + d + 1) - a - 1;
		x = x - i;
		ans += 1ll * x * (x - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}