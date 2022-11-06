#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=5e5+5;

ll a[sz];

int main()
{
    ll n,d,e;
    cin >> n >> d >> e;
    e*=5;
    ll ans=n;
    for(ll i=0; i*d<=n; i++) {
        ll x=n-i*d;
        ans=min(ans, x%e);
    }
    cout << ans;
}