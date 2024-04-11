#include <bits/stdc++.h>

using namespace std;

void solve() {
    int xs, ys;
    cin >> xs >> ys;
    int xt, yt;
    cin >> xt >> yt;

    int xf, yf;
    cin >> xf >> yf;

    if (xs > xt) {
        swap(xs, xt);
    }
    if (ys > yt) {
        swap(ys, yt);
    }

    int d = abs(xs - xt) + abs(ys - yt);

    if (abs(xs - xt) > 0 && abs(ys - yt) > 0) {
        cout << d << "\n";
    } else if (xs <= xf && xf <= xt && ys <= yf && yf <= yt) {
        cout << d + 2 << "\n";
    } else {
        cout << d << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}