#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200000 + 10;
typedef long long LL;

const LL MOD = 1e9 + 7;
int n; LL l[N],r[N],f[N],g[N];
LL mpow(LL a, LL x) {
    if(x==0) return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0) return t*t%MOD;
    return t*t%MOD*a%MOD;
}
LL cac(int pos){
    LL tot=(r[pos-1]-l[pos-1]+1)*(r[pos]-l[pos]+1)%MOD*(r[pos+1]-l[pos+1]+1)%MOD;
    LL s12 = max(0LL, min(r[pos],r[pos-1])-max(l[pos],l[pos-1])+1);
    LL s23 = max(0LL, min(r[pos],r[pos+1])-max(l[pos],l[pos+1])+1);
    LL s123 = max(0LL, min(min(r[pos],r[pos+1]),r[pos-1])-max(max(l[pos],l[pos+1]),l[pos-1])+1);
    tot += s123 - s12*(r[pos+1]-l[pos+1]+1) - s23*(r[pos-1]-l[pos-1]+1);
    //printf("(%lld,%lld,%lld)\n", s12,s23,s123);
    //printf("pos=%d, %d\n", pos,(tot%MOD+MOD)%MOD);
    return tot = (tot % MOD + MOD) % MOD;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&l[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&r[i]);
    }
    LL M=1;
    for(int i=1;i<=n;i++){
        M=M*(r[i]-l[i]+1)%MOD;
    }

    LL sum=0;
    for(int i=1;i<=n;i++){
        f[i] = 1LL*(r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%MOD;
        LL x = max(0LL, min(r[i],r[i-1])-max(l[i],l[i-1])+1);
        g[i] = f[i] = ((f[i] - x) % MOD + MOD) % MOD;
        //printf("g[%d] = %d, x = %lld\n", i, g[i], x);
        f[i] = f[i] * mpow(1LL*(r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%MOD, MOD-2) % MOD;
        //printf("f[%d] = %lld\n", i, f[i]*M%MOD);
        sum = (sum + f[i]) % MOD;
    }
    LL ans = sum * sum;
    for (int i=1;i<=n;i++){
        ans = (ans-f[i]*f[i]%MOD-2*f[i]*f[i-1]%MOD);
        ans = (ans % MOD + MOD) % MOD;
    }
    //cout << (ans * M % MOD) << endl;
    for(int i=1;i<=n;i++){
        ans = (ans + f[i]) % MOD;
    }
    //cout << (ans * M % MOD) << endl;
    for(int i=1;i<n;i++) {
        ans = (ans + 2 * cac(i) * mpow(1LL*(r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%MOD*(r[i+1]-l[i+1]+1)%MOD, MOD-2)) % MOD;
    }
    //cout << (ans * M % MOD) << endl;
    cout << ans << endl;
}