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
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        int x;
        cin >> x;
        res += x;
    }
    if (res == 0)
        cout << "0\n";
    else if (res == 4)
        cout << "2\n";
    else
        cout << "1\n";
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