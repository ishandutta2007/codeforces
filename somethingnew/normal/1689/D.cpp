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
    vector<string> pole(n);
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        cin >> pole[i];
        for (int j = 0; j < m; ++j) {
            if (pole[i][j] == 'B')
                a.emplace_back(i + j, i - j);
        }
    }
    int l = -1, r = 10000000;
    while (l + 1 < r) {
        int m = l + r >> 1;
        array<int, 4> pole = {-(int)1e9, (int)1e9, -(int)1e9, (int)1e9};
        for (auto [x, y] : a) {
            pole[0] = max(pole[0], x - m);
            pole[1] = min(pole[1], x + m);
            pole[2] = max(pole[2], y - m);
            pole[3] = min(pole[3], y + m);
        }
        if (pole[0] <= pole[1] and pole[2] <= pole[3]) {
            r = m;
        } else {
            l = m;
        }
    }
    fakkk:
    array<int, 4> pol = {-(int)1e9, (int)1e9, -(int)1e9, (int)1e9};
    for (auto [x, y] : a) {
        pol[0] = max(pol[0], x - r);
        pol[1] = min(pol[1], x + r);
        pol[2] = max(pol[2], y - r);
        pol[3] = min(pol[3], y + r);
    }
    //cout << pol[0] << ' ' << pol[1] << ' ' << pol[2] << ' ' << pol[3] << ' ' << r << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pol[0] <= i + j and i + j <= pol[1] and pol[2] <= i - j and i - j <= pol[3]) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
    }
    r++;
    goto fakkk;
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