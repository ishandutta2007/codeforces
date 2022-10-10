#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll better(ll p, ll q, ll k, ll l) {
    return abs(k*l*p - l*q) < abs(k*l*p - k*q);
}

void solve() {
    ll h, c, t;
    cin >> h >> c >> t;
    t *= 2;
    if(t <= c + h) {
        cout << "2\n";
        return;
    }
    ll p = t - c - h, q = h - c;
    ll bstk = 1;
    ll tk = q / p;
    for(ll k = max(1LL, tk - 10); k <= tk + 10; k++) {
        if((k % 2) && better(p, q, k, bstk))
            bstk = k;
    }
    cout << bstk << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}