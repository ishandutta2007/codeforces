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
    int n, k;
    cin >> n >> k;
    vector<int> a(26);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[c-'a']++;
    }
    string ans;
    for (int i = 0; i < k; ++i) {
        int p = n / k;
        int let = 0;
        for (int j = 0; j < min(25, p); ++j) {
            if (a[j] > 0) {
                a[j]--;
                let++;
            } else {
                break;
            }
        }
        cout << char('a' + let);
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