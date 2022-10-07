#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(i % 2 == 1) cout<< (1ll << (i + j)) <<" ";
            else cout << 0 <<" ";
        }
        cout<<endl;
    }
    ll q;
    cin >> q;
    while(q--){
        long long k;
        cin >> k;
        cout<<1<<" "<<1<<endl;
        ll x = 0, y = 0;
        while(x < n-1 || y < n-1){
            ll u = (x+y+1);
            if((1ll<<u) & k){
                if(x % 2 == 1) y++;
                else x++;
            }
            else{
                if(x % 2 == 1)x++;
                else y++;
            }
            cout<<x+1<<" "<<y+1<<endl;
        }

    }


}