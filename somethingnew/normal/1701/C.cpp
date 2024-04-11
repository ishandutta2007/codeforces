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
bool chk(int t, vector<int> wrk, int n) {
    vector<int> rb(n, t);
    int qt = 0;
    for (int i = 0; i < wrk.size(); ++i) {
        if (rb[wrk[i]] == 0)
            qt++;
        else
            rb[wrk[i]]--;
    }
    for (int i = 0; i < n; ++i) {
        qt -= rb[i] / 2;
    }
    //cerr << t << ' ' << (qt <= 0) << '\n';
    return qt <= 0;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> wrk(m);
    for (int i = 0; i < m; ++i) {
        cin >> wrk[i];
        wrk[i]--;
    }
    int l = 0, r = m * 2 + 4;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (chk(m, wrk, n))
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
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