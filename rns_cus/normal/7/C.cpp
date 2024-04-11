#include<stdio.h>
typedef __int64 ll;
ll extEuclid(ll a, ll b, ll&x, ll&y) {
     //extEuclid(a, b, x, y)=a*x+b*y;
    if(!b) {x=1, y=0;return a;}
    ll d, tmp;
    d=extEuclid(b, a%b, x, y);
    tmp=x;
    x=y;
    y=tmp-a/b*y;
    if(x < 0ll)x = b - ((-x) % b);
    else x %= b;
    x %= b;
    y = (d - a * x) / b;
    return d;
}
ll abs(ll x){if(x < 0ll)return -x;return x;}
int main(){
    ll a,b,c,x,y;
    while(scanf("%I64d%I64d%I64d", &a, &b, &c) == 3){
        if(!c){printf("%d %d\n", 0, 0);continue;}
        if(!a){
            if(abs(c) % abs(b) == 0)printf("%d %I64d\n", 0, -c / b);
            else puts("-1");
            continue;
        }
         if(!b){
            if(abs(c) % abs(a) == 0)printf("%I64d %d\n", -c / a, 0);
            else puts("-1");
            continue;
        }
        ll aa = abs(a), bb = abs(b);
        ll d = extEuclid(aa, bb, x, y);
        x *= (aa / a), y *= (bb / b);
        if(abs(c) % d){puts("-1");continue;}
        printf("%I64d %I64d\n", -x * (c / d), -y * (c / d));
    }
    return 0;
}