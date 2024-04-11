#include <iostream>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 1000000007;

int n, k;
LL f[N], inv[N];
LL a[N];

LL mpow(LL a, LL x) {
    if (x == 0)
        return 1;
    LL t = mpow(a, x/2);
    if (x % 2 == 0)
        return t * t % MOD;
    return t * t % MOD * a % MOD;
}

void init() {
    f[0] = inv[0] = 1;
    for (int i = 1; i < N; i ++) {
        f[i] = f[i-1] * i % MOD;
        inv[i] = mpow(f[i], MOD - 2);
    }
}

LL c(LL x, LL y) {
    return f[x] * inv[y] % MOD * inv[x-y] % MOD;
}

LL S(LL x, LL y) {
    LL ans = 0;
    for (int i = 0; i <= y; i ++) {
        if (i%2 == 0)
            ans = ans + c(y, i) * mpow(y - i, x);
        else
            ans = ans - c(y, i) * mpow(y - i, x); 
        ans = (ans % MOD + MOD) % MOD;
    }
    ans = ans * inv[y] % MOD;
    return ans;
}

int main() {
    init();
    scanf("%d %d", &n, &k);

    LL sum = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
        sum += a[i]; sum %= MOD;
    }

    if (n == 1 && k == 1) {
        return !printf("%lld\n", a[1]);
    } 

    LL ret = S(n,k) + S(n-1,k) * (n-1);
    ret %= MOD; ret = ret * sum % MOD;
    cout << ret << endl;
}