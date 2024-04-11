#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    ll p[62];
    for(ll i = 0; i < 60; i++) p[i] = (1ll << i);
    for(int c = 0; c < t; c++){
        ll n, m;
        cin >> n >> m;
        ll a[100002];
        ll b[62]{0};
        ll s = 0;
        for(ll i = 0; i < m; i++){
            cin >> a[i];
            s += a[i];
            b[lower_bound(p, p + 60, a[i]) - p]++;
        }
        if(s < n){
            cout << -1 << endl;
            continue;
        }
        ll ans = 0;
        for(ll i = 0; i < 60; i++){
            if((n >> i) & 1){
                for(ll j = i; j < 60; j++){
                    if(b[j]){
                        ans += j - i;
                        for(ll k = i; k < j; k++) b[k]++;
                        b[j]--;
                        break;
                    }
                }
            }
            b[i + 1] += b[i] / 2;
        }
        cout << ans << endl;
    }
}