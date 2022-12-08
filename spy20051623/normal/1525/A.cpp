#include <bits/stdc++.h>

using namespace std;

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

void solve() {
	int n;
	scanf("%d", &n);
	if (n == 0 || n == 100) {
		printf("1\n");
		return;
	}
	int m = 100 - n;
	int g = gcd(n, m);
	n /= g;
	m /= g;
	printf("%d\n", n + m);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}