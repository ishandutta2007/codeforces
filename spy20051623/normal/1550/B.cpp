#include <bits/stdc++.h>

using namespace std;

char s[500];

void solve() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	scanf("%s", s);
	if (b >= 0) {
		printf("%d\n", n * (a + b));
		return;
	}
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1])++ans;
	}
	printf("%d\n", a * n + b * (ans / 2 + 1));
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