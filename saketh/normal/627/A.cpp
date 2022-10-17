#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll S, X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> S >> X;

    vector<ll> avail;

    int ones = 0;

    for (int i = 0; i < 50; i++) {
        if (X&1) {
            ones++;
            S -= (1ll << i);
        } else {
            avail.push_back(1ll << (i + 1));
        }
        
        X >>= 1;
    }

    reverse(avail.begin(), avail.end());

    bool used = false;

    for (ll pos : avail) {
        if (S >= pos) {
            S -= pos;
            used = true;
        }
    }

    if (S == 0) {
        if (!used) cout << ((1ll << ones) - 2) << "\n";
        else cout << (1ll << ones) << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}