#include <bits/stdc++.h>

using namespace std;

int a[2005];

void solve() {
	int n, s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		s ^= a[i];
	}
	if (!s) {
		printf("YES\n");
		return;
	}
	int cnt = 0;
	int p = 0;
	for (int i = 0; i < n; ++i) {
		p ^= a[i];
		if (p == s) {
			++cnt;
			p = 0;
		}
	}
	if (cnt >= 2)
		printf("YES\n");
	else
		printf("NO\n");
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