#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        ll a,b;
        cin>>a>>b;
        ll ans = 1e9;
        for (ll x=max(2LL, b);x<=b+50;x++) {
            ll ret = x-b;
            ll A = a;
            while(A) A/=x, ret++;
            ans=min(ans, ret);
        }
        cout<<ans<<endl;
    }
}