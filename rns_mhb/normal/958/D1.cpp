#include <bits/stdc++.h>
using namespace std;

#define N 202020

int x[N], y[N], n;

int id[N], ans[N];

bool cmp(int i, int j) {
	return x[i] * y[j] < x[j] * y[i];
}

bool same(int i, int j) {
	return x[i] * y[j] == x[j] * y[i];
}

int main() {
	scanf("%d\n", &n);
	for (int i = 1, tmp; i <= n; i ++) {
		id[i] = i;
		scanf("(%d+%d)/%d\n", &x[i], &tmp, &y[i]);
		x[i] += tmp;
	}
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; ) {
		int j = i + 1;
		while (j <= n && same(id[i], id[j])) j ++;
		for (int k = i; k < j; k ++) ans[id[k]] = j - i;
		i = j;
	}
	for (int i = 1; i <= n; i ++) printf("%d%c", ans[i], i == n ? '\n' : ' ');

	return 0;
}