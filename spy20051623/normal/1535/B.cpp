#include <bits/stdc++.h>

using namespace std;

int a[2005];

int gcd(int x, int y) {
	int t;
	while (t = x % y) {
		x = y;
		y = t;
	}
	return y;
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (gcd(a[i], a[j] * 2) > 1 || gcd(a[j], a[i] * 2) > 1)
				++cnt;
		}
	}
	printf("%d\n", cnt);
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