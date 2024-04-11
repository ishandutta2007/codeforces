#include <bits/stdc++.h>

using namespace std;

int a[2][10] = {{4, 4, 3, 3, 2, 2, 1, 1, 0, 0}, {5, 4, 4, 3, 3, 2, 2, 1, 1, 0}};

void solve() {
	char s[100];
	scanf("%s", s);
	int x[2] = {0, 0};
	int ans = 10;
	for (int i = 0; i < 10; ++i) {
		if (s[i] == '1')++x[i % 2];
		if (s[i] == '?' && i % 2 == 0)++x[i % 2];
		if (x[0] + a[0][i] < x[1] || x[0] > x[1] + a[1][i]) {
			ans = min(ans, i + 1);
			break;
		}
	}
	memset(x, 0, sizeof x);
	for (int i = 0; i < 10; ++i) {
		if (s[i] == '1')++x[i % 2];
		if (s[i] == '?' && i % 2 == 1)++x[i % 2];
		if (x[0] + a[0][i] < x[1] || x[0] > x[1] + a[1][i]) {
			ans = min(ans, i + 1);
			break;
		}
	}
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