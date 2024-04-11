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
int zpr(int l, int r) {
    if (l > r)
        return 0;
    cout << "? " << l << ' ' << r << endl;
    vector<int> a(r - l + 1);
    int res = 0;
    for (int i = 0; i < r - l + 1; ++i) {
        cin >> a[i];
        if (l <= a[i] and a[i] <= r)
            res += 1;
    }
    return res % 2;
}
void solve() {
    int n;
    cin >> n;
    int l = 1, r = n + 1;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (zpr(l, m - 1))
            r = m;
        else
            l = m;
    }
    cout << "! " << l << endl;
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