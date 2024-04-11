#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ld eps = 1e-11;

struct pt {
    ld x, y;
};

ld len(const pt &a, const pt &b) {
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n;
pt a, b, t;
pt c[N];
ld ans;

ld d1[N], d2[N];

ld f1(int i) {
    return len(a, c[i]) - len(t, c[i]);
}

ld f2(int i) {
    return len(b, c[i]) - len(t, c[i]);
}

bool cmp1(int i1, int i2) {
    return f1(i1) + eps < f1(i2);
}

bool cmp2(int i1, int i2) {
    return f2(i1) + eps < f2(i2);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i].x >> c[i].y;
        ans += len(c[i], t) * 2;
        d1[i] = i;
        d2[i] = i;
    }

    sort(d1, d1 + n, cmp1);
    sort(d2, d2 + n, cmp2);

    ld df = min(f1(d1[0]), f2(d2[0]));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (d1[i] != d2[j] && f1(d1[i]) + f2(d2[j]) < df) {
                df = f1(d1[i]) + f2(d2[j]);
            }
        }
    }

    cout.precision(10);
    cout << fixed << ans + df;


    return 0;
}