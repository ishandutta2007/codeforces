#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
	long long t;
	while (t = x % y) {
		x = y;
		y = t;
	}
	return y;
}

long long v[1000005], u[1000005];
vector<long long> r;

long long exgcd(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		long long r = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return r;
	}
}

long long china(long long a1, long long a2, long long b1, long long b2) {
	long long i, c, d, x, y;
	c = b2 - b1;
	d = exgcd(a1, a2, x, y);
	x = x * c / d;
	y = a2 / d;
	x = (x % y + y) % y;
	b1 += x * a1;
	a1 *= a2 / d;
	return b1;
}

int main() {
//	freopen("in.txt", "r", stdin);
	long long n, m, t, g, l, i, j, M, sum = 0, res;
	cin >> n >> m >> t;
	g = gcd(n, m);
	l = n * m / g;
	for (i = 1; i <= n; ++i) {
		cin >> j;
		v[j] = i;
	}
	for (i = 1; i <= m; ++i) {
		cin >> j;
		u[j] = i;
	}
	M = max(n, m);
	for (i = 1; i < 1000005; ++i) {
		if (!v[i] || !u[i])
			continue;
		if (v[i] % g != u[i] % g)
			continue;
		j = china(n, m, v[i] - 1, u[i] - 1);
		r.push_back(j + 1);
		++sum;
	}
	r.push_back(0);
	r.push_back(2e18);
	sort(r.begin(), r.end());
	res = (t - 1) / (l - sum) * l;
	t = (t - 1) % (l - sum) + 1;
	i = 1;
	while (t > r[i] - r[i - 1] - 1) {
		t -= r[i] - r[i - 1] - 1;
		res += r[i] - r[i - 1];
		++i;
	}
	res += t;
	cout << res << endl;
	return 0;
}