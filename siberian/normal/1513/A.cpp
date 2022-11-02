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
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    if (k == 0) {
        ans.resize(n);
        iota(all(ans), 1);
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    int L = 1, R = n;
    while (L <= R) {
        if (ans.empty() || ans.back() == R + 1) {
            ans.push_back(L);
            ++L;
        } else {
            ans.push_back(R);
            --R;
        }
    }   
    // int fans = 0;
    for (int i = 1; i < n; i += 2) {
        if ((i + 1) / 2 == k && i + 1 < n) {
            sort(ans.begin() + i + 1, ans.end());
            reverse(ans.begin() + i + 1, ans.end());
            for (auto i : ans) {
                cout << i << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "-1" << endl;
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