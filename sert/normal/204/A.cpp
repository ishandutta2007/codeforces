#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sump(ll x) {
    if (x < 10)
        return x;
    if (x < 100)
        return 9 + x / 11;
    ll ans = 18;
    ll l, m, r;
    ll st = 1;
    for (ll c = 1; c < 10; c++) {
        st = 1;
        for (ll len = 0; len < 16; len++) {
            st *= 10;
            l = -1;
            r = st;
            while (r - l > 1) {
                m = (r + l) / 2;
                if (c * st * 10 + m * 10 + c <= x)
                    l = m;
                else
                    r = m;
            }
            //cerr << c << " " << len << " " << r << "\n";
            ans += r;
        }
    }
    return ans;
}

ll l, r;

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> l >> r;

    cout << sump(r) - sump(l - 1);

    //while(true);
}