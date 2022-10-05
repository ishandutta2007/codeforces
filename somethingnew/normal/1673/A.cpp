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
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res += s[i] - 'a' + 1;
    }
    if (s.size() % 2 == 1) {
        res -= (min(s[0], s.back()) - 'a' + 1) * 2;
    }
    if (res > 0) {
        cout << "Alice " << res << '\n';
    } else {
        cout << "Bob " << -res << '\n';
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