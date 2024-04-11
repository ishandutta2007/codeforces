#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll l,r;
    cin>>l>>r;
    ll g=0,ans=0;
    for (ll i=61; i>=0; i--)
        {
            ll p1=l&(1LL<<i);
            ll p2=r&(1LL<<i);
            if (p1>0) p1=1;
            if (p2>0) p2=1;
            if (p1!=p2) g=1;
            if (g==1) ans+=(1LL<<i);
        }
    cout<<ans<<endl;
}