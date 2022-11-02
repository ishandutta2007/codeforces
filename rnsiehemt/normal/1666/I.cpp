#include <bits/stdc++.h>
using namespace std;

int dig(int y, int x) {
    int res;
    cout << "DIG " << y+1 << " " << x+1 << "\n";
    cin >> res;
    return res;
}

int scan(int y, int x) {
    int res;
    cout << "SCAN " << y+1 << " " << x+1 << "\n";
    cin >> res;
    return res;
}

void solve(int Y, int X) {
    int S0 = scan(0, 0);
    int S1 = scan(Y-1, 0);
    int xsum = (S0 + S1) / 2 - (Y-1);
    int ysum = (S0 - S1) / 2 + (Y-1);
    int xmid = xsum / 2;
    int ymid = ysum / 2;
    int S2 = scan(ymid, 0);
    int S3 = scan(0, xmid);
    int y2 = (S2 - xsum + ysum) / 2;
    int y1 = ysum - y2;
    int x2 = (S3 + xsum - ysum) / 2;
    int x1 = xsum - x2;
    if (dig(y1, x1)) {
        assert(dig(y2, x2));
    } else {
        assert(dig(y2, x1));
        assert(dig(y1, x2));
    }
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int Y, X;
        cin >> Y >> X;
        solve(Y, X);
    }
}