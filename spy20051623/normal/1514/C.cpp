#include <bits/stdc++.h>

using namespace std;

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

int gcd(int x, int y) {
	int t;
	while (t = x % y) {
		x = y;
		y = t;
	}
	return y;
}

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
	int n;
	scanf("%d", &n);
	long long int res = 1;
	int cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (gcd(i, n) == 1) {
			res = res * i % n;
			++cnt;
		}
	}
	if (res == 1) {
		printf("%d\n", cnt);
		for (int i = 1; i < n; ++i) {
			if (gcd(i, n) == 1) {
				printf("%d ", i);
			}
		}
		return 0;
	}
	int mk = 0;
	for (int i = 1; i < n; ++i) {
		if (gcd(i, n) == 1) {
			long long x, y;
			exgcd(i, n, x, y);
			x = (x + n) % n;
			if (res * x % n == 1) {
				mk = i;
				break;
			}
		}
	}
	printf("%d\n", cnt - 1);
	for (int i = 1; i < n; ++i) {
		if (gcd(i, n) == 1 && i != mk)
			printf("%d ", i);
	}
	return 0;
}