#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d %d %d\n", a > max(b, c) ? 0 : max(b, c) + 1 - a,
		   b > max(a, c) ? 0 : max(a, c) + 1 - b,
		   c > max(a, b) ? 0 : max(a, b) + 1 - c);
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