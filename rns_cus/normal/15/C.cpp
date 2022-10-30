#include<stdio.h>
typedef __int64 ll;
ll ss(ll x) {
    ll ret = 0;
    ll xx = x;
    int cnt = 0;
    while(x) {
        if(x & 1ll){
            if(!cnt)ret ^= (xx - 1ll);
            if(cnt == 1) ret ^= 1ll;
        }
        cnt ++;
        x >>= 1;
    }
    return ret;
}
int main(){
    ll n, x, a;
    scanf("%I64d", &n);
    ll ans = 0ll;
    for(int i = 0; i < n; i ++) {
        scanf("%I64d%I64d", &a, &x);
        ans = ans ^ (ss(a + x) ^ ss(a));
    }
    if(ans)puts("tolik");
    else puts("bolik");
}