#include <bits/stdc++.h>

using namespace std;

char s[1000];

void solve() {
	scanf("%s", s);
	int n = strlen(s);
	if ((s[n - 1] - '0') % 2 == 0) {
		puts("0");
		return;
	}
	int p = -1;
	for (int i = 0; i < n; ++i) {
		if ((s[i] - '0') % 2 == 0) {
			p = i;
			break;
		}
	}
	if (p == -1) {
		puts("-1");
		return;
	}
	if (p == 0) puts("1");
	else puts("2");
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