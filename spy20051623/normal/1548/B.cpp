#include <bits/stdc++.h>

using namespace std;

long long a[200005];
long long b[200005];
long long st[200005][50];
int n;

int get(int x) {
	int k = x;
	int p = 20;
	long long cur = b[x];
	while (x < n && p >= 0) {
		while (p >= 0 && x + (1 << p) > n)--p;
		while (p >= 0 && __gcd(cur, st[x][p]) == 1)--p;
		if (p >= 0) {
			cur = __gcd(cur, st[x][p]);
			x += 1 << p;
		}
	}
	return x - k;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld\n", &a[i]);
		if (i) {
			b[i] = abs(a[i] - a[i - 1]);
			st[i][0] = b[i];
		}
	}
	for (int i = 1; 1 << i <= n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (j + (1 << i) <= n) st[j][i] = __gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		}
	}
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans = max(ans, get(i));
	}
	printf("%d\n", ans + 1);
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