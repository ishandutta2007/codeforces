#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000 + 11;



int main()
{
    ll n,k,M,D;
    cin>>n>>k>>M>>D;
    ll ans=0;
    for (ll i=0; i<D; i++)
    {
        ll x=min(M,n/(k*i+1));
        if (x==0) break;
        ll p = 0;
        ll c=k*(i+1);
        if ((n-x)/x<c-5) p=1;
        if ((n-x)/x<c+5) p=2;
        if (p==2) ans=max(ans,x*(i+1));
        if (p==1&&n-x<x*k*(i+1)) ans=max(ans,x*(i+1));
    }
    cout<<ans<<endl;
}