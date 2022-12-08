#include <bits/stdc++.h>

using namespace std;

int a[100005];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int res = 0x3f3f3f3f;
	for (int i = 1; i <= 100; ++i) {
		int c = 0;
		int p = 0;
		while (p < n) {
			if (a[p] == i)
				++p;
			else {
				++c;
				p += k;
			}
		}
		res = min(res, c);
	}
	printf("%d\n", res);
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