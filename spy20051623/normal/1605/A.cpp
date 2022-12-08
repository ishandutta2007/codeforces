#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", (a + c - b - b) % 3 != 0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}