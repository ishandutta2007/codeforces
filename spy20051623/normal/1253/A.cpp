#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	int op = 0, k;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			if (a[i] > b[i] || op == 2) {
				printf("NO\n");
				return;
			}
			if (op == 0) {
				op = 1;
				k = b[i] - a[i];
			} else if (b[i] - a[i] != k) {
				printf("NO\n");
				return;
			}
		} else if (op == 1) {
			op = 2;
		}
	}
	printf("YES\n");
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