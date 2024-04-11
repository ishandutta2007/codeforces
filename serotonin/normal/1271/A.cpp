#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

int main()
{
    ll a[6];
    for(ll i=0; i<6; i++) cin >> a[i];

    ll ans=0, z=min(a[1],a[2]);
    for(ll i=0; i<=min(a[3],a[0]); i++) {
        ll x=i, y=min(a[3]-i,z);
        ans=max(ans, x*a[4]+y*a[5]);
    }
    cout << ans << endl;
}