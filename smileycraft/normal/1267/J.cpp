
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
    ll T;
    cin >> T;
    while (--T >= 0){
        ll n;
        cin >> n;
        vll v(n);
        for (ll i = 0; i < n; ++i){
            ll x;
            cin >> x;
            ++v[x - 1];
        }
        vector<bool> possible(n + 2, true);
        ll maxi = n + 1;
        for (ll x : v) if (x != 0){
            maxi = min(maxi, x + 1);
            for (ll k = 2; k <= x + 1; ++k){
                if (x % (k - 1) > x / (k - 1)) possible[k] = false;
            }
        }
        for (ll k = maxi; k >= 2; --k) if (possible[k]){
            ll total = 0;
            for (ll x : v) if (x != 0){
                ll q = x / (k - 1), r = x % (k - 1);
                while (q - 1 >= r + k - 1){
                    --q;
                    r += k - 1;
                }
                total += q;
            }
            cout << total << endl;
            break;
        }
    }
    return 0;
}