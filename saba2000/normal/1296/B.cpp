#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        ll s;
        cin >> s;
        ll ans  =0;
        while(s >= 10){
            ans += (s -s%10);
            s -= (s - s% 10) - s/10;
        }
        cout<<ans+s<<endl;
    }
}