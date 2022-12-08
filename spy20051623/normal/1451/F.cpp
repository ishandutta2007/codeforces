#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m, p;
	scanf("%d%d", &n, &m);
	int x[205] = {0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &p);
			x[i + j] ^= p;
		}
	}
	for (int i = 0; i <= n + m - 2; ++i) {
		if (x[i]) {
			printf("Ashish\n");
			return;
		}
	}
	printf("Jeel\n");
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