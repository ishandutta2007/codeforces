#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 2000000 + 10;

int n;
LL pw[N], fac[N], facinv[N], inv[N];
LL c(int x, int y) {
    if (y < 0 || x < 0 || x < y) return 0;
    return fac[x] * facinv[y] % MOD * facinv[x - y] % MOD;
}
int main() {
    inv[1] = 1;
    for (int i = 2; i < N; i ++) {
        inv[i] = (MOD - (MOD/i)) * inv[MOD%i] % MOD;
    }
    pw[0] = 1;
    for (int i = 1; i < N; i ++) pw[i] = pw[i-1] * 2 % MOD;
    fac[0] = 1, facinv[0] = 1;
    for (int i = 1; i < N; i ++) {
        fac[i] = fac[i-1] * i % MOD;
        facinv[i] = facinv[i-1] * inv[i] % MOD;
        pw[i] = (pw[i-1] + pw[i]) % MOD;
    }


    cin >> n;
    LL ans = pw[2 * n];
    LL sum = 0;
    for (int pos = n + 1; pos <= 2 * n; pos ++) {
       sum = (sum + c(pos - 1, n) * pw[2 * n - pos] % MOD) % MOD;
    }

    sum = sum * 2 % MOD;
    ans = (ans + MOD - sum + MOD) % MOD;
    cout << ans << endl;
}