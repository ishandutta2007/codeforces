#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

ll a[sz];

int main()
{
    ll n;
    cin >> n;

    ll ans=n, ans2=1;
    vector <ll> ps;

    for(ll i=2; i*i<=n; i++) {
        ll z=1;
        while(n%i==0) {
            z*=i;
            n/=i;
        }
        if(z>1) ps.push_back(z);
    }
    if(n>1) ps.push_back(n);

    for(int m=0; m<sz; m++) {
        ll x=1, y=1;
        for(int i=0; i<ps.size(); i++) {
            if((1<<i)&m) x*=ps[i];
            else y*=ps[i];
        }

        if(max(x,y)<ans) {
            ans=max(x,y);
            ans2=min(x,y);
        }
    }

    cout << ans << " " << ans2 << endl;
}