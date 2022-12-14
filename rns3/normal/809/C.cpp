#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

int T, x, y, xx, yy, k;

int calc(int x, int y, int k, int add) {
    if (x > y) swap(x, y);
    if (!x) return 0;
    if (k <= 0) return 0;
    int z = 1 << (31 - __builtin_clz(y)), rlt = 0;
	int kk = min(k, z);
    if (x < z) {
        rlt = ((1ll * (kk + 1) * kk / 2 % P) * x) % P + (((1ll * kk * x) % P * add) % P);
        rlt = (rlt % P + calc(x, y - z, k - z, z + add)) % P;
    }
    else {
        rlt = (((1ll * (kk + 1) * kk / 2 % P) * z) % P + ((1ll * kk * z) % P * add)) % P + calc(x - z, y - z, k, add);
        rlt = (1ll * rlt + 1ll * (calc(z, y - z, k - z, z + add) + calc(z, x - z, k - z, z + add))) % P;
    }
    return rlt;
}

int main() {
	scanf("%d", &T);
	while (T --) {
        scanf("%d %d %d %d %d", &x, &y, &xx, &yy, &k);
        x --, y --;
        int ans = calc(xx, yy, k, 0) + calc(x, y, k, 0) - calc(x, yy, k, 0) - calc(xx, y, k, 0);
        ans = (1ll * ans + P * 2) % P;
        printf("%d\n", ans);
	}
	return 0;
}