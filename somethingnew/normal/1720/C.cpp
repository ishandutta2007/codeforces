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
    vector<string> table(n);
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }
    int ok = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == '1')
                res++;
            if (i + 1 < n)
                ok = max(ok, ((int)(table[i][j] == '0')) + (table[i + 1][j] == '0'));
            if (j + 1 < m)
                ok = max(ok, ((int)(table[i][j] == '0')) + (table[i][j + 1] == '0'));
            if (i + 1 < n and j + 1 < m)
                ok = max(ok, ((int)(table[i][j] == '0')) + (table[i + 1][j + 1] == '0'));
            if (i - 1 >= 0 and j + 1 < m)
                ok = max(ok, ((int)(table[i][j] == '0')) + (table[i - 1][j + 1] == '0'));

        }
    }
    cout << res - 2 + ok << '\n';
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