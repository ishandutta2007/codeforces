#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, 0);
    vector<int> one(n, 0);
    vector<vector<int>> have(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        have[i].resize(k);
        for (auto& x : have[i]) {
            cin >> x;
            cnt[x - 1]++;
            if (k == 1) {
                one[x - 1]++;
            }
        }
    }
    if (*max_element(all(one)) > (m + 1) / 2) {
        cout << "NO\n";
        return;
    }
    // cout << "puhh" << endl;
    vector<int> ans(m, -1);
    int mx = max_element(all(cnt)) - cnt.begin();
    // cerr << "mx = " << mx << endl;
    int need = (m + 1) / 2;
    for (int i = 0; i < m && need > 0; ++i) {
        if (have[i].size() != 1) continue;
        for (int j = 0; j < (int)have[i].size() && need > 0; ++j) {
            if (have[i][j] != mx + 1) continue;
            --need;
            ans[i] = mx + 1;
            have[i].erase(have[i].begin() + j);
            break;
        }
    }
    // cerr << "puhh" << endl;
    for (int i = 0; i < m && need > 0; ++i) {
        for (int j = 0; j < (int)have[i].size() && need > 0; ++j) {
            if (have[i][j] != mx + 1) continue;
            --need;
            ans[i] = mx + 1;
            have[i].erase(have[i].begin() + j);
            break;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (int)have[i].size(); ++j) {
            if (have[i][j] != mx + 1) continue;
            have[i].erase(have[i].begin() + j);
            break;
        }
    }
    // cerr << "puhh" << endl;
    for (int i = 0; i < m; ++i) {
        if (ans[i] != -1) continue;
        assert(!have[i].empty());
        ans[i] = have[i][0];
    }
    cout << "YES\n";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    // cout.flush();
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}