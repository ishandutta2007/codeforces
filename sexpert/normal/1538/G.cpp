#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b, x, y;
    cin >> x >> y >> a >> b;
    if(a > b) {
        swap(a, b);
        swap(x, y);
    }
    ll d = b - a;
    auto chk = [&](int steps) -> bool {
        ll x0 = x - steps * a, y0 = y - steps * a;
        if(x0 < 0 || y0 < 0)
            return false;
        if(d == 0)
            return true;
        return (x0 / d + y0 / d) >= steps;
    };

    ll lo = 0, hi = 1e9;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(chk(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}