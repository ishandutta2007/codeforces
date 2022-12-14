#include <bits/stdc++.h>
using namespace std;

int n, m, a[5], b[5];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 5; i ++) {
		a[i] = n / 5;
		if (i && n % 5 >= i) a[i] ++;
	}
	for (int i = 0; i < 5; i ++) {
		b[i] = m / 5;
		if (i && m % 5 >= i) b[i] ++;
	}
	long long ans = 0;
	for (int i = 0; i < 5; i ++) {
		int j = (5 - i) % 5;
		ans += 1ll * a[i] * b[j];
	}
	cout << ans << endl;
	return 0;
}