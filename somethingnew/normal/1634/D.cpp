#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"

using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
int zpr(int a, int b, int c) {
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    int x;
    cin >> x;
    return x;
}
int zpr(array<int, 3> x) {
    return zpr(x[0], x[1], x[2]);
}
void solve() {
    array<int, 3> res = {0, 1, 2};
    int n;
    cin >> n;
    int valres = zpr(res);
    for (int i = 3; i < n; ++i) {
        auto res2 = res, res3 = res;
        res2[0] = i;
        res3[1] = i;
        int vl2 = zpr(res2), vl3 = zpr(res3);
        if (vl2 > valres) {
            res = res2;
            valres = vl2;
        }
        if (vl3 > valres) {
            res = res3;
            valres = vl3;
        }
    }
    int t = 0;
    while (t == res[0] or res[1] == t or res[2] == t)
        t++;
    for (int i = 0; i < 3; ++i) {
        auto res2 = res;
        res2[i] = t;
        if (zpr(res2) == valres) {
            cout << "! ";
            for (auto q : res2)
                if (q != t)
                    cout << q + 1 << ' ';
            cout << endl;
            return;
        }
    }
    exit(1);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}