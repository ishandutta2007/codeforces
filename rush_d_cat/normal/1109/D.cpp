#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
const int MOD = 1e9 + 7;

LL inv[N],fac[N];
LL mpow(LL a, LL x){
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}
LL C(int n,int m){
    if(n<m) return 0;
    if(n<0) return 0;
    LL ans = fac[n]*inv[m]%MOD*inv[n-m]%MOD;
    return ans;
}
LL cac(int n,int x) {
    if(n==0) return 1;
    return (x+n-1) * mpow(x-1, n-1) % MOD;
}
int n,m,a,b;
// 1000000 1000000 1 2
int main(){
    cin >> n >> m >> a >> b;
    inv[1]=1; inv[0]=1;
    for(int i=2;i<N;i++){
        inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    }
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=inv[i-1]*inv[i]%MOD;
    }

    LL ans = 0;
    for(int d=2;d<=m+1;d++){
        if(d>n) break;
        // n-2, d-2
        LL cnt1 = fac[n-2] * mpow(fac[n-d], MOD-2) % MOD;
    
        // d-1, m
        LL cnt2 = C(m-1,d-2); 
        LL cnt3 = cnt1 * cnt2 % MOD;

        LL cnt4 = mpow(-m, n-d) * cac(n-d, -(n-1)) % MOD;
        //printf("d = %d, cnt1 = %lld, cnt2 = %lld, cnt3 = %lld, cnt4 = %lld\n", d, cnt1,cnt2,cnt3,cnt4);
        ans = ans + cnt3 * cnt4 % MOD;
        ans = ans % MOD;
    }
    cout << ans << endl;

}