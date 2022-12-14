#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,p;
    cin>>n>>p;
    for (ll x=1;x<=1e6;x++) {
        ll cur = x*p;
        ll need = n-cur;
        int bits = __builtin_popcount(need);
        if (bits<=x && need>=x){
            cout<<x<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}