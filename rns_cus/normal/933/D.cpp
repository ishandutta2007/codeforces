#include <bits/stdc++.h>
using namespace std;

#define N 1000100

typedef long long ll;

ll m;
const int mod = 1e9 + 7;
ll sum[5][N];

ll powmod(int x, int n) {
    ll rlt = 1;
    while (n) {
        if (n & 1) rlt = rlt * x % mod;
        x = 1ll * x * x % mod, n >>= 1;
    }
    return rlt;
}

ll mul(ll x, ll y) {
    ((x %= mod) += mod) %= mod;
    ((y %= mod) += mod) %= mod;
    return x * y % mod;
}

int main() {
    for (int i = 0; i <= 3; i ++) {
        for (int j = 1; j < N; j ++) {
            sum[i][j] = sum[i][j-1];
            (sum[i][j] += powmod(j, 2 * i)) %= mod;
        }
    }
    scanf("%I64d", &m);
    int k = sqrt(m);
    ll rlt = 0;
    int x = 2 * powmod(3, mod - 2) % mod;
    for (int i = 1; i <= k; i ++) {
        (rlt += mul(m - 1ll * i * i + 1, mul(m - 1ll * i * i + 2, m + 2ll * i * i))) %= mod;
        int t = sqrt(m - 1ll * i * i);
        (rlt += 2 * sum[3][t]) %= mod;
        (rlt += mul(6ll * i * i - 3 * m - 6, sum[2][t])) %= mod;
        (rlt += mul(6 * mul(1ll * i * i, 1ll * i * i) - 6 * mul(m + 2, 1ll * i * i) + 3 * m + 4, sum[1][t])) %= mod;
        (rlt += mul(sum[0][t], mul(1ll * i * i - m - 1, mul(1ll * i * i - m - 2, 2ll * i * i + m)))) %= mod;
    }
    (rlt *= x) %= mod;
    (rlt += mul(powmod(6, mod - 2), mul(m, mul(m + 1, m + 2)))) %= mod;
    printf("%I64d\n", rlt);
}