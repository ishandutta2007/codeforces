#include <bits/stdc++.h>
using namespace std;

#define N 10010
#define M 100010

int n, m, a[N], b[M], p, bb, c[N];

int cnt, q[100], e[100], ya[N], yas;

int expmod(int a, int b) {
	if (!b) return 1;
	int rlt = expmod(a, b / 2);
	rlt = 1ll * rlt * rlt % p;
	if (b % 2) rlt = 1ll * rlt * a % p;
    return rlt;
}

void dfs(int i, int now) {
	if (i == cnt + 1) {
		ya[++yas] = now;
		return ;
	}
	int cur = now;
	for (int j = 0; j <= e[i]; j ++, cur *= q[i]) {
		dfs(i + 1, cur);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int j = 1; j <= m; j ++) {
		scanf("%d", &b[j]);
		b[j] %= p - 1;
    }
    if (p == 2) {
		puts("1");
		return 0;
    }
    bb = p - 1;
    for (int j = 1; j <= m; j ++) bb = __gcd(bb, b[j]);
    if (bb == p - 1) {
		puts("1");
		return 0;
    }
	int h = p - 1;
	for (int qq = 2; qq * qq <= h; qq ++) {
        if (h % qq == 0) {
        	q[++cnt] = qq;
			while (!(h % qq)) {
                h /= qq;
				e[cnt] ++;
			}
        }
	}
	if (h > 1) q[++cnt] = h, e[cnt] = 1;
	dfs(1, 1);
	sort (ya + 1, ya + yas + 1);
    for (int i = 1; i <= n; i ++) {
		for (int k = 1; k <= yas; k ++) {
			if (expmod(a[i], ya[k]) == 1) {
				c[i] = ya[k];
				break;
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		c[i] = (p - 1) / c[i] * __gcd(c[i], bb);
	}
	int hwai[1000];
	for (int k = 1, rlt; k <= yas; k ++) {
        rlt = ya[k];
        for (int i = 1; i <= cnt; i ++) if (ya[k] % q[i] == 0) rlt = 1ll * rlt * (q[i] - 1) / q[i];
        hwai[k] = rlt;
	}
    int ans = 0;
    for (int k = 1; k <= yas; k ++) {
		bool tag = 0;
		for (int i = 1; i <= n && !tag; i ++) {
			if (ya[k] % c[i] == 0) tag = 1;
		}
		if (tag) ans += hwai[yas+1-k];
    }
    printf("%d\n", ans);
	return 0;
}