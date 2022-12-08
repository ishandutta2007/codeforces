#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", a ^ b);
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