#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
LL x, k;
LL mpow(LL a, LL x) {
    if(x==0) return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0) return t*t%MOD;
    return t*t%MOD*a%MOD;
}
int main() {
    cin >> x >> k;
    if(x==0) {
        return !printf("0\n");
    }
    LL ans = (( x - mpow(2, MOD-2) ) % MOD + MOD)%MOD;
    ans = ans*mpow(2,k)%MOD;
    ans = ans + mpow(2,MOD-2); ans%=MOD;
    ans = ans*2LL%MOD;
    cout<<ans<<endl;
}