#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=5e5+5;

int main()
{
    ll n,a=0,b=0;
    cin >> n;
    while(n--) {
        char c;
        getchar();
        scanf("%c", &c);
        if(c=='+') {
            ll x,y;
            scanf("%lld %lld", &x, &y);
            ll ta,tb,tc,td;
            ta=max(a,x),tb=max(b,y);
            tc=max(a,y),td=max(b,x);
            if(ta*tb<tc*td) {
                a=ta;
                b=tb;
            }
            else {
                a=tc;
                b=td;
            }
        }
        else {
            ll x,y;
            scanf("%lld %lld", &x, &y);
            if(max(x,y)>=max(a,b) && min(x,y)>=min(a,b)) puts("YES");
            else puts("NO");
        }
    }
}