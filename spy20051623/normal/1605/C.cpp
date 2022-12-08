#include <bits/stdc++.h>

using namespace std;

char s[1000005];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == 'a' && s[i + 1] == 'a') {
			puts("2");
			return;
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		if (s[i] == 'a' && s[i + 2] == 'a') {
			puts("3");
			return;
		}
	}
	for (int i = 0; i < n - 3; ++i) {
		if (s[i] == 'a' && s[i + 3] == 'a' &&
			(s[i + 1] == 'b' && s[i + 2] == 'c' || s[i + 1] == 'c' && s[i + 2] == 'b')) {
			puts("4");
			return;
		}
	}
	for (int i = 0; i < n - 6; ++i) {
		if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 6] == 'a' && s[i + 1] == s[i + 2] && s[i + 4] == s[i + 5] &&
			(s[i + 1] == 'b' && s[i + 4] == 'c' || s[i + 1] == 'c' && s[i + 4] == 'b')) {
			puts("7");
			return;
		}
	}
	puts("-1");
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