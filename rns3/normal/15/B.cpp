#include<stdio.h>
#include<algorithm>
using namespace std;
typedef __int64 ll;
ll aa, bb, cc, dd;
ll a, b, c, d;
ll A, AA, B, BB, C, CC, D, DD;
ll ss(){
    ll ret = 2ll * (B - A + 1) * (D - C + 1);
    ll x = max(A, AA);
    ll y = min(B, BB);
    ll xx = max(C, CC);
    ll yy = min(D, DD);
    if(y < x || yy < xx) return ret;
    return ret - (y - x + 1) * (yy - xx + 1);

}
int main(){
    ll n, m;
    int T;
   // freopen("A.in","r",stdin);
    scanf("%d", &T);
    while(T --) {
        scanf("%I64d%I64d", &n, &m);
        scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
        aa = min(a - 1, c - 1);
        bb = min(n - a, n - c);
        cc = min(b - 1, d - 1);
        dd = min(m - b, m - d);
        A = a - aa, B = a + bb;
        C = b - cc, D = b + dd;
        AA = c - aa, BB = c + bb;
        CC = d - cc, DD = d + dd;
        printf("%I64d\n", n * m - ss());


    }
}