#include <bits/stdc++.h>
using namespace std;

#define N 5050
#define FOR for (int i = 1; i <= n; i ++)
typedef long long LL;

int n, st, en, x[N], a[N], b[N], c[N], d[N], nxt[N];

LL dist(int i, int j) {
	if (j > i) return 1ll * x[j]-x[i]+d[i]+a[j];
	return 1ll * x[i]-x[j]+c[i]+b[j];
}

int main() {
	scanf("%d %d %d", &n, &st, &en);
	FOR scanf("%d", &x[i]);
	FOR scanf("%d", &a[i]);
	FOR scanf("%d", &b[i]);
	FOR scanf("%d", &c[i]);
	FOR scanf("%d", &d[i]);
	nxt[st] = en;
	FOR if (i != st && i != en) {
		int ntt = st;
		LL now, fin = dist(st, i) + dist(i, nxt[st]) - dist(st, nxt[st]);
		for (int nt = nxt[st]; nt != en; nt = nxt[nt]) {
			now = dist(nt, i) + dist(i, nxt[nt]) - dist(nt, nxt[nt]);
			if (fin > now) fin = now, ntt = nt;
		}
		nxt[i] = nxt[ntt];
		nxt[ntt] = i;
	}
	LL ans = 0;
	FOR if (i != en) ans += dist(i, nxt[i]);
	printf("%I64d\n", ans);
	return 0;
}