#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

bool check(vector<int> a) {
    map<int, int> cnt;
    for (auto i : a) {
        cnt[i]++;
    }
    for (auto i : cnt) {
        if (i.second > (a.size() + 1) / 2) {
            return false;
        }
    }
    return true;
}

int getLen(pair<int, int> a) {
    return a.second - a.first + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    if (!check(a)) {
        cout << "-1\n";
        return;
    }
    
    vector<pair<int, int>> block;
    for (int l = 0; l < n; ++l) {
        int r = l;
        while (r + 1 < n && a[r] != a[r + 1]) ++r;
        block.push_back({l, r});
        l = r;
    }
    map<int, int> cnt;
    for (auto i : block) {
        cnt[a[i.first]]++;
        cnt[a[i.second]]++;
    }
    vector<pair<int, int>> fcnt;
    for (auto i : cnt) {
        fcnt.push_back({i.second, i.first});
    }
    sort(all(fcnt));
    int mxVal = fcnt.back().second;
    int szMx = fcnt.back().first;
    int val = block.size() + 1 - szMx;
    int ans = block.size() - 1;

    for (int i = 0; i + 1 < a.size(); ++i) {
        if (a[i] == a[i + 1]) continue;
        if (a[i] == mxVal || a[i + 1] == mxVal) continue;
        if (val >= 0) break;
        ++ans;
        ++val;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}