#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#define int long long
using namespace std;

void solve() {
    int n, m, st1, st2, fn1, fn2;
    int res = 1e9;
    cin >> n >> m >> st1 >> st2 >> fn1 >> fn2;
    if (st1 <= fn1) {
        res = min(res, fn1 - st1);
    } else {
        res = min(res, 2 * n - fn1 - st1);
    }
    n = m;st1 = st2;fn1 = fn2;
    if (st1 <= fn1) {
        res = min(res, fn1 - st1);
    } else {
        res = min(res, 2 * n - fn1 - st1);
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}