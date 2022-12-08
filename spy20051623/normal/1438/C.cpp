#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int p;
			scanf("%d", &p);
			if ((p + i + j) % 2)++p;
			printf("%d ", p);
		}
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