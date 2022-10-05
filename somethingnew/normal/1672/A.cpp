#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res += x;
    }
    if ((res - n) % 2 == 0) {
        cout << "maomao90\n";
    } else {
        cout << "errorgorn\n";
    }
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