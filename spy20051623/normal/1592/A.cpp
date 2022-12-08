#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n, h;
	scanf("%d%d", &n, &h);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n, greater<int>());
	int ans = h / (a[0] + a[1]);
	h -= ans * (a[0] + a[1]);
	ans <<= 1;
	if (h > 0 && h <= a[0]) ++ans;
	else if (h > a[0]) ans += 2;
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