//        
//   @roadfromroi 
//        
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
#define int long long
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = a * d;
    int y = b * c;
    if (y == 0 or x == 0) {
        cout << 1 - (x == y) << '\n';
    } else
        cout << 2 - (x % y == 0) - (y % x == 0) << '\n';
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