#include <bits/stdc++.h>
using namespace std;
#define M 3000010
int l[M], r[M], a[M], cnt, K, n, x, y, val[M], st[M], en[M], m;
int main() {
//	freopen("D.in", "r", stdin);
	scanf("%d %d", &n, &K);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", l + i, r + i), l[i] *= 2, r[i] *= 2, a[cnt++] = l[i], a[cnt++] = r[i], a[cnt++] = r[i] + 1;
	}
	sort(a, a + cnt); cnt = unique(a, a + cnt) - a;
	for (int i = 0; i < n; i++) {
		x = lower_bound(a, a + cnt, l[i]) - a; val[x]++;
		x = lower_bound(a, a + cnt, r[i]) - a; val[x+1]--;
	}
	int last = -1;
	for (int i = 1; i <= cnt; i++) val[i] += val[i-1];
	for (int i = 0; i <= cnt; i++) {
		if (val[i] < K) {
			if (last >= 0) st[m] = last, en[m++] = i - 1;
			last = -1;
		}
		else {
			if (last < 0) last = i;
		}
	}
	printf("%d\n", m);
	for (int i = 0; i < m; i++) printf("%d %d\n", a[st[i]]/2, a[en[i]]/2);
}