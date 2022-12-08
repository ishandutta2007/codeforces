#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m, i, j;
	scanf("%d%d%d%d", &n, &m, &i, &j);
	int k1 = i - 1 + j - 1 + n - i + m - j, k2 = i - 1 + n - j + n - i + j - 1;
	if (k1 < k2) {
		printf("%d %d %d %d\n", 1, m, n, 1);
	} else {
		printf("%d %d %d %d\n", 1, 1, n, m);
	}
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