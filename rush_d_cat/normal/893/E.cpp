#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
const int N = 1000000+10;
typedef long long LL;
LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x/2);
    if (x % 2 == 1) {
        return t*t%MOD*a%MOD;
    } else {
        return t*t%MOD;
    }
}

LL fac[2*N], inv[2*N];
LL notprime[N], prime[N];
vector<int> v[N];

void init() {
    fac[0] = 1, inv[0] = 1;
    for (int i = 1; i < 2*N; i ++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = mpow(fac[i], MOD-2) % MOD;
    }
    for (int i = 2; i < N; i ++) {
        if (!notprime[i]) {
            for (int j = i; j < N; j += i) {
                notprime[j] = 1;
                int tmp = j, cnt = 0;
                while (tmp % i == 0) {
                    cnt ++;
                    tmp /= i;
                }
                v[j].push_back(cnt);
            }
        }
    }

}

LL C(int n, int m) {
    return fac[n] * inv[m] % MOD * inv[n-m] % MOD;
}

int q, x, y;
int main() {
    init();
    scanf("%d", &q);
    while (q --) {
        scanf("%d %d", &x, &y);
        LL ans = 1;
        for (int i = 0; i < v[x].size(); i ++) {
            ans *= C(v[x][i] + y - 1, y - 1); ans %= MOD;
        }
        ans *= mpow(2, y-1); ans %= MOD;
        printf("%lld\n", ans);
    }
}