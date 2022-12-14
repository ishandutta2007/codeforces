#include <cstdio>

#define N 1000005

typedef __int64 LL;

const int MOD = 1000000007;

struct pnt {
	LL x, y;
	pnt(LL x = 0, LL y = 0) : x(x), y(y) {}
	pnt operator - (const pnt &p) const {
		return pnt((x - p.x + MOD) % MOD, (y - p.y + MOD) % MOD);
	}
	pnt operator + (const pnt &p) const {
		return pnt((x + p.x) % MOD, (y + p.y) % MOD);
	}
	LL operator ^ (const pnt &p) const {
		return x * p.y - y * p.x;
	}
} p[N];

LL V[N], VM[N];

main() {
//	freopen("G_3.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%I64d %I64d", &p[i].x, &p[i].y);
		p[i + n] = p[i];
	}
	for (int i = 0; i < n + n - 1; i ++) {
		V[i] = p[i + 1] ^ p[i];
		VM[i] = V[i] % MOD;
	}
	LL tot = 0;
	for (int i = 0; i < n - 1; i ++) tot += V[i];
	tot += p[0] ^ p[n - 1];
	LL cur = 0, A = 0, small = 0;
	pnt P = pnt(0, 0);
    for (int i = 0, j = 0; i < n; i ++) {
    	if (j < i + 1) j = i + 1;
    	for ( ; j < i + n; j ++) {
    		cur += V[j - 1];
    		LL tmp = cur + (p[i] ^ p[j]);
    		if (tmp > tot / 2) break;
    		if (tmp * 2 == tot && j >= n) break;
    		A = (A + cur % MOD) % MOD;
    		P = P + p[j];
    	}
    	small = (small + A + (p[i] ^ P) % MOD) % MOD;
    	cur -= V[j - 1] + V[i];
    	A = (A - (j - i - 1) * VM[i] % MOD) % MOD;
    	P = P - p[i + 1];
    }
    LL rlt = 1LL * n * (n - 3) / 2 % MOD;
    rlt = rlt * (tot % MOD) % MOD;
    rlt = (rlt - 2 * small) % MOD;
    if (rlt < 0) rlt += MOD;
    printf("%I64d\n", rlt);
}