#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll da = min(n, a - x);
        ll db = min(n - da, b - y);
        ll ans = (a-da) * (b-db);
        db = min(n, b - y);
        da = min(n - db, a - x);
        ans = min(ans, (a-da) * (b-db));
        cout << ans << '\n';
    }
    return 0;
}