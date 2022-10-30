#include <bits/stdc++.h>

using namespace std;

#define N 133
typedef unsigned int uint;

int n, p, q;
uint f[2][N], C[N];

void run() {
	uint ans = 0;
	for(int i = 1; i <= q; i ++) {
		uint x = 1, t = 0;
		for(int j = 0; j <= p; j ++) {
			t += C[j] * x;
			x *= i;
		}
		ans = ans ^ (t * (uint)(i));
	}
    printf("%u\n", ans);
}

int g[N], gg[N][N];

uint calc(int a, int b) {
	if(b > a) return 0;
	if(b == 0) return 1;
	for(int i = 0; i < b; i ++) g[i] = a - i;
	for(int i = b; i > 1; i --) {
		int x = i;
		for(int j = 0; j < b && x > 1; j ++) {
			int y = gg[x][g[j] % x];
			x /= y; g[j] /= y;
		}
	}
	uint rt = 1;
	for(int i = 0; i < b; i ++) {
		rt *= (uint)g[i];
	}
	return rt;
}

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

void init() {
	for(int i = 0; i < N; i ++) for(int j = 0; j < N; j ++) gg[i][j] = gcd(i, j);
		C[0] = 1;
		for(int k = 0; k <= p; k ++) {
			C[k] = calc(n, k);
		}
}

int main() {
	scanf("%d%d%d", &n, &p, &q);
	if(p >= n) p = n - 1;
	init();
	run();
	return 0;
}