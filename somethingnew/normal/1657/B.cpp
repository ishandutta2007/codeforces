#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
void solve() {
    int n, B, x, y;
    cin >> n >> B >> x >> y;
    int res = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (res + x > B)
            res -= y;
        else
            res += x;
        ans += res;
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}