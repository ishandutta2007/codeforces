#include <bits/stdc++.h>
using namespace std;
#define M 2002002
typedef long long ll;

const ll mod = 1000000007;
int n;
ll fac[M] = {1}, fac_[M] = {1};

ll C(int a, int b) {
    return (fac[a] * fac_[b] % mod) * fac_[a-b] % mod;
}

ll POW(ll a, ll n) {
    ll s = 1;
    while (n) {
        if (n & 1) {
            s = s * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return s;
}

int main() {
    //freopen("H.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i < M; i++) {
        fac[i] = fac[i-1] * i % mod;
    }
    fac_[M-1] = POW(fac[M-1], mod - 2);
    for (int i = M - 2; i >= 0; i--) {
        fac_[i] = fac_[i+1] * (i + 1) % mod;
    }

    ll answer = POW(2, 2 * n + 1) - 1;

    for (int k = 1; k <= n; k++) {
        answer = answer + 2 * mod - 2 * C(2 * n + 1, k) + 2 * C(n + k, k);
    }
    printf("%I64d\n", answer % mod);
    return 0;
}