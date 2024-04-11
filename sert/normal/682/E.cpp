#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5432;
typedef long double ld;

struct pt {
    ll x, y;
    pt() {}
    pt(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    pt operator - (const pt &a) {
        return pt(x - a.x, y - a.y);
    }

    pt operator + (const pt &a) {
        return pt(x + a.x, y + a.y);
    }

    ll operator * (const pt &a) {
        return x * a.y - y * a.x;
    }
};

pt a[N];
pt b, c, d;
bool upd = true;
ll n, s;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    srand(3431);
    random_shuffle(a, a + n);

    b = a[0];
    c = a[1];
    d = a[2];

    while (upd) {
        upd = false;

        for (int i = 0; i < n; i++) {
            if ((c - d) * (a[i] - b) > 0) {
                b = a[i];
                upd = true;
            }

            if ((d - b) * (a[i] - c) > 0) {
                c = a[i];
                upd = true;
            }

            if ((b - c) * (a[i] - d) > 0) {
                d = a[i];
                upd = true;
            }
        }
    }

    pt bb, cc, dd;
    bb = b + c - d;
    cc = d + b - c;
    dd = c + d - b;

    cout << bb.x << " " << bb.y << "\n";
    cout << cc.x << " " << cc.y << "\n";
    cout << dd.x << " " << dd.y << "\n";

    return 0;
}