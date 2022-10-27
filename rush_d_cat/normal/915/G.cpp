#include <iostream>
using namespace std;
typedef long long LL;
const int N = 2000000+10;
const LL MOD = 1000000007;
LL n, k;
LL F[N];

int prime[N], cnt = 0;
bool vis[N]; 
int phi[N], mius[N];

void getPrime() 
{
    phi[1] = 1, mius[1] = 1;

    for (int i = 2; i < N; i ++) {
        if (vis[i] == 0) {
            prime[++ cnt] = i;
            phi[i] = i - 1;
            mius[i] = -1;
        }

        for (int j = 1; j <= cnt && prime[j] * i < N; j ++) {
            vis[prime[j] * i] = 1;

            if (i % prime[j] == 0) {           
                mius[prime[j] * i] = 0;
                phi[prime[j] * i] = phi[i] * prime[j];
                break;
            } else {
                mius[prime[j] * i] = mius[i] * -1;
                phi[prime[j] * i] = phi[i] * (prime[j] - 1);
            }
        }
    }
}

LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x/2);
    if (x % 2) return t * t % MOD * a % MOD;
    return t * t % MOD;
}

LL sum[N], mp[N];
void init() {
    for (int i = 1; i < N; i ++) {
        mp[i] = mpow(i, n);
    }
    for (int i = 1; i <= k; i ++) if (mius[i]) {
        for (int j = i; j <= k; j = j + i) {
            if (mius[i] == 1)
                sum[j] = ((sum[j] + (mp[j/i]-mp[j/i-1])) % MOD + MOD) % MOD;
            else
                sum[j] = ((sum[j] - (mp[j/i]-mp[j/i-1])) % MOD + MOD) % MOD;
        }
    }

    for (int i = 1; i <= k; i ++) {
        sum[i] = (sum[i] + sum[i-1]) % MOD;
    }
}

int main() {
    cin >> n >> k;
    getPrime();
    init();

    LL ans = 0;
    for (int i = 1; i <= k; i ++)  ans = (ans + (i ^ sum[i])) % MOD;
    cout << ans << endl;
}