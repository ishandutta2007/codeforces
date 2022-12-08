#include <bits/stdc++.h>

using namespace std;

char s[100000];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0') {
			if (i <= n / 2) printf("%d %d %d %d\n", i, n, i + 1, n);
			else printf("%d %d %d %d\n", 1, i, 1, i - 1);
			return;
		}
	}
	printf("%d %d %d %d\n", 1, n / 2 * 2, 1, n / 2);
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