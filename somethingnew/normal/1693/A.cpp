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
    int n;
    cin >> n;
    vector<int> a(n);
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        sm += a[i];
        a[i] = 0;
        if (sm < 0) {
            cout << "No\n";
            return;
        }
        if (sm == 0)
            break;
    }
    if (sm != 0) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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