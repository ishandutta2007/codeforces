#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

set <ll> s;
ll l, r, x, n;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> l >> r;
    for (ll n = 2; n <= 61; n++)
        for (ll m = 0; m < n - 1; m++) {
            x = ((1ll) << (n)) - 1 - ((1ll) << (m));
            if (l <= x && x <= r) {
                s.insert(x);
                //cerr << x << "\n";
            }
        }
    cout << s.size();

    return 0;
}