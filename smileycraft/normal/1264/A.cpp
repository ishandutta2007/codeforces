
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
    ll t;
    cin >> t;
    while (--t >= 0){
        ll n;
        cin >> n;
        vll v(n);
        for (ll i = 0; i < n; ++i) cin >> v[i];
        ll g = 1;
        while (g < n && v[g - 1] == v[g]) ++g;
        ll s = g + 1;
        while (g + s < n && v[s + g - 1] == v[s + g]) ++s;
        ll b = g + 1;
        while (g + s + b < n && v[s + g + b - 1] == v[s + g + b]) ++b;
        if (2 * (g + s + b) > n){
            cout << "0 0 0" << endl;
            continue;
        }
        for (ll nb = b + 1; 2 * (g + s + nb) <= n; ++nb) if (v[s + g + nb - 1] != v[s + g + nb]) b = nb;
        cout << g << ' ' << s << ' ' << b << endl;
    }
    return 0;
}