#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<vector<int>> fans(2, vector<int>(0, 0));

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        fans[x].push_back(a[i]);
    }



    // cerr << "fans = " << endl;
    // for (auto i : fans) {
    //     for (auto j : i) {
    //         cerr << j << " ";
    //     }
    //     cerr << endl;
    // }


    for (int it = 0; it < 2; ++it) {
        sort(all(fans[it]));
        fans[it].push_back(0);
        reverse(all(fans[it]));
        for (int i = 1; i < fans[it].size(); ++i) {
            fans[it][i] += fans[it][i - 1];
        }
    }

    // cerr << "fans = " << endl;
    // for (auto i : fans) {
    //     for (auto j : i) {
    //         cerr << j << " ";
    //     }
    //     cerr << endl;
    // }

    int ans = INT_MAX;
    for (int i = 0; i < fans[0].size(); ++i) {
        int need = m - fans[0][i];
        int pos = lower_bound(all(fans[1]), need) - fans[1].begin();
        if (pos == fans[1].size()) continue;
        // cerr << i << " " << pos << endl; 
        chkmin(ans, i + pos * 2);
    }
    if (ans == INT_MAX) ans = -1;
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