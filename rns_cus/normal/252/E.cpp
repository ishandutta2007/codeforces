#include <bits/stdc++.h>
using namespace std;
#define N 1001000

typedef long long LL;

LL lcm(LL a, LL b) {
    return a / __gcd(a, b) * b;
}

LL a, b, k, ans;
int f[N], g[N];

int main() {
//    freopen("e.in", "r", stdin);
    cin >> a >> b >> k;
    int mod = 1;
    for (int i = 1; i <= k; i ++) mod = lcm(mod, i);
    for (int i = 1; i <= mod; i ++) {
        f[i] = f[i-1] + 1;
        for (int j = 2; j <= k; j ++) f[i] = min(f[i], f[i-i%j] + 1);
    }
    int x = a % mod, y = b % mod;
    g[y] = 0;
    for (int i = y + 1; i <= mod; i ++) {
        g[i] = g[i-1] + 1;
        for (int j = 2; j <= k; j ++) {
            if (i - i % j >= y) g[i] = min(g[i], g[i-i%j] + 1);
        }
    }
    LL L = b - y + mod, R = a - x;
    if (R < L) ans = g[x];
    else ans = (R - L) / mod * f[mod] + g[mod] + f[x];
    cout << ans << endl;
    return 0;
}