#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 34;
const ll INF = 1e9;

ll c, ha, hb, wa, wb, w, h, cc, ans;

int main() {

    srand(3431);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> c >> ha >> hb >> wa >> wb;

    if (wa < wb) {
        swap(wa, wb);
        swap(ha, hb);
    }

    if (wa > 30000) {
        for (ll i = 0; i < 40000; i++) {
            h = ha * i;
            w = wa * i;
            if (w > c) continue;
            h += hb * ((c - w) / wb);
            ans = max(ans, h);
        }
        cout << ans;
        return 0;
    }

    if (ha * wb < hb * wa) {
        swap(wa, wb);
        swap(ha, hb);
    }

    for (int i = 0; i < 40000; i++) {
        h = hb * i;
        w = wb * i;
        if (w > c) continue;
        h += ha * ((c - w) / wa);
        ans = max(ans, h);
    }
    cout << ans;
    //while(true);
}