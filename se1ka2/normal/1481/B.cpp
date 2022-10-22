#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[102];
        for(int i = 0; i < n; i++) cin >> a[i];
        while(true){
            ll r;
            for(r = 0; r < n - 1; r++){
                if(a[r] < a[r + 1]) break;
            }
            if(r == n - 1){
                cout << -1 << endl;
                break;
            }
            ll l;
            for(l = r; l >= 0; l--){
                if(a[l] > a[r]) break;
            }
            ll d = a[r + 1] - a[r];
            if(l >= 0) d = min(d, a[l] - a[r]);
            if((r - l) * d < k){
                for(int i = l + 1; i <= r; i++) a[i] += d;
                k -= (r - l) * d;
            }
            else{
                cout << r - (k - 1) % (r - l) + 1 << endl;
                break;
            }
        }
    }
}