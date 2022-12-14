#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll ans=n;
    for (ll i=2;i*i<=n;i++) {
        if (n%i==0) {
            ans=__gcd(ans,i),ans=__gcd(ans,n/i);
        }
    }
    if (ans==0)ans=n;
    cout<<ans<<endl;
}