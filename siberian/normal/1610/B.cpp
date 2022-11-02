#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

bool check(vector<int> a, int x) {
    vector<int> have;
    for (auto i : a) {
        if (i != x) {
            have.push_back(i);
        }
    }
    a = have;
    reverse(all(a));
    return a == have;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vin(a);
    int cnt = 0;
    while (cnt < n - 1 - cnt && a[cnt] == a[n - cnt - 1]) {
        ++cnt;
    }
    if (cnt >= n - 1 - cnt) {
        cout << "YES\n";
    } else if (check(a, a[cnt]) || check(a, a[n - cnt - 1])) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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