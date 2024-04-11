#include <bits/stdc++.h>

using namespace std;

int x[300005];

void solve() {
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = a;
	int y = x[a - 1];
	if (y == b) {
		printf("%d\n", ans);
		return;
	}
	y ^= b;
	if (y == a) ans += 2;
	else ++ans;
	printf("%d\n", ans);
}

void init() {
	for (int i = 1; i < 300005; ++i) {
		x[i] = x[i - 1] ^ i;
	}
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