#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	if (a == b) {
		printf("0 0\n");
		return;
	}
	if (a > b)swap(a, b);
	long long c = b - a;
	long long d = min(a % c, c - a % c);
	printf("%lld %lld\n", c, d);
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