#include <bits/stdc++.h>

using namespace std;

int a[1000];

void solve() {
	int n;
	scanf("%d", &n);
	int minm = 0x3f3f3f3f;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		minm = min(minm, a[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == minm)
			++cnt;
	}
	printf("%d\n", n - cnt);
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