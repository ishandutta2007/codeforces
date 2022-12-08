#include <bits/stdc++.h>

using namespace std;

int a[500];

void solve() {
	memset(a, 0, sizeof a);
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		a[p] = 1;
	}
	for (int i = 1; i <= 500; ++i) {
		if (!a[i]) {
			if (c)
				--c;
			else {
				printf("%d\n", i - 1);
				return;
			}
		}
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