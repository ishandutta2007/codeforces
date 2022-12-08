#include <bits/stdc++.h>

using namespace std;

char s[1000005];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	int x = 0, y = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	int q = strlen(s), ans = 0;
	for (int i = 0; i < q; ++i) {
		switch (s[i]) {
			case 'L':
				if (y > y1) {
					++ans;
					--y;
				} else if (y2 - y1 + 1 < m) {
					++ans;
					--y;
					--y1;
				}
				break;
			case 'R':
				if (y < y2) {
					++ans;
					++y;
				} else if (y2 - y1 + 1 < m) {
					++ans;
					++y;
					++y2;
				}
				break;
			case 'U':
				if (x > x1) {
					++ans;
					--x;
				} else if (x2 - x1 + 1 < n) {
					++ans;
					--x;
					--x1;
				}
				break;
			case 'D':
				if (x < x2) {
					++ans;
					++x;
				} else if (x2 - x1 + 1 < n) {
					++ans;
					++x;
					++x2;
				}
				break;
		}
	}
	printf("%d %d\n", 1 - x1, 1 - y1);
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