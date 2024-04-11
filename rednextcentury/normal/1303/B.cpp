#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll g,b,n;
pair<ll,ll> getNum(ll x){
    ll good=0,bad=0;
    ll full = x / (b+g);
    good+=full*g;
    bad+=full*b;
    x%=(b+g);
    if (x<=g)good+=x,x=0;
    else good+=g,bad+=x-g;
    return {good,bad};
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>g>>b;
        ll ret=1e18;
        ll l=1, r = 1e18;
        while(l<=r){
            ll mid = (l+r)/2;
            auto p = getNum(mid);
            if (p.first>=(n/2+n%2) && p.first+p.second>=n)ret=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<ret<<endl;
    }
}