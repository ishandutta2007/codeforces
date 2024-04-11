#include <bits/stdc++.h>
using namespace std;
#define N 2020

typedef long long LL;

const LL inf = 1ll << 60;

int n, m, a[N], b[N], c[N];
LL sa, sb;
int A[3][3], B[3][3];

typedef pair <LL, int> pli;

pli p[N*N];

void SWAP() {
	for (int i = 1; i <= n; i ++) c[i] = a[i];
	for (int i = 1; i <= m; i ++) a[i] = b[i];
	for (int i = 1; i <= n; i ++) b[i] = c[i];
	swap(n, m);
	swap(sa, sb);
}

LL solve1() {
    LL rlt = inf;
    for (int i = 1; i <= m; i ++) p[i] = pli(b[i], i);
    sort(p + 1, p + m + 1);
    for (int i = 1; i <= n; i ++) {
		int j = lower_bound(p + 1, p + m + 1, pli(a[i] + (sb - sa + 1) / 2, 0)) - p;
		if (j == m + 1) j = m;
		LL dif = abs((sa - a[i] + p[j].first) - (sb + a[i] - p[j].first));
		if (rlt > dif) {
			rlt = dif;
			A[1][1] = i, B[1][1] = p[j].second;
		}
		j = lower_bound(p + 1, p + m + 1, pli(a[i] + (sb - sa + 1) / 2 + 1, 0)) - p - 1;
		if (j == 0) j = 1;
		dif = abs((sa - a[i] + p[j].first) - (sb + a[i] - p[j].first));
		if (rlt > dif) {
			rlt = dif;
			A[1][1] = i, B[1][1] = p[j].second;
		}
    }
    return rlt;
}

LL solve2() {
	if (n == 1 || m == 1) return inf;
	LL rlt = inf;
	int cnt = 0, mod = m + 1;
	for (int i = 1; i <= m; i ++) {
		for (int j = i + 1; j <= m; j ++) {
            p[++cnt] = pli(b[i] + b[j], i * mod + j);
		}
	}
	sort(p + 1, p + cnt + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			LL two = a[i] + a[j];
			int k = lower_bound(p + 1, p + cnt + 1, pli(two + (sb - sa + 1) / 2, 0)) - p;
			if (k == cnt + 1) k = cnt;
			LL dif = abs((sa - two + p[k].first) - (sb + two - p[k].first));
			if (rlt > dif) {
				rlt = dif;
				A[2][1] = i, B[2][1] = p[k].second / mod;
				A[2][2] = j, B[2][2] = p[k].second % mod;
			}
			k = lower_bound(p + 1, p + cnt + 1, pli(two + (sb - sa + 1) / 2 + 1, 0)) - p - 1;
			if (k == 0) k = 1;
			dif = abs((sa - two + p[k].first) - (sb + two - p[k].first));
			if (rlt > dif) {
				rlt = dif;
				A[2][1] = i, B[2][1] = p[k].second / mod;
				A[2][2] = j, B[2][2] = p[k].second % mod;
			}
		}
	}
	return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sa += a[i];
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) scanf("%d", &b[i]), sb += b[i];
	bool chg = 0;
	if (sa > sb) SWAP(), chg = 1;
	LL ans = abs(sa - sb);
	int change = 0;
	LL ans1 = solve1();
	LL ans2 = solve2();
	if (ans > ans1) ans = ans1, change = 1;
	if (ans > ans2) ans = ans2, change = 2;
	printf("%I64d\n", ans);
	printf("%d\n", change);
	for (int i = 1; i <= change; i ++) {
		if (chg) swap(A[change][i], B[change][i]);
		printf("%d %d\n", A[change][i], B[change][i]);
	}
	return 0;
}