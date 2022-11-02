#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define N 100100
#define mod 1000000007

int n, k;
LL a[N], b[N], c[N];

LL expmod(LL a, LL b) {
	LL rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = rlt * x % mod;
		x = x * x % mod, b >>= 1;
	}
	return rlt;
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	if (k == 0) {
		for (int i = 1; i <= n; i ++) cout << a[i] << ' '; cout << endl;
		return 0;
	}
	c[1] = 1;
    for (int i = 2; i <= n; i ++) {
        c[i] = (c[i-1] * (k + i - 2) % mod) * expmod(i - 1, mod - 2) % mod;
    }
    for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j ++) b[i] = (b[i] + c[i-j+1] * a[j]) % mod;
    }
    for (int i = 1; i <= n; i ++) cout << b[i] << ' '; cout << endl;
	return 0;
}