
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
    ll n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < m; ++i) cin >> b[i];
    ll q;
    cin >> q;
    for (ll i = 0; i < q; ++i){
        ll x;
        cin >> x;
        --x;
        cout << a[x % n] << b[x % m] << endl;
    }
    return 0;
}