#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;
const int MOD = 1e9 + 7;

#define mod %MOD

ll step(ll d)
{
    if (d==0) return 1;
    if (d%2==1) return (step(d-1)*2ll)mod;
    ll c=step(d/2);
    return (c*c)mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x,k;
    cin>>x>>k;
    if (x==0) cout<<0<<endl; else
    {
        x%=MOD;
        ll ans=step(k+1)*x-step(k)+1;
        ans+=MOD;
        ans%=MOD;
        cout<<ans<<endl;
    }
}


/// 992 C