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

#define int ll

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> have(n);
    vector<int> u(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sum += s[i];
        have[u[i] - 1].push_back(s[i]);
    }
    sort(all(have), [&] (const vector<int>& a, const vector<int>& b) {
        return a.size() > b.size();
    });
    // cerr << "have = " << endl;
    // for (auto i : have) {
    //     for (auto j : i) {
    //         cerr << j << ' ';
    //     }
    //     cerr << endl;
    // }
    for (int i = 0; i < n; ++i) {
        sort(all(have[i]));
        for (int j = 1; j < have[i].size(); ++j) {
            have[i][j] += have[i][j - 1];
        }
    }
    vector<int> ans(n);

    for (int k = 1; k <= n; ++k) {
        ans[k - 1] = 0;
        for (int i = 0; i < n && have[i].size() >= k; ++i) {
            ans[k - 1] += have[i].back();
            int cnt = have[i].size() % k;
            if (cnt > 0) {
                ans[k - 1] -= have[i][cnt - 1];
            }
        }
    }

    for (auto i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
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