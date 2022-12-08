#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (a == 1 && (n - 1) % b) {
		printf("NO\n");
		return;
	}
	for (long long i = 1; i <= n; i *= a) {
		if ((n - i) % b == 0) {
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
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