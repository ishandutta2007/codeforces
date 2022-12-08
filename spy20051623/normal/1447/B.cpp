#include <bits/stdc++.h>

using namespace std;

int a[15][15];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0, cnt = 0;
	priority_queue<int> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			if (a[i][j] < 0) ++cnt;
			q.push(abs(a[i][j]));
		}
	}
	cnt &= 1;
	while (q.size() > cnt) {
		ans += q.top();
		q.pop();
	}
	if (!q.empty()) ans -= q.top();
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