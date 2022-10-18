#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const ll N = 1e6 + 11;

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    vector<pair<ll,ll> > vv;
    for (ll i=1; i<=n; i++)
    {
        ll l;
        cin>>l;
        ll d=floor(sqrt(l));
        if (d*d==l) vv.pb(mp(0,-(1+(l==0)))); else
        {
            ll x=d*d;
            ll z=(d+1)*(d+1);
            if (l-x<z-l) vv.pb(mp(l-x,0)); else
                vv.pb(mp(z-l,0));
        }
    }
    sort(vv.begin(),vv.end());
    ll ans=0;
    for (ll j=0; j<n/2; j++)
        ans+=vv[j].ff;
    for (ll j=n/2; j<vv.size(); j++)
        ans+=abs(vv[j].ss);
    cout<<ans<<endl;
}