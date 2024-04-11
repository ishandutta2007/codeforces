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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> ans;
    int x = sum / n;

    for (int i = 2; i <= n; ++i) {
        int need = (a[i] + i - 1) / i * i - a[i];
        assert(a[1] >= need);
        ans.push_back({1, i, need});
        a[1] -= need;
        a[i] += need;
        assert(a[i] % i == 0);
        ans.push_back({i, 1, a[i] / i});
        a[1] += a[i] / i * i;
        a[i] -= a[i] / i * i;
        assert(a[i] == 0);
    }

    for (int i = 2; i <= n; ++i) {
        ans.push_back({1, i, x});
        a[1] -= x;
        a[i] += x;
    }

    for (int i = 1; i <= n; ++i) {
        assert(a[i] == x); 
    }

    assert(ans.size() <= 3 * n);
    cout << ans.size() << "\n";
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
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