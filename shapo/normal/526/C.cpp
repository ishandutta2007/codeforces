#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;

int
main()
{
    ll c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;
    ll ans = 0ll;
    if (wr * wr >= c) {
        for (ll a = 0ll; a * wr <= c; ++a) {
            ll b = (c - a * wr) / wb;
            ans = max(ans, a * hr + b * hb);
        }
    } else if (wb * wb >= c) {
        for (ll b = 0ll; b * wb <= c; ++b) {
            ll a = (c - b * wb) / wr;
            ans = max(ans, a * hr + b * hb);
        }
    } else {
        if (wb * hr > hb * wr) {
            swap(wb, wr);
            swap(hb, hr);
        }
        for (ll a = 0ll; a <= wb; ++a) {
            ll b = (c - a * wr) / wb;
            ans = max(ans, a * hr + b * hb);
        }
    }
    cout << ans << endl;
    return 0;
}