#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * a * rlt % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

#define N 1010

int f[N][N], k, pa, pb;

int main() {
	scanf("%d %d %d", &k, &pa, &pb);
	int tmp = expmod(pa + pb, mod - 2);
	pa = 1ll * pa * tmp % mod;
	pb = 1ll * pb * tmp % mod;
	for (int i = 1; i < N; i ++) for (int j = i; j < N; j ++) f[i][j] = (j + 1ll * pa * expmod(pb, mod - 2)) % mod;
	for (int i = 1; i < N; i ++) {
		for (int j = i - 1; j >= 0; j --) {
			if (j) f[i][j] = (1ll * pa * f[i][j+1] + 1ll * pb * (f[i-j][j] + j)) % mod;
			else f[i][j] = f[i][1];
		}
	}
	printf("%d\n", f[k][0]);

	return 0;
}