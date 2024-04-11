#include <bits/stdc++.h>

using namespace std;

char s[1000];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	bool c = false;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'U') putchar('D');
		else if (s[i] == 'D') putchar('U');
		else if (c) c = false, putchar('R');
		else c = true, putchar('L');
	}
	putchar('\n');
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