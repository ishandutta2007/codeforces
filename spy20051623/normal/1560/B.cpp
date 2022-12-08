#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b) swap(a, b);
	int n = b - a;
	if (a <= 0 || a > n * 2 || b <= 0 || b > n * 2 || c <= 0 || c > n * 2) {
		printf("-1\n");
		return;
	}
	if (c - n > 0) printf("%d\n", c - n);
	else printf("%d\n", c + n);
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