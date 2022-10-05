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
    vector<pair<int, int>> segs(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].first >> segs[i].second;
        cin >> c[i];
    }
    int ls = 0, rs = 0, all = 0;
    for (int i = 0; i < n; ++i) {
        if (segs[i].first < segs[ls].first)
            ls = i;
        if (segs[i].first == segs[ls].first and c[i] < c[ls])
            ls = i;
        if (segs[i].second > segs[rs].second)
            rs = i;
        if (segs[i].second == segs[rs].second and c[i] < c[rs])
            rs = i;
        if (all != -1 and (segs[all].first != segs[ls].first or segs[all].second != segs[rs].second))
            all = -1;
        if (segs[i].first == segs[ls].first and segs[i].second == segs[rs].second) {
            if (all == -1)
                all = i;
            if (c[all] > c[i])
                all = i;
        }
        int ans1 = c[ls] + c[rs];
        if (all != -1) {
            cout << min(c[all], ans1) << '\n';
        } else {
            cout << ans1 << '\n';
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}