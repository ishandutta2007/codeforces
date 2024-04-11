#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
const int mod = 1e9 + 7;

int n, p, k;

int expmod(int a, int b, int mod) {
	int res = 1;
	for (; b; b >>= 1) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
	}
	return res;
}

int main() {
    scanf("%d %d", &p, &k);
    if (k == 0) printf("%d\n", expmod(p, p - 1, mod));
    else if (k == 1) printf("%d\n", expmod(p, p, mod));
	else {
		int c = 1, d;
        f1(i, 1, p) {
			c = 1ll * k * c % p;
            if (c == 1) {
				d = i;
				break;
            }
        }
        d = (p - 1) / d;
        printf("%d\n", expmod(p, d, mod));
	}
	return 0;
}