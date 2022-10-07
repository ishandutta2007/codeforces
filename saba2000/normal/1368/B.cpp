#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
   ll n;
   cin >> n;
    ll lo =  1, hi = 500;
    while(lo < hi){
        ll mid = (lo + hi)/2;
        ll x = mid / 10, y = mid % 10;
        ll ans = 1;
        for(ll i = 0; i < 10- y; i++)
            ans  = ans * x;
        for(ll i = 0 ;i < y; i++)
            ans = ans * (x+1);
        if(ans >= n) hi = mid;
        else lo = mid+1;
    }
    string s = "codeforces";
    ll x = lo / 10, y = lo % 10;
    for(ll i = 0; i < 10-y; i++){
        for(ll j = 0; j < x; j++)
            cout<<s[i];
    }
    for(ll  i = 10-y; i < 10; i++)
        for(ll j = 0 ; j <= x; j++)
            cout<<s[i];
    cout<<endl;
}