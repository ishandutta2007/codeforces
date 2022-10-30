
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
        ll n;
        cin >> n;
        vll v(n);
        for (ll i = 0; i < n; ++i) cin >> v[i];
        ll value = v.back(), prev_value = 0, index = n - 1;
        bool yes = true;
        while (true){
            for (ll i = 0; i + 1 < value - prev_value; ++i) yes = yes && (v[index - i] == v[index - (i + 1)] + 1);
            if (!yes) break;
            index -= value - prev_value;
            if (index < 0) break;
            prev_value = value;
            value = v[index];
        }
        cout << (yes ? "Yes" : "No") << endl;
    }
    return 0;
}