#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n;
	scanf("%lld", &n);
	n = (n + 1) / 2;
	if (n <= 3)printf("15\n");
	else printf("%lld\n", n * 5);
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