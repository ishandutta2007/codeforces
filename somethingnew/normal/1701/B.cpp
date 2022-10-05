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
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        nums[i] = 1;
    }
    cout << "2\n";
    for (int i = 1; i <= n; ++i) {
        if (nums[i])
            cout << i << ' ';
        int j = i * 2;
        while (j <= n and nums[j] == 1) {
            cout << j << ' ';
            nums[j] = 0;
            j *= 2;
        }
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