#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
const int N = 5e6 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD
ll c[N];
ll ggg(ll l)
{
    return (l*(l-1)/2)mod;
}
ll d[N];
ll get(ll l)
{
    if (l==1) return 0;
    if (d[l]!=0) return d[l];
    ll j=c[l];
    ll ps=(get(l/j)+ggg(j)*l/j)mod;
    d[l]=ps;
    return ps;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t,l,r;
    cin>>t>>l>>r;
    for (ll i=2; i<=r; i++)
        if (c[i]==0)
    {
        c[i]=i;
        if (i<=3e3)
        {
            for (ll j=i*i; j<=r; j+=i)
            if (c[j]==0) c[j]=i;
        }
    }
    ll d=1;
    ll ans=0;
    for (ll i=l; i<=r; i++)
    {
        ans=(ans+d*get(i))mod;
        d=(d*t)mod;
    }
    cout<<ans<<endl;
}