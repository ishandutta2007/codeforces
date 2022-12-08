#include <bits/stdc++.h>

using namespace std;

void solve() {
	int l, r;
	scanf("%d%d", &l, &r);
	int ans = 0;
	while (r) {
		ans += r - l;
		r /= 10;
		l /= 10;
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