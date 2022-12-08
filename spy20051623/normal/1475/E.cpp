#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int gcd(int x, int y) {
	int t;
	while (x % y) {
		t = x % y;
		x = y;
		y = t;
	}
	return y;
}

long long c(int n, int m) {
	long long re = 1;
	int i, j, p, a[1005], g;
	if (m > n / 2)
		m = n - m;
	for (i = 0; i < m; ++i) {
		a[i] = n - i;
	}
	for (i = 1; i <= m; ++i) {
		j = 0;
		p = i;
		while (p > 1) {
			g = gcd(a[j], p);
			if (g > 1) {
				a[j] /= g;
				p /= g;
			} else ++j;
		}
	}
	for (i = 0; i < m; ++i) {
		re = re * a[i] % 1000000007;
	}
	return re;
}

main() {
	long long t, n, k, a[1005], i, j;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		cin >> n >> k;
		for (i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a + n, cmp);
		j = 0;
		for (i = 0; i < k; ++i) {
			if (a[i] < a[j])
				j = i;
		}
		i = j;
		while (i < n - 1 && a[i + 1] == a[j])
			++i;
		long long res = c(i - j + 1, k - j);
		cout << res << endl;
	}
}