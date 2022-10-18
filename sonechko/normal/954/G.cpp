#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 1e6 + 11;

ll a[N],n,k,r,b[N];

bool good(ll x)
{
    ll kol=0;
    for (int i=1; i<=n; i++)
        b[i]=0;
    ll sum=0;
    for (int d=1; d<=n; d++)
    {
        ll y=a[d]+sum;
        if (y<x)
        {
            ll h=x-y;
            sum+=h;
            kol+=h;
            b[d+r*2]+=h;
        }
        sum-=b[d];
        if (kol>k) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>r>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        int x=max(1ll,i-r);
        int y=min(n,i+r);
        b[x]+=a[i];
        b[y+1]-=a[i];
    }
    for (int i=1; i<=n; i++)
    {
        b[i]+=b[i-1];
        a[i]=b[i];
    }
    ll l=0,r=2e18;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        if (good(mid)) l=mid; else r=mid;
    }
    if (good(r)) cout<<r<<endl; else cout<<l<<endl;
}