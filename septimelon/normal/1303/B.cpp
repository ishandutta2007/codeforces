#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, g, b;
    cin >> n >> g >> b;
    ll ng = (n + 1) / 2;
    ll nb = n / 2;
    ll cng = ng / g;
    ll gl = ng % g;
    if (gl == 0) {
        --cng;
        gl = g;
    }
    ll cnb = nb / b;
    if (nb % b == 0) {
        --cnb;
    }
    ll cnt = n / (g + b);
    ll tl = n % (g + b);
    if (tl == 0) {
        --cnt;
        tl = (g + b);
    }
    ll mint;
    if (cng > cnb) {
        mint = cng * (g + b) + gl;
    } else {
        mint = n;
    }
    cout << mint << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}