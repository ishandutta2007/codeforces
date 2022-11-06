#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

ll n,m,q,g;

ll fnc(ll x, ll y)
{
    if(x==1) return (y+n-1)/n;
    else return (y+m-1)/m;
}

int main()
{
    cin >> n >> m >> q;
    g=__gcd(n,m);
    n/=g, m/=g;
    while(q--) {
        ll sx,sy,ex,ey;
        scanf("%lld %lld %lld %lld", &sx, &sy, &ex, &ey);
        ll x=fnc(sx,sy);
        ll y=fnc(ex,ey);
        if(x==y) puts("YES");
        else puts("NO");
    }
}