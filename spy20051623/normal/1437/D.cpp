#include <bits/stdc++.h>

using namespace std;

int a[200005];
int d[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	a[n] = 0;
	int p = 0, q = 1;
	while (q < n) {
		while (a[q] < a[q + 1]) d[q++] = d[p] + 1;
		d[q++] = d[p++] + 1;
	}
	printf("%d\n", d[n - 1]);
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