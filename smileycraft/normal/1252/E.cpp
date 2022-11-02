
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
    ll n;
    cin >> n;
    ll black = 0, white = 0;
    for (ll i = 0; i < n; ++i){
        ll x;
        cin >> x;
        black += (x + i % 2) / 2;
        white += (x + (i + 1) % 2) / 2;
    }
    cout << min(black, white) << endl;
    return 0;
}