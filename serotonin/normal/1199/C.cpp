#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=4e5+5;

ll a[sz];
map <ll,ll> mp;
vector <ll> c;

int main()
{
    ll n,t;
    cin >> n >> t;
    t*=8;
    for(ll i=0; i<n; i++) scanf("%lld", &a[i]);
    sort(a,a+n);
    c.push_back(1);
    for(ll i=1,j=0; i<n; i++) {
        if(a[i]==a[i-1]) c[j]++;
        else c.push_back(1), j++;
    }

    ll k=min(60LL,t/n),b=1LL<<k;
    ll ans=n,y=0,z=c.size();
    for(ll i=1; i<c.size(); i++) c[i]+=c[i-1];
    for(ll i=0; i<c.size(); i++) {
        ll j=min(i+b-1,z-1);
        ans=min(ans, y+c[z-1]-c[j]);
        y=c[i];
    }
    cout << ans;
}