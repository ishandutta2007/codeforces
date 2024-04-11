#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


#define ll long long


const ll inf = 2e18;


int32_t main(){
    if(1){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        ll mx = -inf;
        ll mn = inf;
        ll mxi = -1;
        for(int i = 1; i <= n; i += 1){
            ll x = 0;
            for(int j = 0; j < m; j += 1){
                ll a;
                cin >> a;
                x += a * j;
            }
            mn = min(mn, x);
            if(x > mx){
                mx = x;
                mxi = i;
            }
        }
        cout << mxi << " " << mx - mn << "\n";
    }
    return 0;
}