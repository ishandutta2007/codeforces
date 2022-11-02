#include <bits/stdc++.h>
using namespace std;

#define N 202020

int c[N], n, m, k[N];

int cnt[N];

int L, R;

int init_bad, bad;

int s;

void add(int c, int d) {
	if (d == 1) {
		cnt[c] ++;
		if (cnt[c] == k[c]) bad --;
	}
	if (d == -1) {
		if (cnt[c] == k[c]) bad ++;
		cnt[c] --;
	}
}

bool ok(int x) {
	memset(cnt, 0, sizeof cnt);
	L = 1, R = 0;
	bad = init_bad;
	while (R < x + s) R ++, add(c[R], 1);
	if (bad == 0) return 1;
	while (R < n) {
		add(c[L], -1);
		L ++;
		R ++;
		add(c[R], 1);
		if (bad == 0) return 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]), cnt[c[i]] ++;
	init_bad = m;
	for (int i = 1; i <= m; i ++) scanf("%d", &k[i]), init_bad -= (k[i] == 0), s += k[i];

	for (int i = 1; i <= m; i ++) if (k[i] > cnt[i]) {
		puts("-1");
		return 0;
	}

	int st = -1, en = n - s, mid;
	while (st < en - 1) {
		mid = (st + en + 1) >> 1;
		if (ok(mid)) en = mid;
		else st = mid;
	}
	printf("%d\n", en);

	return 0;
}