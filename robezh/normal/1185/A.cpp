#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18;

ll a[3], d;
ll res = INF;

int main() {
    for(int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a + 3);

    cin >> d;
    for(int i = 0; i < 2; i++) {
        ll cur = 0;
        ll b1 = max(a[1], a[0] + d);
        ll b2 = max(a[2], b1 + d);
        res = min(res, abs(b1 - a[1]) + abs(b2 - a[2]));

        for(int j = 0; j < 3; j++) a[j] = (ll)1e9 - a[j];
        sort(a, a + 3);
    }

    res = min(res, 1LL * max(0LL, d - (a[1] - a[0])) + max(0LL, d - (a[2] - a[1])));
    cout << res << endl;
}