#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = n / 5; i >= 0; --i) {
		if ((n - i * 5) % 3 == 0) {
			printf("%d %d 0\n", (n - i * 5) / 3, i);
			return;
		}
		if ((n - i * 5) % 7 == 0) {
			printf("0 %d %d\n", i, (n - i * 5) / 7);
			return;
		}
	}
	puts("-1");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}