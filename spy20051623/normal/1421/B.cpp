#include <bits/stdc++.h>

using namespace std;

char s[300][300];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
	}
	if (s[0][1] == s[1][0]) {
		int cnt = 0;
		if (s[n - 1][n - 2] == s[0][1]) ++cnt;
		if (s[n - 2][n - 1] == s[0][1]) ++cnt;
		printf("%d\n", cnt);
		if (s[n - 1][n - 2] == s[0][1]) printf("%d %d\n", n, n - 1);
		if (s[n - 2][n - 1] == s[0][1]) printf("%d %d\n", n - 1, n);
	} else if (s[n - 1][n - 2] == s[n - 2][n - 1]) {
		int cnt = 0;
		if (s[0][1] == s[n - 1][n - 2]) ++cnt;
		if (s[1][0] == s[n - 1][n - 2]) ++cnt;
		printf("%d\n", cnt);
		if (s[0][1] == s[n - 1][n - 2]) printf("1 2\n");
		if (s[1][0] == s[n - 1][n - 2]) printf("2 1\n");
	} else {
		printf("2\n");
		printf("2 1\n");
		if (s[n - 1][n - 2] == s[0][1]) printf("%d %d\n", n, n - 1);
		if (s[n - 2][n - 1] == s[0][1]) printf("%d %d\n", n - 1, n);
	}
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