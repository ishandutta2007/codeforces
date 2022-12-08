#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];
int b[200005];
int c;
int d[200005];
int k[200005];
int p[200005];
int r[200005];

void solve() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; ++i) {
		p[i] = (c - k[i] - 1) / a[i] + 1;
		if (k[i] < b[i]) {
			d[i] = (b[i] - k[i] - 1) / a[i] + 1;
			k[i + 1] = 1LL * a[i] * d[i] + k[i] - b[i];
		} else {
			d[i] = 0;
			k[i + 1] = k[i] - b[i];
		}
	}
	r[n - 1] = p[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		r[i] = min(p[i], d[i] + 1 + r[i + 1]);
	}
	printf("%d\n", r[0]);
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