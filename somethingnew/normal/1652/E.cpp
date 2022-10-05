#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "set"
#include "array"
#include "map"
#define all(x) x.begin(), x.end()
using namespace std;
int mxvh(vector<int> &a) {
    if (a.empty())
        return 0;
    sort(all(a));
    int cnt = 1, mxcnt = 1;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1])
            cnt++;
        else
            cnt = 1;
        mxcnt = max(mxcnt, cnt);
    }
    return mxcnt;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 1;
    vector<int> ex;
    for (int i = -600; i <= 600; ++i) {
        vector<int> cn(n);
        for (int j = 0; j < n; ++j) {
            cn[j] = a[j] + i * j;
        }
        int mx = mxvh(cn);
        res = max(res, mx);
    }
    for (int i = 0; i < n; ++i) {
        vector<int> cn;
        for (int j = max(0, i - 300); j < min(n, i + 300); ++j) {
            if (i == j)
                continue;
            if ((a[j] - a[i]) % (j - i) == 0)
                cn.push_back((a[j] - a[i]) / (j - i));
        }
        int mx = mxvh(cn) + 1;
        res = max(res, mx);
    }
    cout << n - res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}