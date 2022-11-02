
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
        ll n, d;
        cin >> n >> d;
        ll total;
        cin >> total;
        for (ll i = 1; i < n; ++i){
            ll x;
            cin >> x;
            if (i <= d && x != 0){
                ll c = min<ll>(d / i, x);
                total += c;
                d -= c * i;
            }
        }
        cout << total << endl;
    }
    return 0;
}