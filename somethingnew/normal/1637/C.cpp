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
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;
    int res = 0;
    bool ok = 1;
    bool ok2 = 0;
    bool ok3 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i != 0 and i != n - 1) {
            if (x >= 2)
                ok3 = 1;
            if (x != 0)
                ok2 = 1;
            if (n == 3 and x % 2 == 1)
                ok = 0;
            res += (x + 1) / 2;
        }
    }
    if (ok == 0 or (ok2 == 1 and ok3 != 1)) {
        cout << "-1\n";
        return;
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}