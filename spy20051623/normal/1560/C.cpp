#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int x, y, s;
	s = floor(sqrt(n - 1));
	n -= s * s;
	if (n <= s) printf("%d %d\n", n, s + 1);
	else printf("%d %d\n", s + 1, 2 * s + 2 - n);
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