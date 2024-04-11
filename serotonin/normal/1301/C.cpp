#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int a[sz];

ll fnc(ll n)
{
    return n*(n+1)/2;
}

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        ll n,m;
        scanf("%lld %lld", &n, &m);

        ll d=min(n-m,m+1);
        m=n-m;

        if(!d) {
            printf("%lld\n", fnc(n));
            continue;
        }

        ll ans=fnc(n);

        ll one=m/d;

        ll besi=m%d;

        ans-=besi*fnc(one+1);
        ans-=(d-besi)*fnc(one);

        printf("%lld\n", ans);
    }
}