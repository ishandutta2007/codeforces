#include <bits/stdc++.h>

using namespace std;

int a[1005];

void solve() {
	int n;
	scanf("%d", &n);
	int d = -1;
	while (n--) {
		int p;
		scanf("%d", &p);
		if (p == 1) {
			++d;
			a[d] = 1;
		} else if (p != a[d] + 1) {
			while (p != a[d] + 1)
				--d;
			++a[d];
		} else {
			++a[d];
		}
		for (int i = 0; i < d; ++i) {
			printf("%d.", a[i]);
		}
		printf("%d\n", a[d]);
	}
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