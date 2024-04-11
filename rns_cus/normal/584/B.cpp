#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

typedef long long LL;

LL expmod(LL a, LL b) {
	LL rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = rlt * x % mod;
		x = x * x % mod, b >>= 1;
	}
	return rlt;
}

int main() {
//	freopen("b.in", "r", stdin);
	int n;
	scanf("%d", &n);
	printf("%I64d\n", ((expmod(27, n) - expmod(7, n)) % mod + mod) % mod);
	return 0;
}