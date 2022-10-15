#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

#define ll long long

ll shift[70];
int q;

ll log_2(ll val) {
    for (int i = 1; i <= 62; i++) {
        if ((1ll << (ll)i) > val) return i-1;
    }
    return 0;
}

ll val2pos(ll val)
{
    ll below_bits = val - (1ll << (ll)log_2(val));
    below_bits += shift[log_2(val)];
    below_bits %= (1ll << (ll)log_2(val));
    return (1ll << (ll)log_2(val)) + below_bits;
}

ll pos2val(ll pos)
{
    ll below_bits = pos - (1ll << (ll)log_2(pos));
    below_bits -= shift[log_2(pos)];
    below_bits %= (1ll << (ll)log_2(pos));
    below_bits += (1ll << (ll)log_2(pos));
    below_bits %= (1ll << (ll)log_2(pos));
    return (1ll << (ll)log_2(pos)) + below_bits;
}

int main()
{
    //for (int i = 1; i <= 20; i++) cout << log_2(i) << ' ';
    ios::sync_with_stdio(false);
    cin >> q;
    for (int qry = 1; qry <= q; qry++) {
        int op;
        cin >> op;
        if (op == 1) {
            ll x, k;
            cin >> x >> k;
            x = log_2(x);
            shift[x] += k;
            shift[x] %= (1ll << x);
            shift[x] += (1ll << x);
            shift[x] %= (1ll << x);
        } else if (op == 2) {
            ll x, k;
            cin >> x >> k;
            x = log_2(x);
            for (; x <= 62; x++) {
                shift[x] += k;
                shift[x] %= (1ll << x);
                shift[x] += (1ll << x);
                shift[x] %= (1ll << x);
                k *= 2;
            }
        } else {
            ll x;
            cin >> x;
            x = val2pos(x);
            while (1) {
                cout << pos2val(x) << ' ';
                if (x == 1) break;
                x /= 2;
            }
            cout << endl;
        }
    }
    return 0;
}