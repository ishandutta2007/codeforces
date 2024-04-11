#include "bits/stdc++.h"

#define int long long

using namespace std;

int ans(int l, int r, int h, const vector<int> & a) {
    if (l >= r) {
        return 0;
    }
    int min_h = a[l];
    for(int i = l; i < r; i ++) {
        min_h = min(min_h, a[i]);
    }
    int res = min_h - h;
    int cur = l;
    for(int i = l; i < r; i ++) {
        if (a[i] == min_h) {
            res += ans(cur, i, min_h, a);
            cur = i + 1;
        }
    }
    res += ans(cur, r, min_h, a);
    return min(r - l, res);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> in(n);
    for(int i = 0; i < n; i ++) {
        cin >> in[i];
    }
    cout << ans(0, n, 0, in) << endl;
}