#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>

using namespace std;

typedef int64_t ll;

ll ask(ll c, ll d) {
    cout << "? " << c << " " << d << endl;
    ll ans;
    cin >> ans;
    return ans;
}

int main() {
    ll a = 0;
    ll b = 0;
    ll need = ask(0, 0);
    for (ll i = 29; i >= 0; --i) {
        if (need == 1) {
            ll lol = ask(a | (1 << i), b | (1 << i));
            if (lol == 1) {
                ll kek = ask(a, b | (1 << i));
                if (kek == 1) {
                    a |= 1 << i;
                    b |= 1 << i;
                }
            }
            if (lol == -1) {
                a |= (1 << i);
                need = ask(a, b);
            }
            continue;
        }
        if (need == 0) {
            ll kek = ask(a | (1 << i), b);
            if (kek == -1) {
                a |= (1 << i);
                b |= (1 << i);
            }
            continue;
        }
        if (need == -1) {
            ll lol = ask(a | (1 << i), b | (1 << i));
            if (lol == -1) {
                ll kek = ask(a, b | (1 << i));
                if (kek == 1) {
                    a |= 1 << i;
                    b |= 1 << i;
                }
            }
            if (lol == 1) {
                b |= (1 << i);
                need = ask(a, b);
            }
            continue;
        }
    }
    cout << "! " << a << " " << b << endl;
    return 0;
}