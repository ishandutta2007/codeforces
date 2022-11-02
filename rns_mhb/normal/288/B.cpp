#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define N 1005

int expmod(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
    }
    return res;
}

int main() {
    int n, k;
	scanf("%d %d", &n, &k);
    n = 1ll * expmod(n-k, n-k, mod) * expmod(k, k-1, mod) % mod;
    printf("%d\n", n);
}