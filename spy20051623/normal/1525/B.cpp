#include <bits/stdc++.h>

using namespace std;

int a[100];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	bool ok = true;
	int x1, xn;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != i)
			ok = false;
		if (a[i] == 1)
			x1 = i;
		if (a[i] == n)
			xn = i;
	}
	if (ok)
		printf("0\n");
	else if (x1 == 1 || xn == n)
		printf("1\n");
	else if (x1 == n && xn == 1)
		printf("3\n");
	else
		printf("2\n");
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