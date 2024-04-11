#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1e6 + 11;
const ll MOD = 1e18;
#define mod %MOD

ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x,y,l,r;
    cin>>x>>y>>l>>r;
    vector<ll> v;
    ll k=1,kk=1;
    for (int i=0; i<=60; i++)
    {
        a[i]=k;
        b[i]=kk;
        if (k!=-1&&r/k>=x&&k*x<=r) k*=x; else k=-1;
        if (kk!=-1&&r/kk>=y&&kk*y<=r) kk*=y; else kk=-1;
    }
    for (int i=0; i<=60; i++)
    for (int j=0; j<=60; j++)
    if (a[i]!=-1&&b[j]!=-1)
    {
        ll dd=a[i]+b[j];
        if (dd>=l&&dd<=r) v.pb(dd);
    }
    v.pb(l-1);
    v.pb(r+1);
    sort(v.begin(),v.end());
    ll ans=0;
    for (int i=1; i<v.size(); i++)
        ans=max(ans,v[i]-v[i-1]-1);
    cout<<ans<<endl;
}