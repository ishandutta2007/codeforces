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
    int k;
    cin >> k;
    string s;
    cin >> s;
    if (k and s.back() == '0') {
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] == '1' and (s.size() - 1 - i) <= k) {
                k -= (s.size() - 1 - i);
                swap(s[i], s.back());
                break;
            }
        }
    }
    if (k and s[0] == '0') {
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == '1' and i <= k) {
                swap(s[i], s[0]);
            }
        }
    }
    int res = (s[0] == '1') * 10 + (s.back() == '1');
    for (int i = 1; i < n-1; ++i) {
        res += (s[i] == '1') * 11;
    }
    cout << res << '\n';
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