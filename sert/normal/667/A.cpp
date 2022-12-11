#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 34;
typedef long double ld;
typedef long long ll;
const ld pi = atan2l(0, -1);
const ld eps = 1e-9;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ld d, h, v, e;
    cin >> d >> h >> v >> e;

    ld a = pi * d * d * 0.25 * e;
    if (a + eps > v) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout.precision(10);
    cout << fixed << pi * d * d * 0.25 * h / (v - a);


    return 0;
}