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
    int n, x;
    cin >> n >> x;
    vector<int> cnt(x + 1, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i = 0; i < x; ++i) {
        cnt[i + 1] += cnt[i] / (i + 1);
        cnt[i] %= i + 1;
        if (cnt[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}