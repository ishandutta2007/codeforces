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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> b;
    for (int i = 1; i < n; ++i) {
        b[a[i] - a[i - 1]]++;
    }
    map<int, int> c;
    while (1) {
        int last = - 1;
        int nonzero = 0;
        vector<pair<int, int>> k;
        for (auto [i, vl] : b) {
            if (vl == 0)
                continue;
            k.push_back({i, vl});
            if (last != -1) {
                c[i - last]++;
                nonzero++;
            }
            last = i;
            if (vl - 1 != 0)
                c[0] += vl - 1;
        }
        if (k.size() == 1 and k[0].first == 0 ) {
            cout << "0\n";
            return;
        }
        if (((k.size() == 2 and k[0].first == 0) or k.size() == 1) and k.back().second == 1) {
            cout << k.back().first << '\n';
            return;
        }
        swap(b, c);c.clear();
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