#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;

ll n,m,k;
ll d(ll p)
{
    ll kol=0;
    for (ll i=1; i<=n; i++)
    {
        kol+=min(m,p/i);
    }
    return kol;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    ll l=1,r=n*m;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        if (d(mid)<k) l=mid; else r=mid;
    }
    if (d(l)>=k) cout<<l<<endl;
    else cout<<r<<endl;
}