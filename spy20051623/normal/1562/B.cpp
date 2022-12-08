#include <bits/stdc++.h>

using namespace std;

char s[1000];

int c[20];

void solve() {
	memset(c, 0, sizeof c);
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
			printf("1\n%d\n", s[i] - '0');
			return;
		}
		if (s[i] == '2') {
			if (c[2]) ans = 22;
			if (c[3]) ans = 32;
			if (c[5]) ans = 52;
			if (c[7]) ans = 72;
		}
		if (s[i] == '3') {
			if (c[3]) ans = 33;
		}
		if (s[i] == '5') {
			if (c[2]) ans = 25;
			if (c[3]) ans = 35;
			if (c[5]) ans = 55;
			if (c[7]) ans = 75;
		}
		if (s[i] == '7') {
			if (c[2]) ans = 27;
			if (c[5]) ans = 57;
			if (c[7]) ans = 77;
		}
		++c[s[i] - '0'];
	}
	printf("2\n%d\n", ans);
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