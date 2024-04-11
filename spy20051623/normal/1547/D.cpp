#include <bits/stdc++.h>

using namespace std;

int a[200005];
int b[200005];
int c[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	b[0] = 0;
	c[0] = a[0];
	for (int i = 1; i < n; ++i) {
		c[i] = a[i] | c[i - 1];
		b[i] = a[i] ^ c[i];
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", b[i]);
	}
	printf("\n");
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