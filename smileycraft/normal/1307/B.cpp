
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll T;
    cin >> T;
    while (--T >= 0){
        ll n, x;
        cin >> n >> x;
        ll maxi = 0;
        bool hit = false;
        for (ll i = 0; i < n; ++i){
            ll a;
            cin >> a;
            maxi = max(maxi, a);
            if (a == x) hit = true;
        }
        if (hit) cout << 1 << endl;
        else cout << max<ll>(2, (x - 1) / maxi + 1) << endl;
    }
    return 0;
}