#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005], pos[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; ++i) {
		pos[a[i]] = i;
	}
	for (int i = 3; i < n + n; i += 2) {
		pos[i] = min(pos[i], pos[i - 2]);
	}
	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, i + pos[b[i] - 1]);
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