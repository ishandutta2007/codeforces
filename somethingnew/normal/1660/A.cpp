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
#include "queue"
#define all(x) x.begin(), x.end()
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
        cout << "1\n";
        return;
    }
    cout << a + b * 2 + 1 << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
/*

 */