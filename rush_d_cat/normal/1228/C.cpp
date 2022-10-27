#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;

int x; LL n;

LL mpow(LL a, LL x){ 
    if (x == 0) return 1;
    LL t = mpow(a, x>>1);
    if (x % 2 == 0) return t * t % MOD;
    return t * t % MOD * a % MOD; 
}

LL cac_cnt(int p) {
    // printf("p = %d\n", p);
    LL sum = 0, now = p;
    while(1) {
        sum = (sum + n / now) % (MOD-1);
        if (now > (n + p - 1) / p) break;
        now = now * p;
    }
    return mpow(p, sum);
}

int main() {
    scanf("%d%lld", &x, &n);
    vector<int> v;
    for(int i=2;i*i<=x;i++) {
        if(x%i == 0) {
            while(x % i == 0) {
                x /= i;
            }
            v.push_back(i);
        }
    }
    if (x > 1) v.push_back(x);
    LL res = 1;
    for (auto x: v) {
        res = res * cac_cnt(x) % MOD;
    }
    printf("%lld\n", res);
}