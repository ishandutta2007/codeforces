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
    int n;
    cin >> n;
    vector<int> b(n);
    vector<array<int, 3>> aseg(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] == 0) {
            aseg[i] = {i + 2, n, i};
            continue;
        }
        int l = 0, r = n + 1;
        int ll, rr;
        while (l + 1 < r) {
            int m = l + r >> 1;
            if ((i + 1) / m <= b[i]) {
                r = m;
            } else {
                l = m;
            }
        }
        ll = r;
        l = 0, r = n + 1;
        while (l + 1 < r) {
            int m = l + r >> 1;
            if ((i + 1) / m >= b[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        rr = l;
        aseg[i] = {ll, rr, i};
    }
    
    sort(all(aseg));
    reverse(all(aseg));
    set<pair<int, int>> aboba;
    vector<int> res(n);
    for (int i = 1; i <= n; ++i) {
        while (!aseg.empty() and aseg.back()[0] == i) {
            aboba.insert({aseg.back()[1],aseg.back()[2]});
            aseg.pop_back();
        }
        pair<int, int> x = *aboba.begin();
        aboba.erase(aboba.begin());
        res[x.second] = i;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
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