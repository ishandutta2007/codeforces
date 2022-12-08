#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];

long long gcd(long long x, long long y) {
	long long t;
	while (t = x % y) {
		x = y;
		y = t;
	}
	return y;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m, i;
	cin >> n >> m;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for (i = 0; i < m; ++i)
		cin >> b[i];
	for (i = n - 1; i >= 1; --i)
		a[i] -= a[i - 1];
	for (i = n - 1; i >= 2; --i)
		a[i - 1] = gcd(a[i], a[i - 1]);
	for (i = 0; i < m; ++i)
		if (n > 1)
			cout << gcd(a[1], a[0] + b[i]) << ' ';
		else
			cout << a[0] + b[i] << ' ';
	return 0;
}