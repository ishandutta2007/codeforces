#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 && (a + b > 0)) {
        cout << "No\n";
        return;
    }
    if(y1 == y2 && (c + d > 0)) {
        cout << "No\n";
        return;
    }
    int nx = x - a + b;
    int ny = y - c + d;
    if(nx < x1 || nx > x2 || ny < y1 || ny > y2) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}