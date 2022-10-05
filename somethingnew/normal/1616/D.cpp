#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#include "deque"
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    for (int i = 0; i < n; ++i) {
        a[i] -= x;
    }
    deque<pair<int, int>> sufmx;
    vector<int> r(n);
    int sm = 0, lsm = 0;
    for (int i = n - 1; i >= 0; --i) {
        lsm = sm;
        sm += a[i];
        int targ = sm+1;
        int p = lower_bound(sufmx.begin(), sufmx.end(), pair<int, int>{targ, 0}) - sufmx.begin();
        if (p == sufmx.size()) {
            r[i] = -1;
        } else {
            r[i] = sufmx[p].second - 1;
        }
        while ((!sufmx.empty()) and sufmx.front().first < lsm) {
            sufmx.pop_front();
        }
        sufmx.push_front({lsm, i + 1});
    }
    int right = n;
    int res = n;
    for (int i = 0; i < n; ++i) {
        if (r[i] != -1) {
            right = min(right, r[i]);
        }
        if (right == i) {
            right = n;
            res--;
        }
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}