#include <stdio.h>
#define abs(a) (a > 0 ? a : -a)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;

ll ext_euc(ll a, ll b, ll &x, ll &y){
    if(!b) {
        ll d = abs(a);
        x = d / a, y = 0;
        return d;
    }
    ll rest = a % b;
    if(rest < 0) rest += b;
    ll c = (a - rest) / b;
    ll d = ext_euc(b, rest, x, y);
    ll tmp = x;
    x = y, y = tmp - c * y;
    ll xx = x / b;
    x -= b * xx, y += a * xx;
    return d;
}

int main(){
    //freopen("c.in", "r", stdin);
    ll a, b, c;
    scanf("%I64d %I64d %I64d", &a, &b, &c);
    if(b < 0) a *= -1, b *= -1, c *= -1;
    ll x, y;
    ll d = ext_euc(a, b, x, y);
    if(c % d != 0) {puts("-1"); return 0;}
    c = -c / d;
    x *= c, y *= c;
    printf("%I64d %I64d\n", x, y);
}