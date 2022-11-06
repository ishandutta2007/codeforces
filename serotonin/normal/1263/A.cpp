#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll a[3];
        for(ll i=0; i<3; i++) cin >> a[i];
        sort(a,a+3,greater<ll>());
        ll ans=0;
        ll tot=a[0]+a[1]+a[2];

        ll big=a[0]-a[1]-a[2];
        if(big<0) {
            ans=tot/2;
        }
        else {
            tot-=big;
            ans=tot/2;
        }
        cout << ans << endl;
    }
}