#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005];
map<int, int> m;

void solve() {
	m.clear();
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	memcpy(b, a, sizeof a);
	sort(b, b + n);
	for (int i = 0; i < n - 1; ++i) {
		m[a[i]] = a[i + 1];
	}
	m[a[n - 1]] = 2e9;
	int ans = n;
	for (int i = 0; i < n - 1; ++i) {
		if (m[b[i]] == b[i + 1]) --ans;
	}
	printf("%s\n", ans <= k ? "YES" : "NO");
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