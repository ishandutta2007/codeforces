#include <bits/stdc++.h>
using namespace std;

#define K 1000005

const int mod = 1e9 + 7;
int n, k;
int y[K];
int ans;

int powmod(int a, int b) {
    a = (a + mod) % mod;
    int rtn = 1;
    for (; b; b >>= 1) {
        if (b & 1) rtn = 1ll * rtn * a % mod;
        a = 1ll * a * a % mod;
    }
    return rtn;
}

void init() {
    y[0] = 0;
    for (int i = 1; i <= k + 1; i ++) {
        y[i] = (y[i-1] + powmod(i, k)) % mod;
    }
}

int main() {
    scanf("%d %d", &n, &k);
    init();
    if (n <= k + 1) printf("%d\n", y[n]);
    else {
        int now = 1;
        for (int i = 1; i <= k + 1; i ++) now = 1ll * now * (n - i) % mod * powmod(-i, mod - 2) % mod;
        ans = 1ll * y[0] * now % mod;
        for (int i = 1; i <= k + 1; i ++) {
            now = 1ll * now * (n - (i - 1)) % mod * (i - k - 2) % mod * powmod(n - i, mod - 2) % mod;
            now = 1ll * now * powmod(i, mod - 2) % mod;
            (ans += 1ll * now * y[i] % mod) %= mod;
        }
        printf("%d\n", (ans + mod) % mod);
    }
}