#include <bits/stdc++.h>
using namespace std;

int n, x, a[33];

int bit(int x) {
	int rlt = 0;
	for (int i = 0; i < 32; i ++) if (x & (1 << i)) rlt ++;
	return rlt;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &x);
		a[bit(x)] ++;
	}
	long long ans = 0;
	for (int i = 0; i < 32; i ++) {
		ans += 1ll * a[i] * (a[i] - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}