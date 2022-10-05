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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    while (!b.empty() and a.back() == b.back()) {
        a.pop_back();
        b.pop_back();
    }
    if (b.size() >= 2) {
        cout << "No\n";
        return;
    }
    if (b.size() == 0) {
        cout << "Yes\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (b[0] == a[i]) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
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