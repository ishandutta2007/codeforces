#include <bits/stdc++.h>

using namespace std;

long long mpow(int p) {
	long long r = 1;
	while (p--) {
		r *= 10;
	}
	return r;
}

void solve() {
	long long n;
	scanf("%lld", &n);
	int k = 0;
	for (int i = 15; i >= 0; --i) {
		k += n / (2050 * mpow(i));
		n %= 2050 * mpow(i);
	}
	if (n)
		printf("-1\n");
	else
		printf("%d\n", k);
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