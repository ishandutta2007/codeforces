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
#define int long long
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int mx = 1e9;
    // y = b
    // x = a + bn
    // z = (a + bn)m + c
    cout << a + b * mx << ' ' << b << ' ' << a + b * mx + c << '\n';
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