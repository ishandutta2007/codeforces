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
    int n, m;
    cin >> n >> m;
    vector<int> sms(n);
    vector<vector<int>> tables(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = 0; j < m; ++j) {
            cin >> tables[i][j];
            x += tables[i][j] * j;
        }
        sms[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        if (sms[i] != sms[(i + 1) % n] and sms[i] != sms[(i - 1 + n) % n]) {
            cout << i + 1 << ' ';
            cout << sms[i] - sms[(i + 1) % n] << '\n';
            return;
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