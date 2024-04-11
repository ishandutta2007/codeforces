#include <bits/stdc++.h>
using namespace std;

#define N 200020

const long long INF = 1ll << 62;

int n, m, k, a, b, c[N], x;
int vis[N];
int v[4][N], e[4], st[4], en[4];
long long sum[4][N];

long long func(int i) {
	long long rlt = sum[3][i];
	int t = m - i;
	st[1] = st[2] = 1;
	if (i < k) {
		rlt += sum[1][k-i] + sum[2][k-i];
		t -= 2 * (k - i);
		st[1] = st[2] = k - i + 1;
	}
	if (t <= 0) {
		if (t < 0) return INF;
		return rlt;
	}
	int stt = 0, enn = 1 << 30;
	while (enn - stt > 1) {
		int mid = stt + enn >> 1;
		int gas = 0;
		for (int i = 0; i <= 2; i ++) gas += (lower_bound(v[i] + st[i], v[i] + e[i] + 1, mid + 1) -  v[i] - 1) - (st[i] - 1);
		if (gas >= t) enn = mid;
		else stt = mid;
	}
	for (int i = 0; i <= 2; i ++) {
		en[i] = lower_bound(v[i] + st[i], v[i] + e[i] + 1, enn) - v[i] - 1;
		rlt += sum[i][en[i]] - sum[i][st[i]-1];
		t -= en[i] - (st[i] - 1);
	}
	if (t) rlt += 1ll * t * enn;
	return rlt;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	if (k > m) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
	scanf("%d", &a);
	for (int i = 1; i <= a; i ++) {
		scanf("%d", &x);
		vis[x] = 1;
	}
	scanf("%d", &b);
	for (int i = 1; i <= b; i ++) {
		scanf("%d", &x);
		vis[x] += 2;
	}
	for (int i = 1; i <= n; i ++) v[vis[i]][++e[vis[i]]] = c[i];
	for (int i = 0; i < 4; i ++) sort (v[i] + 1, v[i] + e[i] + 1);
	for (int i = 0; i < 4; i ++) for (int j = 1; j <= e[i]; j ++) sum[i][j] = sum[i][j-1] + v[i][j];
	long long ans = INF;
	st[0] = 1;
	for (int i = 0; i <= min(e[3], m); i ++) {
		if (min(e[2], e[1]) < k - i) continue;
		if (i + e[0] + e[1] + e[2] < m) continue;
        ans = min(ans, func(i));
	}
	if (ans == INF) puts("-1");
	else printf("%I64d\n", ans);
	return 0;
}