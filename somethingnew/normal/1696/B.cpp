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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int pz = n, lz = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0)
            lz = i;
        if (a[i] != 0)
            pz = min(i, pz);
    }
    if (lz == 0 and pz == n) {
        cout << "0\n";return;
    }
    for (int i = pz; i <= lz; ++i) {
        if (a[i] == 0) {
            cout << "2\n";
            return;
        }
    }
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