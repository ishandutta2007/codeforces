#include "list"
#include <iostream>
#include "queue"
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto & i : a) {
        cin >> i;
    }
    sort(all(a));
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int binl = -1, binr = i;
        while (binr - binl > 1) {
            int binm = binl + binr >> 1;
            if (a[binm] + a[i] >= l) {
                binr = binm;
            } else {
                binl = binm;
            }
        }
        int rr = binr;
        binl = -1, binr = i;
        while (binr - binl > 1) {
            int binm = binl + binr >> 1;
            if (a[binm] + a[i] <= r) {
                binl = binm;
            } else {
                binr = binm;
            }
        }
        int ll = binl;
        //cout << ll << ' ' << rr;
        res += max(0ll, ll - rr + 1);
    }
    cout << res << '\n';
}
signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}