#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >>t ;
    while(t--){
        ll a,b,q;
        cin>>a>>b>>q;
        if(a > b) swap(a,b);
        ll d = a / __gcd(a,b);
        while(q--){
            ll l, r;
            cin>> l>>r;
            if(l / b == r / b){
                if((l / b) % d){
                    cout<<r-l+1<<" ";
                }
                else cout<<0<<" ";
                continue;
            }
            ll ans = 0;
            if((l / b) % d == 0) ans += b - l % b;
            if((r / b) % d == 0) ans += r % b + 1;
            ll L = l/b+1, R = r/b-1;
            cout << (r- l +1) - ((R / d - (L - 1) / d) * b  + ans) << " ";
        }
        cout<<endl;
    }
}
/*
(x/b)*b


*/