#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	if (b == 1) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	printf("%lld %lld %lld\n", a, a * b, a * (b + 1));
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