#include <bits/stdc++.h>

using namespace std;

int a[505];

void solve() {
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	bool ok = true;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] > a[i + 1]) {
			ok = false;
			break;
		}
	}
	if (ok) {
		printf("0\n");
		return;
	}
	int p = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] > x) {
			p = i;
			break;
		}
	}
	if (p == -1) {
		printf("-1\n");
		return;
	}
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] > a[i + 1]) {
			while (p <= i) {
				if (x < a[p]) {
					swap(x, a[p]);
					++ans;
				}
				++p;
			}
			if (a[i] > a[i + 1]) {
				if (x < a[i + 1]) {
					swap(x, a[i + 1]);
					++ans;
					++p;
				} else {
					printf("-1\n");
					return;
				}
			}
		}
	}
	printf("%d\n", ans);
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