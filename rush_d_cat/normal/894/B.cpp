#include <iostream>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x/2);
    if (x%2==1) return a*t%MOD*t%MOD;
    return t*t%MOD;
}

int main() {
    LL n, m, k;
    cin >> n >> m >> k;
    LL ans = mpow(mpow(2,n-1),m-1);
    printf("%lld\n", ((n+m)%2&&k==-1) ? 0 : ans);
}