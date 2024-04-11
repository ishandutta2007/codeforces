#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, a[N], k, q;
long long s[N];

long long calc(int k) {
	long long rlt = 0, x = 1, y = k;
	while (1) {
		rlt += s[n-x];
		x += y,	y *= k;
		if (x >= n) break;
	}
	return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) s[i] = s[i-1] + a[i];
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += 1ll * (n - i) * a[i];
	}
	scanf("%d", &q);
	while (q --) {
		scanf("%d", &k);
		if (k == 1) {
			cout << ans << ' '; continue;
		}
		cout << calc(k) << ' ';
	}
	cout << endl;
	return 0;
}