#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    map<int, int> cnt;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<pair<int, int>> bp(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        bp[i] = {x, y};
    }
    sort(all(bp));
    for (auto [x, cx] : cnt) {
        a[cx].push_back(x);
    }
    vector<int> ex;
    for (int i = 0; i <= n; ++i) {
        if (a[i].size() > 0)
            ex.push_back(i);
        sort(all(a[i]));
        reverse(all(a[i]));
    }
    long long res = 0;
    for (auto [x, cx] : cnt) {
        for (auto j : ex) {
            int t = 0;
            while (t != a[j].size() and x < a[j][t]) {
                auto it = lower_bound(all(bp), make_pair(x, a[j][t]));
                if (it == bp.end() or (*it) != make_pair(x, a[j][t])) {
                    res = max(res, ((long long)x + a[j][t]) * ((long long)j + cx));
                    break;
                }
                t++;
            }
        }
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}