#include <bits/stdc++.h>

using namespace std;

int a[1005][5];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			int x = 0, y = 0, z = 0, ok = 1;
			for (int k = 0; k < n; ++k) {
				if (a[k][i] && a[k][j]) ++z;
				else if (a[k][i]) ++x;
				else if (a[k][j]) ++y;
				else {
					ok = 0;
					break;
				}
			}
			if (ok && x <= n / 2 && y <= n / 2) {
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
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