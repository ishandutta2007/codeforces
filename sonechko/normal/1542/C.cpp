#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;


ll countt(ll n, ll x)
{
    ll p=1;
    for (ll j=1; j<x; j++)
        p=(p*1ll*j)/__gcd(p,j);
    ll p2=(p*1ll*x)/__gcd(p,x);
    ll c1=n/p-n/p2;
    return c1;
}

void up()
{
    ll n;
    cin>>n;
    ll ans=0;
    for (int j=2; j<=42; j++)
        ans=(ans+countt(n,j)*1ll*j)%1000000007;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
        up();
}
/**
2 3 5 7 11 13 17 19 23 29 31 37 41
**/