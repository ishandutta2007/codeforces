#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 100100

struct fenwik_tree {
	int mx[N], mx_id[N], ID;
	void add(int x, int val, int id) {
		while (x < N) {
			if (mx[x] < val) mx[x] = val, mx_id[x] = id;
			x += x & -x;
		}
	}
	int calc(int x) {
		ID = 0;
		int rlt = 0;
		while (x) {
			if (rlt < mx[x]) rlt = mx[x], ID = mx_id[x];
			x -= x & -x;
		}
		return rlt;
	}
} P, S;

int n, d, a[N], prv[N], nxt[N], f[N], bf[N];
LL h[N], x[N];
map <LL, int> mp;

void print(int x) {
	if (!x) return;
	print(bf[x]);
	printf("%d ", x);
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &d);
	for (int i = 1; i <= n; i ++) scanf("%I64d", &h[i]), x[i-1] = h[i];
	sort(x, x + n);
	int m = unique(x, x + n) - x;
	for (int i = 0; i < m; i ++) mp[x[i]] = i + 1;
	for (int i = 1; i <= n; i ++) {
		a[i] = mp[h[i]];
		prv[i] = lower_bound(x, x + m, h[i] - d + 1) - x;
		nxt[i] = lower_bound(x, x + m, h[i] + d) - x + 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		f[i] = P.calc(prv[i]) + 1, bf[i] = P.ID;
		int rlt = S.calc(N - nxt[i]) + 1;
		if (f[i] < rlt) f[i] = rlt, bf[i] = S.ID;
		P.add(a[i], f[i], i);
		S.add(N - a[i], f[i], i);
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i ++) {
		if (f[i] == ans) {
			print(i); puts(""); return 0;
		}
	}
	return 0;
}