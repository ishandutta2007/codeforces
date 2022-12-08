#include <bits/stdc++.h>

using namespace std;

char s[80][40];
char k[40];

void solve() {
	scanf("%s", k);
	int ans = 1000;
	for (int i = 0; i < 63; ++i) {
		int cur = 0, p1 = 0, p2 = 0;
		while (s[i][p1] != '\0' && k[p2] != '\0') {
			if (s[i][p1] == k[p2]) ++p1, ++p2;
			else ++cur, ++p2;
		}
		while (s[i][p1] != '\0') ++cur, ++p1;
		while (k[p2] != '\0') ++cur, ++p2;
		ans = min(ans, cur);
	}
	printf("%d\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	for (int i = 0; i < 63; ++i) {
		sprintf(s[i], "%lld", 1ll << i);
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}