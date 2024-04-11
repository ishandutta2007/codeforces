//In the name of God
// Break through! I screamed forth from my soul!

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;
const int sq = 375;

int a[N], go[N], cnt[N], n;

void build(int x) {
	int l = x * sq, r = min((x + 1) * sq, n);
	for (int i = r - 1; i >= l; i--) {
		if (i + a[i] >= r)
			go[i] = i, cnt[i] = 0;
		else
			go[i] = go[i + a[i]], cnt[i] = cnt[i + a[i]] + 1;	
	}
}

int main() {
	int m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i * sq < n; i++) {
		build(i);
	}
	while (m--) {
		int c; scanf("%d", &c);
		if (c) {
			int res = 0, cur;
			scanf("%d", &cur); --cur;
			while (cur < n) {
				res += cnt[cur] + 1;
				cur = go[cur];
				if (cur + a[cur] >= n)
					break;
				cur += a[cur];
			}
			printf("%d %d\n", cur + 1, res);
		} else {
			int v, x; scanf("%d%d", &v, &x), --v;
			a[v] = x;
			build(v / sq);
		}
	}
}