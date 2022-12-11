#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x1, y1, x2, y2;
    ll x, y;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && (a + b) > 0) {
        cout << "NO" << endl;
        return;
    }
    if (y1 == y2 && (c + d) > 0) {
        cout << "NO" << endl;
        return;
    }
    if (x - a + b < x1 || x - a + b > x2) {
        cout << "NO" << endl;
        return;
    }
    if (y - c + d < y1 || y - c + d > y2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t) {
        --t;
        solve();
    }
    return 0;
}