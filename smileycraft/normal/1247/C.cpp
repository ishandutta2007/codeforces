
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

ll bit_count(ll x){
    ll c = 0;
    while (x > 0){
        c += x & 1;
        x >>= 1;
    }
    return c;
}

int main(){
    ll n, p;
    cin >> n >> p;
    for (ll i = 0; i < 40 && i <= n; ++i){
        if (bit_count(n) <= i){
            cout << i << endl;
            return 0;
        }
        n -= p;
    }
    cout << -1 << endl;
    return 0;
}