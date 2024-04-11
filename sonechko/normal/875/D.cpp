#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ss second
#define ff first
#define mp make_pair
const ll N = 2e5 + 11;
ll dp1[N][30],dp2[N][30],a[N];
map<ll,ll> mt;
int  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
     ll ans=n*(n+1)/2;
    for (ll i=1; i<=n; i++)
    cin>>a[i];
    for (ll i=1; i<=n; i++)
    {
        ll k=1;
        for (ll j=0; j<30; j++)
        {
            if ((a[i]&k)>0) dp1[i][j]=i;
            else dp1[i][j]=dp1[i-1][j];
            k*=2;
        }
    }
    for (ll j=0; j<30; j++)
        dp2[n+1][j]=n+1;
    for (ll i=n; i>=1; i--)
    {
        ll k=1;
        for (ll j=0; j<30; j++)
        {
            if ((a[i]&k)>0) dp2[i][j]=i;
            else dp2[i][j]=dp2[i+1][j];
            k*=2;
        }
    }
    for (ll i=1; i<=n; i++)
    {
        ll x=mt[a[i]];
        ll l=x,r=n+1;
        for (ll j=0; j<30; j++)
            if (dp1[i][j]!=i)
        {
            l=max(l,dp1[i-1][j]);
            r=min(r,dp2[i+1][j]);
        }
        l++;
        r--;

        ans-=1LL*(i-l+1)*1LL*(r-i+1);
        mt[a[i]]=i;
    }
    cout<<ans<<endl;
}