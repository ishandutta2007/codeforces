#include <bits/stdc++.h>
using namespace std;

int n, mod;

int expmod(int a, int b) {
	int rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * x % mod;
		x = 1ll * x * x % mod, b >>= 1;
	}
	return rlt;
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &mod);
	printf("%d\n", (expmod(3, n) - 1 + mod) % mod);
	return 0;
}