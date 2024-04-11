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
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int rs = 1;
        while (x % m == 0) {
            x /= m;
            rs *= m;
        }
        if (a.empty() or a.back().first != x)
            a.push_back({x, rs});
        else
            a.back().second += rs;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        int rs = 1;
        while (x % m == 0) {
            x /= m;
            rs *= m;
        }
        if (b.empty() or b.back().first != x)
            b.push_back({x, rs});
        else
            b.back().second += rs;
    }
    if (b != a)
        cout << "No\n";
    else
        cout << "Yes\n";
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