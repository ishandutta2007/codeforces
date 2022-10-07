#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100009];
void solve(){
    int n;
    scanf("%d", &n);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    ll ok = 1;
    for(ll i = 1; i <= n- 1; i++){
        if(a[i] > a[i+1]){
            ok = 0;
        }
    }
    if(ok){
        cout << 0 << endl;
        return;
    }
    for(ll x = 0; x <= 40; x++){
        ll M = (1 << (x+1))-1;
        ll ok = 1, last = a[1];
        for(ll i = 2; i <= n; i++){
            if(a[i] >= last) {last = a[i]; continue;}
            if(last - a[i] > M) {
                ok = 0;
                break;
            }
        }
        if(!ok)continue;
        cout <<x+1<<endl;
        return;
    }
}
main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }


}