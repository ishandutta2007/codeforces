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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 1e18;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        int lst = 0;
        for (int j = i + 1; j < n; ++j) {
            int vl = (lst + a[j]) / a[j];
            lst = vl * a[j];
            cnt += vl;
            //cout << vl << '\n';
        }
        lst = 0;
        for (int j = i - 1; j >= 0; --j) {
            int vl = (lst + a[j]) / a[j];
            lst = vl * a[j];
            cnt += vl;
        }
        res = min(res, cnt);
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