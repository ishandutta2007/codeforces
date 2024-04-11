#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 100000 + 10;
int gcd(int x,int y) {
    return y == 0 ? x: gcd(y, x % y); 
}
int m;
int vis[N], mu[N], prime[N];
LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x>>1);
    if (x % 2 == 0) return t * t % MOD;
    return t * t % MOD * a % MOD;
}
int main() {
    mu[1] = 1; 
    for (int i = 2; i < N; i ++) {
        if (vis[i] == 0) {
            prime[++ prime[0]] = i; 
            mu[i] = - 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < N; j ++){
            vis[i * prime[j]] = 1;
            mu[i * prime[j]] = (i % prime[j] == 0) ? 0 : - mu[i];
            if (i % prime[j] == 0) break;
        }
    }
    cin >> m;
    LL ans = 0;
    for (int i = 2; i <= m; i ++) {
        // [(m/i) / m] ^ k
        LL p = (m/i) * mpow(m, MOD-2) % MOD;
        ans = (ans - mu[i] * p * mpow((1 - p + MOD) % MOD, MOD-2)) % MOD;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << (ans + 1) % MOD << endl;
}

// p(0)=1, p(1)=1/2