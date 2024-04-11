#include <bits/stdc++.h>
using namespace std;

#define N 101010

int n, a[N];

const int K = 600;

int type[N], x[N], y[N], e;

bool bad[N];

int d[N], to[N];

void solve() {
	memset(bad, 0, sizeof bad);
	for (int k = 1; k <= e; k ++) if (!type[k]) bad[x[k]] = 1;
	for (int i = n; i >= 1; i --) {
		if (a[i] > n) bad[i] = 1;
		if (bad[i]) to[i] = i, d[i] = 0;
		else to[i] = to[a[i]], d[i] = d[a[i]] + 1;
	}
	for (int k = 1; k <= e; k ++) {
		if (type[k]) {
			int D = 1, now = x[k];
			while (1) {
				if (bad[now]) {
					if (a[now] == n + 1) {
						printf("%d %d\n", now, D);
						break;
					}
					now = a[now], D ++;
				}
				else D += d[now], now = to[now];
			}

		}
		else a[x[k]] = y[k];
	}e = 0;
}

int main() {
	//freopen("r.in", "r", stdin);
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), a[i] = min(n + 1, a[i] + i);
	int st, en = 0;
	for (int i = 1; i <= m; i ++) {
		e ++;
		scanf("%d", &type[e]);
		if (type[e] == 1) scanf("%d", &x[e]);
		else scanf("%d %d", &x[e], &y[e]), y[e] = min(n + 1, x[e] + y[e]);
		if (i % K == 0) solve();
	}
	solve();

	return 0;
}