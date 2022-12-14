#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

#define N 2020

int a[N], b[N], sa[N], sb[N];
int n, m;
int A[N], B[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sa[i] = a[i] + sa[i-1];
	for (int i = 1; i <= m; i ++) scanf("%d", &b[i]), sb[i] = b[i] + sb[i-1];
	for (int i = 1; i <= n; i ++) {
		int now = INF;
		for (int le = 1, ri = i; ri <= n; le ++, ri ++) {
			now = min(now, sa[ri] - sa[le-1]);
		}
		A[i] = now;
	}
	for (int i = 1; i <= m; i ++) {
		int now = INF;
		for (int le = 1, ri = i; ri <= m; le ++, ri ++) {
			now = min(now, sb[ri] - sb[le-1]);
		}
		B[i] = now;
	}
	int x;
	scanf("%d", &x);
	int ans = 0;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) {
		if (1ll * A[i] * B[j] <= x) ans = max(ans, i * j);
	}
	printf("%d\n", ans);

	return 0;
}