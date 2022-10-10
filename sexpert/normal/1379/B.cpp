#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll l, r, m;
    cin >> l >> r >> m;
    for(ll a = l; a <= r; a++) {
        ll rm = m % a;
        ll dis = min(rm, a - rm);
        if(dis <= r - l) {
            if(rm <= r - l && m > rm)
                cout << a << " " << l + rm << " " << l << '\n';
            else
                cout << a << " " << r - (a - rm) << " " << r << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}