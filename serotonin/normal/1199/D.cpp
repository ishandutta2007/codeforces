#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=2e5+5;

ll a[sz],d[sz],tp[sz];
map <ll,ll> mp;

int main()
{
    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++) scanf("%lld", &a[i]);

    ll q,mx=-1;
    cin >> q;
    for(ll i=1; i<=q; i++) {
        int f;
        scanf("%d", &f);
        if(f==1) {
            ll p,tk;
            scanf("%lld %lld", &p, &tk);
            a[p]=tk;
            d[p]=i;
        }
        else {
            ll b;
            scanf("%lld", &b);
            mp[i]=b;
            mx=i;
        }
    }

    if(mx>=0) {
        q=mx, mx=0;
        for(ll i=q; i>=0; i--) {
            mx=max(mx, mp[i]);
            tp[i]=mx;
        }
    }

    for(ll i=1; i<=n; i++) {
        a[i]=max(a[i], tp[d[i]]);
    }

    for(ll i=1; i<=n; i++) printf("%lld ", a[i]);
}