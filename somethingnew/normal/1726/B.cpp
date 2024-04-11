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
    if (n > m) {
        cout << "NO\n";
        return;
    }
    if (n % 2 == 1) {
        cout << "YES\n";
        for (int i = 0; i < n - 1; ++i) {
            cout << "1 ";
        }
        cout << m - n + 1 << '\n';
    } else {
        if (m % 2 == 0) {
            cout << "YES\n";
            for (int i = 0; i < n - 2; ++i) {
                cout << "1 ";
            }
            cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';
        } else {
            cout << "No\n";
        }
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