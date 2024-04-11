#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for (ll x = a; x <= b; ++x) {
        ll miny = c + 1 - x;
        ll minyv = 1;
        if (miny < b) {
            minyv += (b - miny);
            miny = b;
        }
        ll maxy = d + 1 - x;
        ll maxyv = (d - c + 1);
        if (maxy > c) {
            maxyv -= (maxy - c);
            maxy = c;
        } else if (maxy < b) {
            maxy = b;
            minyv = maxyv;
        }
        //cout << x << ": " << (maxy - miny + 1) * (minyv + maxyv) / 2 << "+" << (c - maxy) * (d - c + 1) << "\n";
        ans += (maxy - miny + 1) * (minyv + maxyv) / 2;
        ans += (c - maxy) * (d - c + 1);
    }
    cout << ans << "\n";
    return 0;
}