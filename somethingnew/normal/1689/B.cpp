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
bool gen(vector<int> &res, int ind, vector<int> &bunned, vector<int> &p) {
    if (ind == res.size()) {
        return 1;
    }
    for (int i = 1; i <= res.size(); ++i) {
        if (!bunned[i] and p[ind] != i) {
            bunned[i] = 1;
            res[ind] = i;
            int vl = gen(res, ind + 1, bunned, p);
            if (vl)
                return 1;
            bunned[i] = 0;
        }
    }
    return 0;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> bunned(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "-1\n";
        return;
    }
    vector<int> res(n);
    gen(res, 0, bunned, a);
    for (auto i : res)
        cout << i << ' ';
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