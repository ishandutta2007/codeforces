#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], ans[N];
long long sum[N][20];
//struct node {
//	int l, r;
//	long long mn;
//} tr[N << 2];
//#define T tr[n]
//#define LS tr[n<<1]
//#define RS tr[n<<1|1]
//
//void build(int n, int l, int r) {
//	T.l = l, T.r = r;
//	if (l == r) {
//		T.mn = sum[l];
//		return;
//	}
//	int m = (l + r) >> 1;
//	build(n << 1, l, m);
//	build(n << 1 | 1, m + 1, r);
//	T.mn = min(LS.mn, RS.mn);
//}

void solve() {
	int n, s;
	scanf("%d%d", &n, &s);
	for (int i = 0; i <= n; ++i) for (int j = 0; j < 20; ++j) sum[i][j] = -1e18;
	sum[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum[i][0] = sum[i - 1][0] + a[i];
	}
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j + (1 << i) <= n + 1)
				sum[j][i] = min(sum[j][i - 1], sum[j + (1 << (i - 1))][i - 1]);
		}
	}
	int maxm = 0;
	for (int i = 1; i <= n; ++i) {
		int to = i - 1;
		for (int j = 19; j >= 0; --j) {
			if (to + (1 << j) <= n)
				if (sum[to + 1][j] + s >= sum[i - 1][0]) to += 1 << j;
		}
		ans[i] = to;
		maxm = max(maxm, to - i + 1);
	}
	if (!maxm) {
		puts("-1");
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (ans[i] - i + 1 == maxm) {
			printf("%d %d\n", i, ans[i]);
			return;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}