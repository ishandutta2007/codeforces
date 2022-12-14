#include <bits/stdc++.h>
using namespace std;

#define N 400020

int n, m, a[N], b[N], p, ans[N], cnt, c[N*2], d[N*2], e, aa[N], bb[N], vis[N*2], ini[N*2];

int main() {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), c[i] = a[i];
	for (int j = 1; j <= m; j ++) scanf("%d", &b[j]), c[j+n] = b[j];
	sort (c + 1, c + n + m + 1);
    d[1] = c[1];
    e = 1;
    for (int i = 2; i <= n + m; i ++) if (c[i] > c[i-1]) d[++e] = c[i];
    for (int i = 1; i <= n; i ++) aa[i] = lower_bound (d, d + e + 1, a[i]) - d;
    for (int j = 1; j <= m; j ++) bb[j] = lower_bound (d, d + e + 1, b[j]) - d;
    for (int j = 1; j <= m; j ++) ini[bb[j]] ++;
    for (int r = 1; r <= p; r ++) {
		if (r + 1ll * p * (m - 1) > n) continue;
		int now = 0;
		for (int i = 1; i <= e; i ++) vis[i] = ini[i], now += vis[i];
        for (int i = r; i <= r + p * (m - 1); i += p) {
            now -= abs(vis[aa[i]]);
			vis[aa[i]] --;
            now += abs(vis[aa[i]]);
        }
        if (!now) ans[++cnt] = r;
        for (int i = r + p * m; i <= n; i += p) {
			now -= abs(vis[aa[i]]);
			now -= abs(vis[aa[i-p*m]]);
			vis[aa[i]] --;
			vis[aa[i-p*m]] ++;
            now += abs(vis[aa[i]]);
            now += abs(vis[aa[i-p*m]]);
            if (!now) ans[++cnt] = i - p * (m - 1);
        }
    }
    sort (ans + 1, ans + cnt + 1);
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i ++) printf("%d ", ans[i]);
	return 0;
}