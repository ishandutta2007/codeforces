#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 100000+10;
LL mpow(LL a,LL x) {
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}
int n,q;
char s[N];int sum[N];

int main() {
    scanf("%d%d%s",&n,&q,s+1);
    for(int i=1;i<=n;i++) {
        sum[i] = sum[i-1] + (s[i]=='1'?1:0);
    }   
    while(q--) {
        int l,r; scanf("%d%d",&l,&r);
        int x=sum[r]-sum[l-1];
        int y=(r-l+1)-x;
        printf("%lld\n", (mpow(2,x)-1+MOD)%MOD * mpow(2,y) % MOD);
    }
}