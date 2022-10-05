#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define ld long double
ld ans;
void slv(ld c, ld m, ld p, ld v, ld ver, int glb) {
    if (ver * glb <= 1e-12) {
        ans += ver * glb;
        return;
    }
    if (c == -1 and m == -1) {
        ans += ver * glb;
        return;
    }
    ans += ver * glb * p;
    if (c == -1) {
        if (m - v <= 1e-12) {
            slv(c, -1, 1, v, ver * m, glb + 1);
        } else {
            slv(c, m - v, p + v, v, ver * m, glb + 1);
        }
        return;
    }
    swap(c, m);
    if (c == -1) {
        if (m - v <= 1e-12) {
            slv(c, -1, 1, v, ver * m, glb + 1);
        } else {
            slv(c, m - v, p + v, v, ver * m, glb + 1);
        }
        return;
    }
    if (m - v <= 1e-12) {
        ld k1 = m / 2;
        slv(c + k1, -1, p + k1, v, ver * m, glb + 1);
    } else {
        ld k2 = v / 2;
        slv(c + k2, m - v, p + k2, v, ver * m, glb + 1);
    }
    swap(c, m);
    if (m - v <= 1e-12) {
        ld k1 = m / 2;
        slv(c + k1, -1, p + k1, v, ver * m, glb + 1);
    } else {
        ld k2 = v / 2;
        slv(c + k2, m - v, p + k2, v, ver * m, glb + 1);
    }
}
void solve(){
    ans = 0;
    ld c, m, p, v;
    cin >> c >> m >> p >> v;
    slv(c, m, p, v, 1, 1);
    cout << setprecision(20) << ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}