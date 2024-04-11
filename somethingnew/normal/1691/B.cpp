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
    vector<int> a(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i] = i + 1;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1])
            swap(p[i], p[i - 1]);
    }
    for (int i = 0; i < n; ++i) {
        if (p[i] == i + 1) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
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