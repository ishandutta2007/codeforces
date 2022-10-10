#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll mpow(ll b, ll e, ll m = MOD) {
    if(e == 0)
        return 1;
    if(e % 2)
        return (b * mpow(b, e - 1, m)) % m;
    ll p = mpow(b, e/2, m);
    return (p * p) % m;
}

int main() {
    ll p, k;
    cin >> p >> k;
    if(k == 0) {
        cout << mpow(p, p - 1) << endl;
        return 0;
    }
    if(k == 1) {
        cout << mpow(p, p) << endl;
        return 0;
    }
    vector<ll> divs;
    for(ll d = 1; d * d <= p - 1; d++) {
        if((p - 1) % d)
            continue;
        divs.push_back(d);
        divs.push_back((p - 1) / d);
    }
    sort(divs.begin(), divs.end());
    ll ord;
    for(auto d : divs) {
        if(mpow(k, d, p) == 1) {
            ord = d;
            break;
        }
    }
    cout << mpow(p, (p - 1)/ord) << endl;
}