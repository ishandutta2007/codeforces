#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100;
int prime[N], cnt = 0;
bool vis[N]; 
int phi[N], mius[N];
vector<LL> vec[N];
void getPrime() {
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
void init() {
    for (int i = 3; i <= 61; i ++) {
        for (LL j = 2;; j ++) {
            LL t = 1;
            bool ok = 1;
            for (int k = 1; k <= i; k ++) {
                if ((double)t * j > 1e18+100)
                    ok = 0;
                t *= j;
            }
            if (ok == 0) break;
            vec[i].push_back(t);
        }
    }
}

int Q; LL L, R;

LL solve(LL x) {
    LL t = sqrt(x);
    LL ans = 0;

    if (t*t > x) t --;
    ans += t;

    for (int i = 3; i <= 60; i ++) {
        if (mius[i] == 0) continue;
        int pos = upper_bound(vec[i].begin(), vec[i].end(), x) - vec[i].begin();

        ans -= mius[i] * pos;
    }
    return ans;
}

int main() {
    getPrime(); init();
    scanf("%d", &Q);
    while (Q --) {
        scanf("%lld %lld", &L, &R);
        LL ret = solve(R) - solve(L-1);
        printf("%lld\n", ret);
    }
}