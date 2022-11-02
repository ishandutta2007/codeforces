
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

vll shows(200001), occs(1000001);

int main(){
    ll T;
    cin >> T;
    while (--T >= 0){
        ll n, k, d;
        cin >> n >> k >> d;
        for (ll i = 0; i < n; ++i){
            cin >> shows[i];
            --shows[i];
        }
        ll amount = 0, mini = 0;
        for (ll i = 0; i < d; ++i){
            ++occs[shows[i]];
            if (occs[shows[i]] == 1){
                ++amount;
            }
        }
        mini = amount;
        for (ll i = d; i < n; ++i){
            --occs[shows[i - d]];
            if (occs[shows[i - d]] == 0){
                --amount;
            }
            ++occs[shows[i]];
            if (occs[shows[i]] == 1){
                ++amount;
            }
            mini = min(mini, amount);
        }
        cout << mini << endl;
        for (ll i = 0; i < n; ++i){
            occs[shows[i]] = 0;
            shows[i] = 0;
        }
    }
    return 0;
}