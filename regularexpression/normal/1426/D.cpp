#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    vector<pair<int, int> > arr;
    map<int, int> lst;
    for (int i = 0; i <= n; ++i) {
        if (lst.find(pref[i]) != lst.end()) arr.push_back({lst[pref[i]] + 1, i - 1});
        lst[pref[i]] = i;
    }
    sort(arr.begin(), arr.end(), [&](auto x, auto y) {
        return x.second < y.second || (x.second == y.second && x.first < y.second);
    });
    int mx = -1, ans = 0;
    for (auto elem : arr) {
        if (mx < elem.first) {
            ++ans;
            mx = elem.second;
        }
    }
    cout << ans;
    return 0;
}