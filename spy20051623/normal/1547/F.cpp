#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];
int st[200005][20];

int get(int x, int k) {
	int p = 0;
	while (1 << (p + 1) <= k)++p;
	if (1 << p == k)return st[x][p];
	else return __gcd(st[x][p], get((x + (1 << p)) % n, k - (1 << p)));
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int g = a[0];
	for (int i = 1; i < n; ++i) {
		g = __gcd(g, a[i]);
	}
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		a[i] /= g;
		if (a[i] > 1)ok = false;
	}
	if (ok) {
		printf("0\n");
		return;
	}
	for (int i = 0; i < n; ++i) {
		st[i][0] = a[i];
	}
	for (int i = 1; 1 << i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			st[j][i] = __gcd(st[j][i - 1], st[(j + (1 << (i - 1))) % n][i - 1]);
		}
	}
	int l = 1, r = n - 1;
	int ans;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (get(i, mid) != 1) {
				res = 1;
				break;
			}
		}
		if (!res)r = mid - 1;
		else ans = mid, l = mid + 1;
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