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
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pole(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> pole[i][j];
        }
    }
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; ++i) {
        int ok = 0;
        multiset<int> nums;
        for (int j = 0; j < m; ++j) {
            nums.insert(pole[i][j]);
        }
        for (int j = 0; j < m; ++j) {
            if (pole[i][j] != *nums.begin()) {
                int t = *nums.begin();
                for (int k = j; k < m; ++k) {
                    if (pole[i][k] == t) {
                        p1 = j;
                        p2 = k;
                        ok = 1;
                    }
                }
                break;
            }
            nums.erase(nums.begin());
        }
        if (ok)
            break;
    }
    for (int i = 0; i < n; ++i) {
        swap(pole[i][p1], pole[i][p2]);
        for (int j = 1; j < m; ++j) {
            if (pole[i][j - 1] > pole[i][j]) {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << p1 + 1 << ' ' << p2 + 1 << '\n';
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