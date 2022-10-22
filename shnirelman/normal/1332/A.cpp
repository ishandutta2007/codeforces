#include <bits/stdc++.h>

using namespace std;
using li = long long;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    x -= a - b;
    y -= c - d;

    bool ans = x1 <= x && x <= x2 && y1 <= y && y <= y2;

    if(x1 == x2 && a > 0)
        ans = false;

    if(y1 == y2 && c > 0)
        ans = false;

    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}