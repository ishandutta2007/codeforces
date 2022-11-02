#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;
ll n;
int a, b, x, ans;

int expmod(int a, ll b, int mod) {
    int res = 1;
    for ( ; b; b >>= 1) {
        if (b & 1) res = 1ll * a * res % mod;
        a = 1ll * a * a % mod;
    }
    return res;
}

int main() {
    scanf("%d %d %I64d %d", &a, &b, &n, &x);
    if (a == 1) ans = (x + 1ll * n % mod * b) % mod;
    else {
        int c = a - 1;
        int d = expmod(a, n, mod);
        ans = 1ll * d * x % mod;
        d = (mod + d - 1) % mod;
        c = expmod(c, mod - 2, mod);
        ans = (ans + 1ll * c * d % mod * b) % mod;
    }
    printf("%d\n", ans);
    return 0;
}