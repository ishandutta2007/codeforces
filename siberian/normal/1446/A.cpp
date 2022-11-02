#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
    int n;
    ll w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    reverse(all(a));
    vector<int> ans;
    ll now = 0;
    for (auto i : a) {
        if (now + i.first > w) continue;
        now += i.first;
        ans.push_back(i.second);
        if (now * 2 >= w) break;
    }
    if (now * 2 < w) {
        cout << "-1\n";
    } else {
        cout << ans.size() << '\n';
        for (auto i : ans) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}