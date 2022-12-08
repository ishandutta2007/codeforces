#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

long long fst[50];

void init() {
	fst[0] = 1;
	for (int i = 1; i < 42; ++i) {
		fst[i] = fst[i - 1] * i / __gcd(fst[i - 1], (long long) i);
	}
}

void solve() {
	long long n;
	scanf("%lld", &n);
	long long ans = 0;
	for (int i = 0; i < 42; ++i) {
		ans = (ans + n / fst[i]) % mod;
	}
	printf("%lld\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}