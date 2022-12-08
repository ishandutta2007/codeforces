#include <bits/stdc++.h>

using namespace std;

char s[300005];

int pre[300005], suf[300005];

void solve() {
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '+') pre[i] = pre[i - 1] + (i & 1 ? 1 : -1);
		else pre[i] = pre[i - 1] - (i & 1 ? 1 : -1);
	}
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (pre[r] - pre[l - 1] == 0) {
			printf("0\n");
			continue;
		}
		if ((pre[r] - pre[l - 1]) & 1) {
			printf("1\n");
//			int ll = l, rr = r;
//			while (ll <= rr) {
//				int mid = (ll + rr) >> 1;
//				if (pre[])
//			}
		} else {
			printf("2\n");
		}
	}
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