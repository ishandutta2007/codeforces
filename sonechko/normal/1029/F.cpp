#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b;
    cin>>a>>b;
    vector<pair<ll,ll> > v1,v2;
    for (ll j=1; j<=(ll)sqrt(a); j++)
        if (a%j==0) v1.pb(mp(j,a/j));
    for (ll j=1; j<=(ll)sqrt(b); j++)
        if (b%j==0) v2.pb(mp(j,b/j));
    int p1=-1,p2=-1;
    ll ans=2e18;
    for (ll j=1; j<=(ll)sqrt(a+b); j++)
        if ((a+b)%j==0)
    {
        ll l=j;
        ll r=(a+b)/j;
        if (ans<l+r) continue;
        while (p1+1<v1.size()&&v1[p1+1].ff<=l)
            p1++;
        while (p2+1<v2.size()&&v2[p2+1].ff<=l)
            p2++;
        int c=0;
        if (p1!=-1&&v1[p1].ss<=r) c=1;
        if (p2!=-1&&v2[p2].ss<=r) c=1;
        if (c==1) ans=l+r;
    }
    cout<<ans*2ll<<"\n";
}