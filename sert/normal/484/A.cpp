#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll l, r, t, x, p;

ll bc(ll x) {
    return (x ? bc(x / 2) + x % 2 : 0);
}

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> t;
    while (t --> 0) {
        cin >> l >> r;
        if (l == r) {
            cout << l << "\n";
            continue;
        }
        p = 61;
        while (true) {
            if ((l & (1ll << p)) != (r & (1ll << p)))
                break;
            p--;
        }
        l >>= p;
        l <<= p;
        l |= (1ll << p) - 1ll;
        if (bc(r) > bc(l))
            l = r;
        cout << l << "\n";
    }
    //return 0;
}