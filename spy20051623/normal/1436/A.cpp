#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		ans += p;
	}
	printf("%s\n", ans == m ? "YES" : "NO");
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