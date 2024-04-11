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

#define int ull

int calc(int val, vector<int> a) {
    for (auto& i : a) {
        while (i % 2 == 0) {
            i /= 2;
            val *= 2;
        }
    }
    int ans = val;
    for (auto i : a) {
        ans += i;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vin(a);
    sort(all(a));
    if (a.size() == 1) {
        cout << a[0] << '\n';
    } else {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            auto b = a;
            b.erase(b.begin() + i);
            chkmax(ans, calc(a[i], b));
        }
        cout << ans << '\n';
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