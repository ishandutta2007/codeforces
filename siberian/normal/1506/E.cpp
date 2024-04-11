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

int n;

void solveMin(vector<int> a) {
    vector<int> ans;
    set<int> have;
    for (int i = 1; i <= n; ++i) {
        have.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            assert(have.count(a[i]));
            have.erase(a[i]);
            ans.push_back(a[i]);   
        } else {
            auto it = *have.begin();
            ans.push_back(it);
            have.erase(it);
        }
        // cout << ans.back() << endl;
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << '\n';
}

void solveMax(vector<int> a) {
    vector<int> ans;
    set<int> have;
    for (int i = 1; i <= n; ++i) {
        have.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            assert(have.count(a[i]));
            have.erase(a[i]);
            ans.push_back(a[i]);   
        } else {
            auto it = have.upper_bound(a[i]);
            assert(it != have.begin());
            --it;
            ans.push_back(*it);
            have.erase(it);
        }
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << '\n';
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    solveMin(a);
    // cout.flush();
    solveMax(a);
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