
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
        ll d, m;
        cin >> d >> m;
        ll total = 1;
        for (ll p2 = 1; ; p2 *= 2){
            if (2 * p2 > d){
                total = (total * (d - p2 + 2)) % m;
                break;
            }
            total = (total * (p2 + 1)) % m;
        }
        cout << (total + m - 1) % m << endl;
    }
    return 0;
}