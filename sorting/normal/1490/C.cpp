#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get_sqrt_3(ll x){
    ll ans = pow(x, (double)0.333333);
    while(ans * ans * ans > x) --ans;
    while((ans + 1) * (ans + 1) * (ans + 1) <= x) ++ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll x;
        cin >> x;

        bool ok = false;
        for(ll i = 1; i * i * i <= x; ++i){
            ll t = x - i * i * i;
            if(!t) continue;
            ll sq = get_sqrt_3(t);
            if(sq * sq * sq == t){
                ok = true;
                break;
            } 
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}