#include <bits/stdc++.h>

using namespace std;

int a[105], b[105];

void solve() {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	int n, m;
	scanf("%d%d", &n, &m);
	int p;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p);
		a[p] = 1;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &p);
		b[p] = 1;
	}
	int ans = 0;
	for (int i = 1; i < 101; ++i) {
		if (a[i] && b[i])
			++ans;
	}
	printf("%d\n", ans);
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