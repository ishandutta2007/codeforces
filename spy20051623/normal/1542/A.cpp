#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a[2] = {0, 0};
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n + n; ++i) {
		int p;
		scanf("%d", &p);
		++a[p % 2];
	}
	printf("%s\n", a[0] == a[1] ? "YES" : "NO");
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