#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=1e5+5;

ll a,b;

ll rer(ll fa)
{
    ll re=fa-a;
    if(re<0) re=0-re;
    ll er=fa-b;
    if(er<0) er=0-er;
    return min(re, er);
}

int main()
{
    ll n,h,m,i,j,k,x,y,z,fin;
    scanf("%I64d %I64d %I64d %I64d %I64d", &n, &h, &a, &b ,&k);
    for(i=0;i<k;i++) {
        ll ta,fa,tb,fb;
        scanf("%I64d %I64d %I64d %I64d", &ta, &fa, &tb, &fb);
        y=0;
        if(fa==fb && ta==tb) {
            puts("0");
            continue;
        }

        if(ta==tb) {
            printf("%I64d\n", abs(fb-fa));
            continue;
        }

        if(a<=fa && fa<=b) fin=fa;
        else {
            y+=rer(fa);

            if(y+fa==a) fin=a;
            else fin=b;
        }

        x=fin-fb;
        if(x<0) x=0-x;
        z=fin-fb;
        if(z<0) z=0-z;
        y+=min(x,z);

        x=ta-tb;
        if(x<0) x=0-x;

        y+=x;

        printf("%I64d\n", y);
    }
}