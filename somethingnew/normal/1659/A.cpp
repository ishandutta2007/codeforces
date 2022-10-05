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
    int n, r, b;
    cin >> n >> r >> b;
    while (r != 0) {
        for (int i = 0; i < r / (b + 1); ++i) {
            cout << "R";
        }
        r -= r / (b + 1);
        if (b != 0) {
            b--;
            cout << "B";
        }
    }
    cout << '\n';
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