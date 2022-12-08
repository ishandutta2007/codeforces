#include <bits/stdc++.h>

using namespace std;

char s[2][200];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s[0]);
	scanf("%s", s[1]);
	for (int i = 0; i < n; ++i) {
		if (s[0][i] == '1' && s[1][i] == '1') {
			puts("NO");
			return;
		}
	}
	if (s[0][0] == '1' || s[1][n - 1] == '1') puts("NO");
	else puts("YES");
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