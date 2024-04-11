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
void solve() {
    string x;
    cin >> x;
    if (x.size() == 2)
        cout << x[1] << '\n';
    else {
        char mn = x[0];
        for (int i = 0; i < x.size(); ++i) {
            mn = min(mn, x[i]);
        }
        cout << mn << '\n';
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