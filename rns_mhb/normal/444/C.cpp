#include <bits/stdc++.h>
using namespace std;

#define N 101010
const int K = 500;

int n, q;
int c[N];
long long d[N];

void init() {
	for (int i = 1; i <= n; i ++) c[i] = i;
}

int type[N], le[N], ri[N], x[N], e;
int y[(N+K)<<1], f;

void input_query() {
	e ++;
	scanf("%d", &type[e]);
	if (type[e] == 1) scanf("%d %d %d", &le[e], &ri[e], &x[e]);
	else scanf("%d %d", &le[e], &ri[e]);
	le[e] --;
	y[++f] = le[e], y[++f] = ri[e];
}

int had[N];
long long s[N];
long long t[N];

void solve() {
	sort(y + 1, y + f + 1);
	int ff = 0;
	for (int i = 1; i <= f; i ++) if (i == 1 || y[i] != y[i-1]) y[++ff] = y[i];
	memset(had, 0, sizeof had);
	f = ff;
	for (int i = 2; i <= f; i ++) {
		s[i] = 0;
		for (int j = y[i-1] + 1; j <= y[i]; j ++) s[i] += d[j];
	}
	for (int k = 1; k <= e; k ++) {
		int L = lower_bound(y + 1, y + f + 1, le[k]) - y;
		int R = lower_bound(y + 1, y + f + 1, ri[k]) - y;
		if (type[k] == 1) {
			for (int i = L + 1; i <= R; i ++) {
				if (had[i]) {
					s[i] += 1ll * (y[i] - y[i-1]) * abs(had[i] - x[k]);
					t[i] += abs(had[i] - x[k]);
					had[i] = x[k];
				}
				else {
					had[i] = x[k];
					for (int j = y[i-1] + 1; j <= y[i]; j ++) s[i] += abs(c[j] - x[k]), d[j] += abs(c[j] - x[k]);
					t[i] = 0;
				}
			}
		}
		else {
			long long ans = 0;
			for (int i = L + 1; i <= R; i ++) ans += s[i];
			printf("%I64d\n", ans);
		}
	}
	for (int i = 2; i <= f; i ++) if (had[i]) {
		for (int j = y[i-1] + 1; j <= y[i]; j ++) c[j] = had[i], d[j] += t[i];
	}
	e = 0;
	f = 0;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &q);
	init();
	for (int i = 1; i <= q; i ++) {
		input_query();
		if (i % K == 0 || i == q) solve();
	}

	return 0;
}