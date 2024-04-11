#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        ll a, b, x, y, n;cin >> a >> b >> x >> y >> n;
        ll ans = LONG_LONG_MAX;
        ll cur = n;
        ll ac = a, bc = b;
        if(cur > ac-x){
            cur -= (ac-x);
            ac = x;
        }
        else{
            ac -=cur;
            cur = 0;
        }
        bc = max(bc-cur,y);
        ans = ac*bc;
        cur = n;
        ac = a, bc = b;
        if(cur > bc-y){
            cur -= (bc-y);
            bc = y;
        }
        else{
            bc -=cur;
            cur = 0;
        }
        ac = max(ac-cur,x);
        ans = min(ac*bc,ans);
        cout << ans << "\n";
        
        
        
    }
}