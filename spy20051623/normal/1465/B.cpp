#include <bits/stdc++.h>

using namespace std;

bool check(long long x) {
	long long m = x;
	while (m) {
		int n = m % 10;
		if (n && x % n)
			return false;
		m /= 10;
	}
	return true;
}

void solve() {
	long long x;
	scanf("%lld", &x);
	while (!check(x))
		++x;
	printf("%lld\n", x);
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