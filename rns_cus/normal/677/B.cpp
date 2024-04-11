#include <bits/stdc++.h>
using namespace std;
#define N 1001001

int n, h, k, m, r, a[N];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d %d", &n, &h, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		m = a[i] + r;
		ans += m / k;
		r = m % k;
		if (r + a[i+1] > h) ans ++, r = 0;
	}
	if (r) ans ++;
	cout << ans << endl;
	return 0;
}