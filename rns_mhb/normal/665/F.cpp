#include <bits/stdc++.h>
using namespace std;

#define N 320000

typedef long long ll;
ll n, k;
ll f[N], g[N];

ll calc(ll n) {
    ll m, rtn = 0;
    for (m = 1; m * m <= n; m ++) f[m] = n / m - 1;
    for (ll i = 1; i <= m; i ++) g[i] = i - 1;
    for (ll i = 2; i <= m; i ++) {
        if (g[i] == g[i-1]) continue;
        for (ll j = 1; j <= min(m - 1, n / i / i); j ++) {
            if (i * j < m) f[j] -= f[i*j] - g[i-1];
            else f[j] -= g[n/i/j] - g[i-1];
        }
        for (ll j = m; j >= i * i; j --) g[j] -= g[j/i] - g[i-1];
    }
    for (ll i = 2; i < m; i ++) {
        if (g[i] == g[i-1]) continue;
        rtn += f[i] - g[i];
        
    }
    return rtn;
}

int main() {
    
    scanf("%I64d", &n);
    k = pow(n, 1.0 / 3) + 1e-9;
    printf("%I64d\n", calc(n) + g[k]);
    return 0;
}