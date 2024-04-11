#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll tot =  n*k;
    ll a,b;
    cin>>a>>b;
    vector<ll>pos;
    pos.push_back(((b-a)%k+k)%k);
    pos.push_back((k-pos.back())%k);
    b = (k-b)%k;
    pos.push_back(((b-a)%k+k)%k);
    pos.push_back((k-pos.back())%k);
    ll x = 1e18,y=0;
    for (auto o:pos){
        for (ll t=1;t<=3*n;t++) {
            ll cur = __gcd(tot,t*k+o);
            x=min(x,tot/cur);
            y=max(y,tot/cur);
        }
    }
    cout<<x<<' '<<y<<endl;
}