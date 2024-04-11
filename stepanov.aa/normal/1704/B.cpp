#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


#define ll long long


const ll inf = 1e18;


int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n);
        for(int i = 0; i < n; i += 1){
            cin >> a[i];
        }
        ll mx = -inf;
        ll mn = inf;
        int cnt = 0;
        for(int i = 0; i < n; i += 1){
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
            if(mx - mn > 2 * x){
                cnt += 1;
                mx = a[i];
                mn = a[i];
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}