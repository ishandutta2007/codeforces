#include <bits/stdc++.h>
using namespace std;

const long long INF = 1ll << 60;

#define N 22

int p[N];
int n;

map <long long, long long> mp[N];

int E = 0, F = 0, G = 0;
long long b[77], c[7777], d[77777], e[777777], f[777777], g[2777777];

long long func(long long val, int m) {
	if (m == 6) {
		int id = lower_bound(g, g + G + 1, val + 1) - g;
		return id;
	}
	if (mp[m].count(val)) return mp[m][val];
	if (m == 0) return 1;
	long long rlt = 0;
	long long now = val;
	while (now) {
		rlt += func(now, m - 1);
		now /= p[m];
	}
	mp[m][val] = rlt;
	return rlt;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
	sort(p + 1, p + n + 1);
	long long k;
	scanf("%I64d", &k);
	b[0] = 1;
	int B = 0;
	while (INF / p[1] >= b[B]) b[B+1] = b[B] * p[1], B ++;
	if (n == 1) {
		printf("%I64d\n", b[k-1]);
		return 0;
	}
	int C = 0;
	c[0] = 1;
	for (int i = 0; i <= B; i ++) {
		long long now = b[i];
		if (now != 1) c[++C] = now;
		while (INF / p[2] >= now) now *= p[2], c[++C] = now;
	}
	sort(c + 1, c + C + 1);
	if (n == 2) {
		printf("%I64d\n", c[k-1]);
		return 0;
	}
	int D = 0;
	d[0] = 1;
	for (int i = 0; i <= C; i ++) {
		long long now = c[i];
		if (now != 1) d[++D] = now;
		while (INF / p[3] >= now) now *= p[3], d[++D] = now;
	}
	sort(d + 1, d + D + 1);
	if (n == 3) {
		printf("%I64d\n", d[k-1]);
		return 0;
	}
	e[0] = 1;
	for (int i = 0; i <= D; i ++) {
		long long now = d[i];
		if (now != 1) e[++E] = now;
		while (INF / p[4] >= now) now *= p[4], e[++E] = now;
	}
	sort(e + 1, e + E + 1);
	if (n == 4) {
		printf("%I64d\n", e[k-1]);
		return 0;
	}
	f[0] = 1;
	for (int i = 0; i <= E; i ++) {
		long long now = e[i];
		if (now != 1) f[++F] = now;
		while (INF / p[5] >= now) now *= p[5], f[++F] = now;
	}
	sort(f + 1, f + F + 1);
	if (n == 5) {
		printf("%I64d\n", f[k-1]);
		return 0;
	}
	g[0] = 1;
	for (int i = 0; i <= F; i ++) {
		long long now = f[i];
		if (now != 1) g[++G] = now;
		while (INF / p[6] >= now) now *= p[6], g[++G] = now;
	}
	sort(g + 1, g + G + 1);

	//printf("k is %I64d\n", k);
	long long st = 0, en = INF, mid;
	while (st < en - 1) {
		mid = (st + en) >> 1;
		long long tmp = func(mid, n);
		//printf("func(%I64d) is %I64d\n", mid, tmp);
		if (tmp < k) st = mid;
		else en = mid;
	}
	printf("%I64d\n", st + 1);


	return 0;
}