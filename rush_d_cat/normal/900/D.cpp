#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

const int N = 400000+10;
int prime[N], cnt = 0;
bool vis[N]; 
vector<LL> v;
void getPrime() {
    for (int i = 2; i < N; i ++) {
        if (vis[i] == 0) {
            prime[++ cnt] = i;
        }
        for (int j = 1; j <= cnt && prime[j] * i < N; j ++) {
            vis[prime[j] * i] = 1;

            if (i % prime[j] == 0) break;
        }
    }
}


LL x, y;
LL mpow(LL a, LL x) {
    if (x == 0) {
        return 1;
    }
    LL t = mpow(a, x / 2);
    if (x % 2)
        return t * t % MOD * a % MOD;
    return t * t % MOD;
}

LL solve(LL n) {
    LL d = n; int ct = 0;
    for (int i = 1; i <= cnt && prime[i] <= n; i ++) {
        //printf("%d\n", prime[i]);
        if (n % prime[i] == 0) {
            if ((n / prime[i]) % prime[i] == 0)
                return 0;
            n /= prime[i]; ct ++;
        }
    }
    if (n != 1) ct ++;

    if (ct % 2 == 0) return mpow(2, y/d - 1);
    return - mpow(2, y / d - 1);
}

int main() {
    cin >> x >> y;

    if (y % x) {
        printf("0\n");
        return 0;
    }

    getPrime();
    //solve(20); return 0;
    y /= x;
    for (LL i = 1; i*i <= y; i ++) {
        if (y % i == 0) {
            if (i*i == y) {
                v.push_back(i);
            } else {
                v.push_back(i); v.push_back(y/i);
            }
        }
    }

    LL ans = 0;
    for (int i=0;i<v.size();i++) {
        //printf("%lld\n", v[i]);
        //printf("%lld %lld\n", v[i], solve(v[i]));
        ans = (ans + solve(v[i])) % MOD;
        ans = (ans + MOD) % MOD;
    }
    cout << ans << endl;
}