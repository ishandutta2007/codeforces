#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;
const ld EPS = 1e-4;

struct pt {
    ld x, y;
    pt() {}
    pt(ld xx, ld yy) {
        x = xx;
        y = yy;
    }
    pt operator - (const pt &a) const {
        return pt(x - a.x, y - a.y);
    }
    ld ang() const {
        return atan2l(y, x);
    }
    ld len() const {
        return sqrtl(x * x + y * y);
    }
};

ld y[10];
pt a[10];
ld yy;
int x, k[10];
ld aa, bb, cc, R, S, pp;

int main() {
    //freopen("a.in", "r", stdin);//freopen("input.txt", "r", stdin);
    //freopen("a.out", "w", stdout);//freopen("output.txt", "w", stdout);
    cout.precision(10);
    for (int i = 0; i < 3; i++)
        cin >> a[i].x >> a[i].y;
    a[3] = a[0];
    a[4] = a[1];

    aa = (a[0] - a[1]).len();
    bb = (a[1] - a[2]).len();
    cc = (a[2] - a[0]).len();
    pp = (aa + bb + cc) * 0.5;
    S = sqrtl(pp) * sqrtl(pp - aa) * sqrtl(pp - bb) * sqrtl(pp - cc);
    R = aa * bb * cc * 0.25 / S;
    //cout << R << "\n";

    for (int i = 0; i < 3; i++) {
        y[i] = fabsl((a[i] - a[i + 1]).ang() - (a[i] - a[i + 2]).ang()) * 180.0 / atan2l(0, -1);
        //cout << fixed << y[i] << "\n";
    }
    bool fail;
    for (int i = 3; true; i++) {
        yy = 180.0 / (i + 0.0);
        fail = false;
        for (int j = 0; j < 3; j++) {
            x = (y[j] / yy + 0.5);
            //cerr << yy * (x + 0.0) - y[j] << " " << fabsl(yy * (x + 0.0) - y[j]) << "\n";
            if (fabsl(yy * (x + 0.0) - y[j]) > EPS)
                fail = true;
            k[j] = x;
        }
        if (!fail) {
            //cerr << i << "\n";
            cout << fixed << 0.5 * i * R * R * sinl(2.0 * atan2l(0, -1) / (i + 0.0));
            return 0;
        }
    }



    return 0;
}