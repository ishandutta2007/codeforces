#include <bits/stdc++.h>
using namespace std;

long long extended_euclid(long long a, long long b, long long &x, long long &y) {
	if (!b) {x = 1, y = 0; return a;}
	long long rlt = extended_euclid(b, a % b, y, x);
	y -= (a / b) * x;
	return rlt;
}

long long chinese_remainder(int *r, int *w, int n) {
	long long rlt = 0, ww = 1, x, y;
	for (int i = 1; i <= n; i ++) ww *= w[i];
	for (int i = 1; i <= n; i ++) {
		extended_euclid(w[i], ww / w[i], x, y);
		rlt = (rlt + ww / w[i] * y * r[i]) % ww;
	}
	return (rlt % ww + ww) % ww;
}

int n, P;
int e;

int mod;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

#define N 101010

struct query {
	int a, b, c;
	bool tag;
	query(int a = 0, int b = 0, int c = 0, bool tag = 0) : a(a), b(b), c(c), tag(tag) {}
	void print() {printf("%d %d %d %d\n", a, b, c, tag);}
} q[N<<2];

void add_query(int k, bool tag = 0) {
	for (int b = 0, ac, a, c; b <= n; b ++) {
		ac = n - b;
		if ((ac + k) % 2 != 0) continue;
		a = (ac + k) / 2;
		c = (ac - k) / 2;
		if (a + c != ac || c < 0) continue;
		q[++e] = query(a, b, c, tag);
	}
}

#define M 1111

int p[M], h[M], MOD[M], cnt;

void get_p_h() {
	cnt = 0;
	for (int i = 2; i * i <= P; i ++) {
		if (P % i == 0) {
			p[++cnt] = i;
			while (P % i == 0) {
				P /= i;
				h[cnt] ++;
			}
		}
	}
	if (P != 1) p[++cnt] = P, h[cnt] = 1;
	for (int i = 1; i <= cnt; i ++) {
		MOD[i] = 1;
		for (int j = 0; j < h[i]; j ++) MOD[i] *= p[i];
	}
}

int ans[M];

int f[N], g[N];

void solve() {
	for (int j = 1; j <= cnt; j ++) {
		mod = MOD[j];
		f[0] = 1, g[0] = 0;
		for (int i = 1, ii; i <= n; i ++) {
			ii = i;
			g[i] = g[i-1];
			while (ii % p[j] == 0) {
				ii /= p[j];
				g[i] ++;
			}
			f[i] = 1ll * f[i-1] * ii % mod;
		}

		int rlt = 0;
		for (int i = 1, ff, gg, now, a, b, c; i <= e; i ++) {
			a = q[i].a, b = q[i].b, c = q[i].c;
			ff = 1ll * f[a] * f[b] % mod;
			ff = 1ll * ff * f[c] % mod;
			ff = expmod(ff, (mod / p[j]) * (p[j] - 1) - 1);
			ff = 1ll * ff * f[n] % mod;
			gg = g[n] - g[a] - g[b] - g[c];
			now = ff;
			for (int t = 0; t < gg; t ++) {
				now = 1ll * now * p[j] % MOD[j];
			}
			if (!q[i].tag) rlt = (1ll * rlt + now) % MOD[j];
			else rlt = (1ll * rlt + MOD[j] - now) % MOD[j];
		}
		ans[j] = rlt;
	}
	long long res = chinese_remainder(ans, MOD, cnt);
	printf("%I64d\n", res);
}

int main() {
	//freopen("r.in", "r", stdin);
	int L, R;
	scanf("%d %d %d %d", &n, &P, &L, &R);
	if (P == 1) {
		puts("0");
		return 0;
	}
	add_query(L);
	add_query(L + 1);
	add_query(R + 1, 1);
	add_query(R + 2, 1);
	get_p_h();
	solve();


	return 0;
}