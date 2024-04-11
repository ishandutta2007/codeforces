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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 0;
    int open = 0;
    int val = 0;
    vector<int> clos(n);
    for (int i = n - 1; i >= 0; --i) {
        val -= open;
        open -= clos[i];
        a[i] -= val;
        int q = min(k, i+1);
        int cn = (max(0ll, a[i]) + q - 1) / q;
        val += cn * q;
        open += cn;
        res += cn;
        if (i-q != -1)
            clos[i-q] += cn;
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}